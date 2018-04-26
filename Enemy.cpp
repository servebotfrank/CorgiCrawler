//
//  Enemy.cpp
//  Project
//
//  Created by Ian Ferguson on 4/24/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#include "Enemy.hpp"


#define PI 3.14159265359

Enemy::Enemy()
{
    
}

Enemy::~Enemy()
{
    
}

Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Texture& TEMP_Texture)
{
    rect.setPosition(position);
    rect.setSize(size);
    rect.setScale(scale);
    
    //Enemy SPRITE
    _Sprite.setTexture(TEMP_Texture); //Set Sprite Texture
    _Sprite.setPosition(position); //Set Sprite Position (Centre)
    _Sprite.setScale(scale); //Sprite Scale
    //sf::Vector2i _Source(1, Up); //Default Sprite Sheet Crop
    _Sprite.setTextureRect(sf::IntRect(_Source.x * 100, _Source.y *100 , 100, 100)); //Crop Sprite Sheet (Default Crop)
    
    //PLAYER / ANIMATION SPEED
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed = 0.8; //Player Speed
}

void Enemy::Update () {
    
    bottom = rect.getPosition().y + rect.getSize().y;
    left = rect.getPosition().x;
    right = rect.getPosition().x + rect.getSize().x;
    top = rect.getPosition().y;
}

bool Enemy::Collision( Enemy e) {
    if(right < e.left || left > e.right || top > e.bottom || bottom < e.top) {
        return false;
    }
    return true;
}

sf::Sprite Enemy::getSprite() const
{
    return _Sprite;
}

void Enemy::moveUp()
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

void Enemy::moveDown()
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

void Enemy::moveRight()
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

void Enemy::moveLeft()
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

void Enemy::path(sf::Vector2f first, sf::Vector2f second)
{
	int direction;
	sf::CircleShape pathpoint[2];
	pathpoint[0].setPosition(first);
	pathpoint[0].setRadius(2);
	pathpoint[1].setPosition(second);
	pathpoint[1].setRadius(2);

	//Path between two points
	if (towardFirst == true)
	{

		if (towardX == true)
		{
			if ((_Sprite.getPosition().x - first.x) > 0.0)
				direction = -1;
			else
				direction = 1;

			_Sprite.move(_Speed*direction, 0);
			if ((_Sprite.getPosition().x - first.x) > -1 && (_Sprite.getPosition().x - first.x) < 1)
				towardX = false;
		}
		else
		{
			if ((_Sprite.getPosition().y - first.y) > 0.0)
				direction = -1;
			else
				direction = 1;

			_Sprite.move(0, _Speed*direction);
			
			if ((_Sprite.getPosition().y - first.y) > -1 && (_Sprite.getPosition().y - first.y) < 1)
				towardX = true;

		}
		
		if (_Sprite.getGlobalBounds().intersects(pathpoint[0].getGlobalBounds()) == true)
			towardFirst = false;
	}
	//-----------------------------------------------------

	else
	{
		if (towardX == true)
		{
			if ((_Sprite.getPosition().x - second.x) > 0.0)
				direction = -1;
			else
				direction = 1;

			_Sprite.move(_Speed*direction, 0);

			if ((_Sprite.getPosition().x - second.x) > -1 && (_Sprite.getPosition().x - second.x) < 1)
				towardX = false;

		}
		else
		{
			if ((_Sprite.getPosition().y - second.y) > 0.0)
				direction = -1;
			else
				direction = 1;

			_Sprite.move(0, _Speed*direction);
		}
	
		if (_Sprite.getGlobalBounds().intersects(pathpoint[1].getGlobalBounds()) == true)
			towardFirst = true;

		if ((_Sprite.getPosition().y - second.y) > -1 && (_Sprite.getPosition().y - second.y) < 1)
			towardX = true;
	}
}
