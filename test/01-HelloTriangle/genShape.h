#pragma once

struct Geometry;

Geometry makeNGon(size_t sides, float radius);

Geometry makeCheckerboard(int rows, int cols, float width, float hight);
