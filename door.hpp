//
//  door.hpp
//  GameCorgi
//
//  Created by Joseph Byam on 4/25/18.
//  Copyright © 2018 Joseph Byam. All rights reserved.
//

#ifndef door_hpp
#define door_hpp

#include <stdio.h>
#include <SFML/Graphics/Rect.hpp>

class Door {
public:
    
    Door( sf::FloatRect rect, int target ) {
        this->rect = rect;
        this->targetLevel = target;
    }
    
    sf::FloatRect rect;
    int targetLevel;
    
private:
    
};

#endif /* door_hpp */
