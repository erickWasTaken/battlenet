#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "DrawWindow.hpp"

using namespace sf;

using namespace std;

namespace Overworld{

    struct Tile{
        const unsigned int id;
        // const unsigned int gid;
        const Vector2f drawingOffset;
        // const Vector2f alignmentOffset;
        Sprite sprite;

        Tile(
            unsigned int id,
            // unsigned int gid,
            Vector2f drawingOffset,
            // Vector2f alignmentOffset,
            Sprite sprite
        );
    };

    class Map{
    public:
        Map(unsigned cols, unsigned rows, int tileWidth, int tileHeight);
        Map(int tileWidth, int tileHeight);
        unsigned GetCols() const;
        unsigned GetRows() const;
        unsigned int GetTileCount();
        Vector2i GetTileDimensions();
        Tile* GetTile(int x, int y);
        void AddTile(Tile tile){ tiles.push_back(tile); }
        void Draw(DrawWindow* target);

    protected:   
        unsigned cols{}, rows{};
        int tileWidth{}, tileHeight{};
        vector<Tile> tiles;
    };
}
