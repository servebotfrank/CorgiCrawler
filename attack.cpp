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

void Attack::fire(int speed, int direction)
{
    if(direction == 1)
        _attack.move(0, -speed);
    
    if(direction == 3)
        _attack.move(0, speed);
    
    if(direction == 2)
        _attack.move(speed, 0);
    
    if(direction == 4)
        _attack.move(-speed, 0);
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
    window.draw(_attack);
}

sf::Vector2f Attack::getPosition(){
    return _attack.getPosition();
}

void Attack::setPos(sf::Vector2f newPos)
{
    _attack.setPosition(newPos);
}

Attack::~Attack(){}
