#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow* window){
    win = window; 
    map = new Map("../resources/maps/home.png");
}

void Game::Run(){
    sf::Clock clock;

    while(win->isOpen()){
        clock.restart();
        while(const std::optional event = win->pollEvent()){
            win->clear();

            map->Draw(win);

            if(event->is<sf::Event::Closed>())
                win->close();
        }
        win->display();
    }
}

Game::~Game(){
    // printf("See you next time =)\n");
}
