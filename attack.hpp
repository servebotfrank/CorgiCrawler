//
//  attack.hpp
//  CorgiCrawler
//
//  Created by Erin Tolman on 4/24/18.
//  Copyright © 2018 Erin Tolman. All rights reserved.
//

#ifndef attack_hpp
#define attack_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Attack{
public:
    Attack();
    void fire(int speed, int direction);
    void Update();
    int getRight();
    int getLeft();
    int getTop();
    int getBottom();
    void draw(sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);
    ~Attack();
private:
    sf::RectangleShape _attack;
};
#endif /* attack_hpp */
