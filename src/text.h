#pragma once

#include <string>

#include "graphics.h"

class Text {
  public:

    enum Alignment { LEFT, CENTER, RIGHT };

    Text(const std::string& file, int width = 8);

    void draw(Graphics& graphics, const std::string& text, int x, int y, Alignment alignment=LEFT) const;

  private:

    std::string file_;
    int width_;
};

