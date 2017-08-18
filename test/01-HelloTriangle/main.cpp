
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"


int main()
{
	Context context;
	context.init(800, 600);

	Vertex verts[4] = {{{.0f,.0f,0,1}},
					   {{.5f,-.5f,0,1}},
					   {{.25f,.5f,0,1}},
					   {{.5f,.5f,0,1}} };

	unsigned idxs[6] = { 0,1,2,3,2,1 };

	Geometry g = makeGeometry(verts, 4, idxs, 6);

	const char* vsource =
		"#version 450\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 color\n"
		"out vec4 vPos;\n"
		"void main () {vPos = position;\n"
		"gl_Position = position; }\n";

	const char* fsource =
		"#version 450\n"
		"in vec4 vPos;\n"
		"out vec4 outColor;\n"
		"void main () \n"
		"{\n"
			" outColor = 0.5 - vPos; \n"
		"}\n";

	Shader s = makeShader(vsource, fsource);

	Framebuffer f = { 0, 800, 600 };

	while (context.step())
	{
		s0_draw(f, s, g);
	}

	context.term();
	return 0;
}