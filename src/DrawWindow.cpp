#include "DrawWindow.hpp"

DrawWindow::DrawWindow(){}
DrawWindow::~DrawWindow(){delete win;}

void DrawWindow::Initialize(const string& title, WindowMode mode){
    // this->title = title; 
    original = View(Vector2f(0, 0), Vector2f(480, 320)); // probably location and res
    
    if (win) delete win;
    win = nullptr;

    auto videoMode = VideoMode(Vector2u(480, 320));

    auto style = State::Windowed;
    style = mode == WindowMode::fullscreen ? State::Fullscreen : State::Windowed;

    win = new RenderWindow(videoMode, "konkai ha yurushite _(_ _)_", style);
    win->setFramerateLimit(FPS_LIMIT); 
}
