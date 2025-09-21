#include <iostream>

#include "DrawWindow.hpp"
#include "FileUtil.hpp"
#include "XML.hpp"

using namespace std;

int main(){
    cout << "battlenet - remake by erickWasTaken" << endl;
    DrawWindow win;
    win.Initialize("", DrawWindow::WindowMode::windowed);

    string path("../resources/maps/homepage.tmx");
    string attrib("nextlayerid");

    XMLElement map = parseXML(FileUtil::Read(path));

    string out = map.GetAttribute(attrib);

    cout << 
        "::READING FILE:: \n" << 
         out << 
    endl;

    while(win.isOpen()){
        win.clear();
        win.display();
    }
    return 0;
}
