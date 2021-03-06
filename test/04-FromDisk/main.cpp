
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"
#include "Graphics\load.h"


int main()
{
	Context context;
	context.init(800, 600);

	Vertex vquads[] = { 
		{ { -1, -1, 0,1 }, {}, {0,0} },
		{ {  1, -1, 0,1 }, {}, {1,0} },
		{ {  1,  1, 0,1 }, {}, {1,1} },
		{ { -1,  1, 0,1 }, {}, {0,1} } };

	unsigned quadidx[] = { 0,1,3, 1,2,3 };

	Geometry quad = makeGeometry(vquads, 4, quadidx, 6);

	const char* vsource =
		"#version 450\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 2) in vec2 texCoord;\n"
		"out vec2 vUV;\n"
		"void main () {gl_Position = position;\n"
		"vUV = texCoord; }\n";

	const char* fsource =
		"#version 450\n"
		"out vec4 outColor;\n"
		"in vec2 vUV;\n"
		"layout(location = 0) uniform sampler2D map;\n"
		"void main () \n"
		"{\n"
		" outColor = texture(map, vUV.xy); \n"
		"}\n";

	Shader sq = makeShader(vsource, fsource);

	Geometry cube = loadGeometry("../../resources/models/cube.obj");

	Texture tex = loadTexture("../../resources/textures/soulspear_diffuse.tga");

	Shader sfile = loadShader("../../resources/shaders/test.vert",
							"../../resources/shaders/test.frag");

	Framebuffer f = { 0, 800, 600 };

	while (context.step())
	{
		setUniform(sfile, 0, tex, 0);
		s0_draw(f, sfile, cube);
	}

	context.term();
	return 0;
}