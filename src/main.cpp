#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using sf::Window;
using sf::Vector2f;

Window win;

int main(){
    win.create(sf::VideoMode({1280, 720}), "WIN TEST", sf::Style::None, sf::State::Windowed);

    while(win.isOpen()){
        win.display();
        while(const std::optional event = win.pollEvent()){
            if(event->is<sf::Event::Closed>())
                win.close();
        }
    }

    return 1;
}
