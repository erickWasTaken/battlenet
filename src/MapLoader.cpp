#include "MapLoader.hpp"
#include "Map.hpp"
#include <optional>
#include "Util.hpp"
#include "XML.hpp"

using namespace std;
using namespace Overworld;

namespace Overworld{
    optional<Map> LoadTiledMap(const string& path){
        // tile info

        XMLElement maptree = parseXML(FileUtil::Read(path));
        if(maptree.name != "map"){
            cout << "received name: " << maptree.name << endl;
            return {};
        }

        auto tileWidth = StringUtil::to_int(maptree.GetAttribute("tilewidth"));
        auto tileHeight = StringUtil::to_int(maptree.GetAttribute("tileheight"));

        auto map = Map(
            StringUtil::to_int(maptree.GetAttribute("width")),
            StringUtil::to_int(maptree.GetAttribute("height")),
            tileWidth,
            tileHeight
        );

        vector<XMLElement> tilesets;
        for(auto& child : maptree.children){
            if(child.name != "tileset")
                continue;
        
            tilesets.emplace_back(child);
        }

        unsigned int id;
        Vector2f draw_offset;
        string texture_path;
        vector<XMLElement>tileElements;
        for(auto& tileset : tilesets){
            auto tilesetElement = parseXML(tileset.GetAttribute("source"));

            for(auto& child : tilesetElement.children){
                if(child.name == "tile"){
                    id = static_cast<unsigned int>(StringUtil::to_int(child.GetAttribute("id")));
                    tileElements.emplace_back(child); 
                }
                else if(child.name == "image"){
                    texture_path = child.GetAttribute("source"); 
                }else if(child.name == "tileoffset"){
                    draw_offset = {
                        (float)StringUtil::to_int(child.GetAttribute("x")),
                        (float)StringUtil::to_int(child.GetAttribute("y"))
                    };
                }
            }
        
            IntRect tileRect = {
                {(int)draw_offset.x, (int)draw_offset.y},
                {tileWidth, tileHeight}
            };

            Texture tex(texture_path, false, tileRect);
            Sprite tilesprite(tex);
            
            Tile tile(id, draw_offset, tilesprite);

            map.AddTile(tile);
        }

        return map;
    }
}
