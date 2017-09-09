
#include "Graphics\Context.h"
#include "Graphics\RenderObjects.h"
#include "Graphics\Vertex.h"
#include "Graphics\Draw.h"
#include "Graphics\load.h"
#include "glm\glm\ext.hpp"


void main()
{
	Context context;
	context.init();

	Geometry spear = loadGeometry("../../resources/models/soulspear.obj");
	Shader mvplite = loadShader("../../resources/shaders/mvplite.vert", "../../resources/shaders/mvplite.frag");

	Texture tex = loadTexture("../../resources/textures/soulspear_diffuse.tga");

	Framebuffer f = { 0, 800, 600 };

	glm::mat4 cam_proj = glm::perspective(45.f, 800.f / 600.f, .01f, 10.f);
	glm::mat4 cam_view = glm::lookAt(glm::vec3(0, 2, 5), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

	while (context.step())
	{
		float time = context.getTime();
		glm::mat4 model = glm::rotate(time, glm::vec3(0, 1, 0));

		setFlags(RenderFlag::DEPTH);
		clearFramebuffer(f);

		int loc = 0, slot = 0;
		setUniform(mvplite, loc, slot,cam_proj, cam_view, model, tex);
		s0_draw(f, mvplite, spear);
	}

	context.term();
}