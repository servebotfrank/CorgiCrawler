//
//  Enemy.hpp
//  Project
//
//  Created by Ian Ferguson on 4/24/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "tilemap.hpp"


class Enemy
{
public:
    sf::RectangleShape rect;
    float bottom, left, right, top;
    Tilemap * map;
    Enemy();
    Enemy(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Texture&);
    ~Enemy();
    
    void Update();
    bool Collision( Enemy e );
    void path(sf::Vector2f first, sf::Vector2f second);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setSpeed(float, sf::Time);
    
    sf::Sprite getSprite() const;

private:
    sf::Sprite _Sprite;
    sf::Vector2f _Source;
    enum _Direction{Down, Left, Right, Up};
    
    float _Speed;
    sf::Clock _AnimClock;
    sf::Time _AnimTime;
	bool towardFirst = true;
	bool towardX = true;
    
};

#endif /* Enemy_hpp */
