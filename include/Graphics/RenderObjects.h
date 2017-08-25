#pragma once

#include "glm\glm\glm.hpp"
struct Vertex;

struct Geometry
{
	unsigned	handle,
				vbo,
				ibo,
				size;
};


Geometry makeGeometry(const Vertex *verts, size_t vsize,
					  const unsigned *idxs, size_t isize);

void freeGeometry(Geometry &g);


struct Shader
{
	unsigned handle;
};

Shader makeShader(const char *vert_src, const char *frag_src);
void freeShader(Shader &);

struct Framebuffer
{
	unsigned handle, width, height;
};

struct Texture
{
	unsigned handle;
};

Texture makeTexture(unsigned w, unsigned h, unsigned c, const unsigned char *pixels)
{
	Texture retval = { 0 };

	unsigned f = 0;
	switch (c)
	{
	case 1: f = GL_RED; break;
	case 2: f = GL_RG;	break;
	case 3: f = GL_RGB; break;
	case 4: f = GL_RGBA; break;
	}

	glGenTextures(1, &retval.handle);
	glBindTexture(GL_TEXTURE_2D, retval.handle);

	glTexImage2D(GL_TEXTURE_2D, 0, f, w, h, 0, f, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	return retval;
};

void freeTexture(Texture &t)
{
	glDeleteTextures(1, &t.handle);
	t = { 0 };
};