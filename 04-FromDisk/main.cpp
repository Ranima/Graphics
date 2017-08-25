
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"


int main()
{
	Context context;
	context.init(800, 600);

	Vertex vquads[4] = { 
		{ { -1, -1, 0,1 } },
		{ {  1, -1, 0,1 } },
		{ {  1,  1, 0,1 } },
		{ { -1,  1, 0,1 } } };

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
		" outColor = textture(map, vUV.xy); \n"
		"}\n";

	Shader sq = makeShader(vsource, fsource);

	Framebuffer f = { 0, 800, 600 };

	while (context.step())
	{
		s0_draw(f, sq, quad);
	}

	context.term();
	return 0;
}