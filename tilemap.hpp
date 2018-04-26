//
//  tilemap.hpp
//  Project
//
//  Created by Ian Ferguson on 4/13/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#ifndef tilemap_hpp
#define tilemap_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "door.hpp"

using std::vector;


class Tilemap: public sf::Drawable, public sf::Transformable
{
public:
    static int nextLevel;
    bool load(const std::string& tile, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    vector<sf::FloatRect> walls;
    vector<Door> doors;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();
        
        // apply the tileset texture
        states.texture = &m_tileset;
        
        // draw the vertex array
        target.draw(m_vertices, states);
    }
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    
};

#endif /* tilemap_hpp */
