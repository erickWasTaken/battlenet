#pragma once
#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Game{
private:
    sf::RenderWindow* win = nullptr;
    Map* map = nullptr;

public:
    Game(sf::RenderWindow* window);
    ~Game();

    void Run();
};
