#pragma once

#include <optional>
#include "Map.hpp"
using namespace std;

namespace Overworld{
    optional<Map> LoadTiledMap(const string& data);    
}
