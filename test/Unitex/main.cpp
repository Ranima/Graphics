
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"


int main()
{
	Context context;
	context.init(800, 600);

	Vertex verts[4] = { { { .0f,.0f,0,1 } },
	{ { .5f,-.5f,0,1 } },
	{ { .25f,.5f,0,1 } },
	{ { .5f,.5f,0,1 } } };

	unsigned idxs[6] = { 0,1,2,3,2,1 };

	Geometry g = makeGeometry(verts, 4, idxs, 6);

	const char* vsource =
		"#version 450\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 color\n"
		"layout(location = 0) uniform float time;\n"
		"out vec4 vPos;\n"
		"void main ()\n" 
		"{\n"
		"gl_Position = position;\n"
		"gl_Position.x += sin(time+position.x)/5.0;\n"
		"}\n";

	const char* fsource =
		"#version 450\n"
		"out vec4 outColor;\n"
		"layout(location = 0) uniform float time;\n"
		"layout(location = 1) uniform int tog;\n"
		"in vec4 color;\n"
		"void main () \n"
		"{\n"
		"if(tog == 1)\n"
		"outColor = 1.0 - vPos; \n"
		"else outColor = vColor;\n"
		"outColor.r = 0.5+sin(time+gl_FragCoord.x/10)/2.0;\n"
		"}\n";

	Shader s = makeShader(vsource, fsource);

	Framebuffer f = { 0, 800, 600 };

	while (context.step())
	{
		clearFramebuffer(f);
		setUniform(s, 0, context.getTime());
		s0_draw(f, s, g);


	}
	freeGeometry(g);
	freeShader(s);

	context.term();
	return 0;
}