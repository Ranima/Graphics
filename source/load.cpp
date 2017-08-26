
#include "Graphics\load.h"
#include "Graphics\RenderObjects.h"
#include "iostream"
#include "fstream"
#include "Graphics\Vertex.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb\stb_image.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

using namespace std;

Geometry loadGeometry(const char *path)
{
	Geometry retval = { 0,0,0,0 };

	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;
	tinyobj::LoadObj(&attrib, &shapes, &materials, &err, path);

	size_t isize = shapes[0].mesh.indices.size();
	size_t *indices = new unsigned[isize];

	size_t vsize = isize;
	Vertex *verts = new Vertex[vsize];

	for (int i = 0; i < isize; ++i)
	{
		indices[i] = i;

		int pi = shapes[0].mesh.indices[i].vertex_index;
		int ni = shapes[0].mesh.indices[i].normal_index;
		int ti = shapes[0].mesh.indices[i].texcoord_index;

		const float *p = &attrib.vertices[pi * 3];
		const float *n = &attrib.normals[ni * 3];
		const float *t = &attrib.texcoords[ti * 2];

		verts[i].position = { p[0],p[1],p[2],1 };
		verts[i].texcoord = { t[0],t[1] };
		verts[i].normal   = { n[0],n[1],n[2],0 };
	}

	retval = makeGeometry(verts, vsize, indices, isize);

	delete[] verts;
	delete[] indices;
	return retval;
}

Texture loadTexture(const char *path)
{
	Texture retval = { 0 };
	stbi_set_flip_vertically_on_load(true);
	int w, h, c;
	unsigned char *pixels;
	pixels = stbi_load(path, &w, &h, &c, STBI_default);
	retval = makeTexture(w, h, c, pixels);
	stbi_image_free(pixels);
	return retval;
}


Shader loadShader(const char *vert_path, const char *frag_path)
{
	Shader retval = { 0 };


	ifstream v(vert_path);
	std::string verts((std::istreambuf_iterator<char>(v)),
					  (std::istreambuf_iterator<char>()));
	
	ifstream f(frag_path);
	std::string frags((std::istreambuf_iterator<char>(f)),
					  (std::istreambuf_iterator<char>()));

	/**********
		Load all of the text from the file provided by the path
		and pass it into make shader.
		Google: "File to C-String in C++"
	**********/


	const char *vsource = verts.c_str();
	const char *fsource = frags.c_str();

	retval = makeShader(vsource,fsource);
	return retval;
}