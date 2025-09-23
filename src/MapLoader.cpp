#include "MapLoader.hpp"
#include "Map.hpp"
#include <optional>
#include "Util.hpp"
#include "XML.hpp"

using namespace std;
using namespace Overworld;

namespace Overworld{
    optional<Map> LoadTiledMap(const string& path){
        XMLElement maptree = parseXML(FileUtil::Read(path));
        if(maptree.name != "map")
            return {};

        auto tileWidth_str = StringUtil::to_int(maptree.GetAttribute("tilewidth"));

        return {};
    }
}
