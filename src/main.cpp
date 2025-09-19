#include <iostream>

#include "DrawWindow.hpp"

using namespace std;

int main(){
    cout << "battlenet - remake by erickWasTaken" << endl;
    DrawWindow win;
    win.Initialize("", DrawWindow::WindowMode::fullscreen);

    while(win.isOpen()){
        win.clear();
        win.display();
    }
    return 0;
}
