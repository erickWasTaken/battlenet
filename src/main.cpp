#include <iostream>

#include "DrawWindow.hpp"
#include "Util.hpp"
#include "XML.hpp"
#include "MapLoader.hpp"

using namespace std;

int main(){
    cout << "battlenet - remake by erickWasTaken" << endl;
    DrawWindow win;
    win.Initialize("", DrawWindow::WindowMode::windowed);

    // string path("../resources/maps/homepage.tmx");
    // auto map = Overworld::LoadTiledMap(path);
    cout << StringUtil::to_int("0847295") << endl;

    while(win.isOpen()){
        win.clear();
        win.display();
    }
    return 0;
}
