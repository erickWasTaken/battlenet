#include <stdio.h>
#include <vector>
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

using sf::RenderWindow;
using sf::Vector2f;
using std::vector;
using std::cout;
using std::endl;

#define WHEIGHT 720
#define WWIDTH 1280
#define TILESIZE 16

RenderWindow* win;

sf::Vector2u SIZE;
vector<uint8_t> map;

int main(){
    win = new RenderWindow(sf::VideoMode({WWIDTH, WHEIGHT}), "REN WIN TES", sf::Style::None, sf::State::Windowed);
    win->setPosition({0, 0});
    win->setFramerateLimit(60);

    // LOADING MAP
    sf::Image layout("./resources/map.png");
    SIZE = layout.getSize();

    for(unsigned int i = 0, k = 0; i < SIZE.x; i++){
        for(unsigned int j = 0; j < SIZE.y; j++, k++){
            map.emplace_back(layout.getPixel(sf::Vector2u({i, j})).a);
            char cell = layout.getPixel(sf::Vector2u({i, j})).a != 0 ? '#' : ' ';
            cout << cell << "   ";
        }
        cout << endl;
    }

    while(win->isOpen()){
        while(const std::optional event = win->pollEvent()){
            if(event->is<sf::Event::Closed>())
                win->close();
        }

        win->clear();
        
        // RENDERING MAP
        for(int i = 0; i < map.size(); i++){
            int offset = map[i] != 0 ? 0 : TILESIZE;

            sf::IntRect rect(sf::Vector2i{0, offset}, sf::Vector2i{TILESIZE, TILESIZE});
            sf::Texture surf = sf::Texture();
            surf.loadFromFile("./resources/tilemap.png", false, rect);
            
            sf::Sprite sprite(surf);

            float xCoord = i % SIZE.x * TILESIZE;
            float yCoord = (i / SIZE.x) * TILESIZE;
            sprite.setPosition({xCoord, yCoord});

            win->draw(sprite);
        }
        
        win->display();
    }
    return 1;
}
