#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2i;

struct Sprite{
    int atlas_id;
    Vector2i offset;

    Vector2i word_pos;
};

class Map{
private:
    unsigned int COLS;
    unsigned int ROWS;
    unsigned int TILESIZE;
    const char* tilemap;

    sf::Image layout;
    sf::Texture atlas;
public:
    Map(const char* atlasPath);    
    void Draw(sf::RenderTexture target);
    void Load();
    void Test();
    ~Map();
};
