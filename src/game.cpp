#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game(RenderWindow* window){
    win = window; 
    map = new Map("../resources/maps/home.png");
}

void Game::Run(){
    sf::Clock clock;

    while(win->isOpen()){
        clock.restart();
        while(const std::optional event = win->pollEvent()){
            win->clear();

            if(event->is<sf::Event::Closed>())
                win->close();
        }
        win->display();
    }
}

Game::~Game(){
    // printf("See you next time =)\n");
}
