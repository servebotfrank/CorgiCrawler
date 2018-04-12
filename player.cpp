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

Player::Player(sf::Texture& TEMP_Texture)
{
    //PLAYER SPRITE
    _Sprite.setTexture(TEMP_Texture); //Set Sprite Texture
    _Sprite.setPosition(600 - 32, 350 - 32); //Set Sprite Position (Centre)
    _Sprite.setScale(1.5f, 1.5f); //Sprite Scale
    //sf::Vector2i _Source(1, Up); //Default Sprite Sheet Crop
    _Sprite.setTextureRect(sf::IntRect(_Source.x * 145, _Source.y *180 , 48, 45)); //Crop Sprite Sheet (Default Crop)
    
    //PLAYER / ANIMATION SPEED
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed = 0.8; //Player Speed
}

Player::~Player()
{
    
}

sf::Sprite Player::getSprite() const
{
    return _Sprite;
}

void Player::moveUp()
{
    _Source.y = Up; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, -_Speed); //Move Player Sprite
    
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

void Player::moveDown()
{
    _Source.y = Down; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, _Speed); //Move Player Sprite
    
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

void Player::moveRight()
{
    _Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(_Speed, 0); //Move Player Sprite
    
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

void Player::moveLeft()
{
    _Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(-_Speed, 0); //Move Player Sprite
    
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

