#include "Map.hpp"
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<uint8_t> map;
vector<int> active;

void Map::Test(){
    for(int i = 0; i < active.size(); i++){
        map[active[i]] = 127;
    }

    cout << active.size() << endl;

    for(int i = 0; i < COLS * ROWS; i++){
        cout << (int)map[i] << "    ";

        if(i % COLS == 0)
            cout << endl;
    }
}

void Map::Load(){
    for(int i = 0; i < COLS * ROWS; i++){
        uint8_t cell = (uint8_t)(layout.getPixel(sf::Vector2u(i % COLS, i / COLS)).a);
        map.push_back(cell);
        if(cell != 0)
            active.push_back(i);
    } 

    Test();
}

void Map::Draw(sf::RenderWindow* target){
    sf::Texture crop("../resources/Atlas.png", false, sf::IntRect({displacement, 0}, {16, 16}));
    sf::Sprite sprite(crop);
    target->draw(sprite);
}

Map::Map(const char* atlasPath){
    layout = sf::Image(atlasPath);
    atlas = sf::Texture(atlasPath);
    COLS = layout.getSize().x;
    ROWS = layout.getSize().y;
    TILESIZE = 16;
    std::cout << "Map dimentions: " << COLS << ", " << ROWS << "\n" << std::endl;

    Load();
}
