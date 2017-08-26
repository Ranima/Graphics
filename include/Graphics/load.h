#pragma once
//Graphics\include\graphics\load.h
#include "RenderObjects.h"

//declare your RO structs or just include

Texture loadTexture(const char *path);

Shader loadShader(const char *vert_path, const char *frag_path);

Geometry loadGeometry(const char *path);