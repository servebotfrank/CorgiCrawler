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
    sf::Vector2i _Source(1, Down); //Default Sprite Sheet Crop
    _Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32)); //Crop Sprite Sheet (Default Crop)
    
    //PLAYER / ANIMATION SPEED
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed = 0.20; //Player Speed
}

Player::~Player()
{
    
}

sf::Sprite Player::getSprite() const
{
    return _Sprite;
}
