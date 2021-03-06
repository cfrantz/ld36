#include "map.h"

#include <stdlib.h>

#define STB_PERLIN_IMPLEMENTATION 1
#include "stb_perlin.h"

Map::Map() {
  for (int x = 0; x < 640; ++x) {
    heights_[x] = 0;
  }
}

void Map::generate_terrain() {
  const float y = rand() / static_cast<float>(RAND_MAX);

  for (int x = 0; x < 640; ++x) {
    heights_[x] = 250;
    for (int i = 0; i < 5; ++i) {
      heights_[x] += (4 << i) * stb_perlin_noise3(x / (float)(16 << i), y, 0);
    }
  }
}

void Map::draw(Graphics& graphics) const {
  for (int x = 0; x < 640; ++x) {
    graphics.draw_line(x, 0, x, heights_[x], 0x31a2f2ff);
    graphics.draw_pixel(x, heights_[x], 0x44891aff);
    graphics.draw_line(x, heights_[x] + 1, x, 360, 0xa46422ff);
  }
}

void Map::impact(int x) {
  heights_[x - 3] += 1;
  heights_[x - 2] += 2;
  heights_[x - 1] += 3;
  heights_[x + 0] += 3;
  heights_[x + 1] += 3;
  heights_[x + 2] += 2;
  heights_[x + 3] += 1;
}
