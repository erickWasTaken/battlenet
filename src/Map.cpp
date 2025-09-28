#include "Map.hpp"

namespace Overworld{
    Tile::Tile(unsigned int id, Vector2f drawingOffset, Sprite sprite) : 
    id{id},
    drawingOffset{drawingOffset},
    sprite{sprite}{}

    Map::Map(unsigned cols, unsigned rows, int tileWidth, int tileHeight){
        this->cols = cols;
        this->rows = rows;
        this->tileWidth = tileWidth;
        this->tileHeight = tileHeight;
    }
    
    Map::Map(int tileWidth, int tileHeight){
        this->tileWidth = tileWidth;
        this->tileHeight = tileHeight;
    }

    unsigned Map::GetCols() const {return cols;}
    unsigned Map::GetRows() const {return rows;}
    unsigned int Map::GetTileCount() {return static_cast<unsigned int>(tiles.size());}

    Tile* Map::GetTile(int x, int y){
    
        if(x < 0 || y < 0 || x > (int)cols || y > (int)rows)
            return nullptr;
        
        return &tiles[y * cols + x];
    }

    Vector2i Map::GetTileDimensions(){
        return {
            tileWidth,
            tileHeight
        };
    }

    void Map::Draw(DrawWindow* target){
        for(auto& tile : tiles){
            target->draw(tile.sprite);
        } 
    }
}
