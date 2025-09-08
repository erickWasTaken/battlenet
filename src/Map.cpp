#include "Map.hpp"
#include <iostream>
#include <SFML/System/Vector2.hpp>

Map::Map(const char* atlasPath){
    layout = sf::Image(atlasPath);
    atlas = sf::Texture(atlasPath);
    COLS = layout.getSize().x;
    ROWS = layout.getSize().y;
    std::cout << "Map dimentions: " << COLS << ", " << ROWS << "\n" << std::endl;

    Draw();
}

void Map::Draw(){
    for(int i = 0; i < COLS; i++){
        for(int j = 0; j < ROWS; j++){
            bool on = layout.getPixel(sf::Vector2u(i, j)).a != 0;
            char cell = on ? '#' : ' ';
            std::cout << cell << "  ";
        }
        std::cout << std::endl;
    } 
}
