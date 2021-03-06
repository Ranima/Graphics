#pragma once


struct Geometry;
struct Shader;
struct Framebuffer;
struct Texture;
enum RenderFlag {DEPTH = 1};


void s0_draw(const Framebuffer &f, const Shader &s, const Geometry &g);

//void clearFramebuffer(const Framebuffer &f);
void clearFramebuffer(const Framebuffer &r, bool color = true, bool depth = true);

void setUniform(const Shader&s, int location, float value);
void setUniform(const Shader&s, int location, int value);
void setUniform(const Shader&s, int location, double value);

void setUniform(const Shader&s, int location, const Texture &value, unsigned slot);
void setUniform(const Shader&s, int location, int slot, )

void setFlags(int flags);
