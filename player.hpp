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


class Player
{
public:
    Player();
    Player(sf::Texture&);
    ~Player();
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setSpeed(float, sf::Time);
    
    sf::Sprite getSprite() const;
private:
    sf::Sprite _Sprite;
    sf::Vector2i _Source;
    enum _Direction{Down, Left, Right, Up};
    
    float _Speed;
    sf::Clock _AnimClock;
    sf::Time _AnimTime;
    
};

#endif /* player_hpp */
