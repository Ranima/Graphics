
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"

int main()
{
	Context context;
	context.init(800, 600);

	Vertex verts[3] = { {{-.5f,-.5f,0,1}},
					   {{.5f,-.5f,0,1}},
					   {{0,.5f,0,1}} };

	unsigned idxs[3] = { 0,1,2 };

	Geometry g = makeGeometry(verts, 3, idxs, 3);

	const char* vsource =
		"#version 450\n"
		"layout(location = 0) in vec4 position;\n"
		"void main () { gl_Position = position; }\n";

	const char* fsource =
		"#version 450\n"
		"out vec4 outColor;\n"
		"void main () { outColor = vec4(0.5, 0.5, 0.0, 1.0); }\n";

	Shader s = makeShader(vsource, fsource);

	Framebuffer f = { 0, 800, 600 };

	while (context.step())
	{
		s0_draw(f, s, g);
	}

	context.term();
	return 0;
}