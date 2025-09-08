#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Map{
private:
    unsigned int COLS;
    unsigned int ROWS;
    sf::Image layout;
    sf::Texture atlas;
public:
    Map(const char* atlasPath);    
    void Draw();
    ~Map();
};
