//
//  player.cpp
//  Project
//
//  Created by Ian Ferguson on 3/29/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#include "player.hpp"

Player::Player()
{
    
}

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Texture& TEMP_Texture)
{
    rect.setPosition(position);
    rect.setSize(size);
    rect.setScale(scale);
    
    //PLAYER SPRITE
    _Sprite.setTexture(TEMP_Texture); //Set Sprite Texture
    _Sprite.setPosition(position); //Set Sprite Position (Centre)
    _Sprite.setScale(scale); //Sprite Scale
    //sf::Vector2i _Source(1, Up); //Default Sprite Sheet Crop
    _Sprite.setTextureRect(sf::IntRect(_Source.x * 145, _Source.y *180 , 48, 45)); //Crop Sprite Sheet (Default Crop)
    
    //PLAYER / ANIMATION SPEED
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed = 0.8; //Player Speed
}

Player::~Player()
{
    
}

void Player::Update () {
    
    bottom = rect.getPosition().y + rect.getSize().y;
    left = rect.getPosition().x;
    right = rect.getPosition().x + rect.getSize().x;
    top = rect.getPosition().y;
}

bool Player::Collision( Player p) {
    if(right < p.left || left > p.right || top > p.bottom || bottom < p.top) {
        return false;
    }
    return true;
}

sf::Sprite Player::getSprite() const
{
    return _Sprite;
}

void Player::moveUp()
{
    _Source.y = Up; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, -_Speed); //Move Player Sprite
    
    bool hitsWall = false;
    for (sf::FloatRect wall : map->walls) {
        if (_Sprite.getGlobalBounds().intersects(wall)) {
            hitsWall = true;
            break;
        }
    }
    
    if (hitsWall) {
        _Sprite.move(0, _Speed);
    }
    else {
        if (_AnimClock.getElapsedTime() > _AnimTime)
        {
            _Sprite.setTextureRect(sf::IntRect(_Source.x * 48, _Source.y * 45, 48, 45)); //Crop Sprite Sheet
        
            //Animation
            _Source.x++;
            if(_Source.x * 48 >= _Sprite.getTexture()->getSize().x)
            {
                _Source.x = 0;
            }
            _AnimClock.restart();
        
        }
    }
    
}

void Player::moveDown()
{
    _Source.y = Down; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, _Speed); //Move Player Sprite
    
    bool hitsWall = false;
    for (sf::FloatRect wall : map->walls) {
        if (_Sprite.getGlobalBounds().intersects(wall)) {
            hitsWall = true;
            break;
        }
    }
    
    if (hitsWall) {
        _Sprite.move(0, -_Speed);
    }
    else {
    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        _Sprite.setTextureRect(sf::IntRect(_Source.x * 48, _Source.y * 45, 48, 45)); //Crop Sprite Sheet
        
        //Animation
        _Source.x++;
        if(_Source.x * 48 >= _Sprite.getTexture()->getSize().x)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
        
    }
    }
}

void Player::moveRight()
{
    _Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(_Speed, 0); //Move Player Sprite
    
    
    bool hitsWall = false;
    for (sf::FloatRect wall : map->walls) {
        if (_Sprite.getGlobalBounds().intersects(wall)) {
            hitsWall = true;
            break;
        }
    }
    
    if (hitsWall) {
        _Sprite.move(-_Speed, 0);
    }
    else {
    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        _Sprite.setTextureRect(sf::IntRect(_Source.x * 48, _Source.y * 45, 48, 45)); //Crop Sprite Sheet
        
        //Animation
        _Source.x++;
        if(_Source.x * 48 >= _Sprite.getTexture()->getSize().x)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
    }
}

void Player::moveLeft()
{
    _Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(-_Speed, 0); //Move Player Sprite
    
  
    bool hitsWall = false;
    for (sf::FloatRect wall : map->walls) {
        if (_Sprite.getGlobalBounds().intersects(wall)) {
            hitsWall = true;
            break;
        }
    }
    
    if (hitsWall) {
        _Sprite.move(_Speed, 0);
    }
    else {
    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        _Sprite.setTextureRect(sf::IntRect(_Source.x * 48, _Source.y * 45, 48, 45)); //Crop Sprite Sheet
        
        //Animation
        _Source.x++;
        if(_Source.x * 48 >= _Sprite.getTexture()->getSize().x)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
    }
}

