#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"

using sf::RenderWindow;
using sf::Vector2f;

RenderWindow* win;

int main(){
    win = new RenderWindow(sf::VideoMode({1280, 720}), "REN WIN TES", sf::Style::None, sf::State::Windowed);
    win->setPosition({0, 0});
    win->setFramerateLimit(60);

    Game game{ win };
    game.Run();

    return 1;
}
