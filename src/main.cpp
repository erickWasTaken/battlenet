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

    string path("../resources/ow/maps/homepage.tmx");
    auto map = Overworld::LoadTiledMap(path);
    Vector2i dimensions = map->GetTileDimensions();
    cout << "tile_width: " << dimensions.x << ", tile_height: " << dimensions.y << endl;

    while(win.isOpen()){
        win.clear();
        map->Draw(&win);
        win.display();
    }
    return 0;
}
