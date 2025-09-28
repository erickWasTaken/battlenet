#pragma once
#define FPS_LIMIT 60

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class DrawWindow{
public:
    enum WindowMode : int{
        windowed,
        fullscreen
    };

    DrawWindow();
    ~DrawWindow();
    bool isOpen(){return win->isOpen();}

    // Test purpose -- IMPLEMENT AFTERWARDS
    void clear(){return win->clear();}
    void draw(const Sprite draw){return win->draw(draw);}
    void display(){return win->display();}

    void Initialize(const string& title, WindowMode mode);
private:
    const string title;
    View original;
    RenderStates state; // Global OpenGL context info
    
    RenderWindow* win{nullptr}; // window to draw to
    RenderTexture* surf{nullptr}; // external texture to draw to 
};
