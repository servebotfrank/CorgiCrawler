//
//  player.hpp
//  Project
//
//  Created by Ian Ferguson on 3/29/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#ifndef player_hpp
#define player_hpp


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "tilemap.hpp"

class Player
{
public:
    
    Tilemap * map;
    Player();
    Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Texture&);
    ~Player();
    
    void move();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setSpeed(float, sf::Time);
    
    sf::Sprite getSprite() const;
    void setLocation(sf::Vector2f position);
    
private:
    sf::Sprite _Sprite;
    sf::Vector2f _Source;
    enum _Direction{Down, Left, Right, Up};
    
    float _Speed;
    sf::Clock _AnimClock;
    sf::Time _AnimTime;
    
    
};

#endif /* player_hpp */
