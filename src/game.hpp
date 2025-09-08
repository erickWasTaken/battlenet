#pragma once
#include <SFML/Graphics.hpp>
#include "Map.hpp"

using sf::RenderWindow;

class Game{
private:
    RenderWindow* win = nullptr;
    Map* map = nullptr;

public:
    Game(RenderWindow* window);
    ~Game();

    void Run();
};
