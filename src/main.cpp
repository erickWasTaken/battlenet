#include <iostream>

#include "DrawWindow.hpp"
#include "FileUtil.hpp"

using namespace std;

int main(){
    cout << "battlenet - remake by erickWasTaken" << endl;
    DrawWindow win;
    win.Initialize("", DrawWindow::WindowMode::windowed);

    string path("filetest.txt");
    cout << "::READING FILE:: \n" << FileUtil::Read(path) << endl;

    while(win.isOpen()){
        win.clear();
        win.display();
    }
    return 0;
}
