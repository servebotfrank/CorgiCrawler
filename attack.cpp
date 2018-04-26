//
//  attack.cpp
//  CorgiCrawler
//
//  Created by Erin Tolman on 4/24/18.
//  Copyright © 2018 Erin Tolman. All rights reserved.
//

#include "attack.hpp"

Attack::Attack()
{
    _attack.setSize(sf::Vector2f(10,10));
    _attack.setPosition(0,0);
    _attack.setFillColor(sf::Color::Red);
}

Attack::Attack(sf::Texture &TEMP_Texture)
{
    _attack.setSize(sf::Vector2f(32,32));
    _Sprite.setPosition(0,0);
    _Sprite.setTexture(TEMP_Texture);
    _Sprite.setTextureRect(sf::IntRect(_Source.x * 145, _Source.y *180 , 32, 32));
}

void Attack::fire(int speed, int direction)
{
    if(direction == 1)
        _Sprite.move(0, -speed);
    
    if(direction == 3)
        _Sprite.move(0, speed);
    
    if(direction == 2)
        _Sprite.move(speed, 0);
    
    if(direction == 4)
        _Sprite.move(-speed, 0);
    
}

int Attack::getRight()
{
    return _attack.getPosition().x + _attack.getSize().x;
}

int Attack::getLeft()
{
    return _attack.getPosition().x;
}

int Attack::getTop()
{
    return _attack.getPosition().y;
}

int Attack::getBottom()
{
    return _attack.getPosition().y + _attack.getSize().y;
}

void Attack::draw(sf::RenderWindow &window)
{
    window.draw(_Sprite);
}

sf::Vector2f Attack::getPosition(){
    return _Sprite.getPosition();
}

void Attack::setPos(sf::Vector2f newPos)
{
    _Sprite.setPosition(newPos);
}

Attack::~Attack(){}
