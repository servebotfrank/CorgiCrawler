
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <iostream>
#include "tilemap.hpp"
#include "attack.hpp"

// Here is a small helper for you! Have a look.

int Tilemap::nextLevel = 0;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    //Define the level with an array
    const int level0[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,


       };
    
    const int level1[] =
    {
        1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
        
        
    };
    
    const int level2[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
        
        
    };
    
    const int level3[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
        
        
    };
    
    // Load a sprite to display
    Tilemap map;
    if (!map.load("corgi crawler tiles.png", sf::Vector2u(32, 32), level0, 25, 19)) {
        return -1;
    }
    
    Tilemap map2;
    if (!map2.load("corgi crawler tiles.png", sf::Vector2u(32, 32), level1, 25, 19)) {
        return -1;
    }
    
    Tilemap map3;
    if (!map3.load("corgi crawler tiles.png", sf::Vector2u(32, 32), level2, 25, 19)) {
        return -1;
    }
    
    Tilemap map4;
    if (!map4.load("corgi crawler tiles.png", sf::Vector2u(32, 32), level3, 25, 19)) {
        return -1;
    }
    
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("Corgi.png"))
        std::cout << "Texture Error" << std::endl;
    
    sf::Sprite sprite(playerTexture);
    
    //Create attack object and vector
    Attack attack;
    vector<Attack> attackVector;
    int direction;
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("Pattern12.ogg")) {
        return EXIT_FAILURE;
    }
    // Play the music
    music.play();
    // Loop music
    music.setLoop(true);
    // Set Volume
    music.setVolume(20);
    
    // Set sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Bark2.wav");
    sf::Sound bark;
    bark.setBuffer(buffer);
   
    
    Player player(sf::Vector2f(365, 250), sf::Vector2f(48, 45), sf::Vector2f(1.5f, 1.5f), playerTexture);
    
    Player player2(sf::Vector2f(200, 125), sf::Vector2f(48, 45), sf::Vector2f(1.5f, 1.5f), playerTexture);
    

    // Start the game loop
    while (window.isOpen())
    {
        if ( Tilemap::nextLevel == 0)
            player.map = &map;
        if ( Tilemap::nextLevel == 1)
            player.map = &map2;
        if ( Tilemap::nextLevel == 2)
            player.map = &map3;
        if ( Tilemap::nextLevel == 3)
            player.map = &map4;
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        

        // Clear screen
        window.clear();
        
        //PLAYER MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ //Move Up
            player.moveUp();
            direction = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ //Move Right
            player.moveRight();
            direction = 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ //Move Down
            player.moveDown();
            direction = 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ //Move Left
            player.moveLeft();
            direction = 4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
             bark.play();
             attackVector.push_back(attack);
             attack.setPos(sf::Vector2f(player.getX() , player.getY()));
        }
        //PLAYER2 MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Move Up
            player2.moveUp();
            direction = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //Move Right
            player2.moveRight();
            direction = 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //Move Down
            player2.moveDown();
            direction = 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //Move Left
            player2.moveLeft();
            direction = 4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            bark.play();
            attackVector.push_back(attack);
            attack.setPos(sf::Vector2f(player2.getX() , player2.getY()));
        }

        // Draw the string
        window.draw(text);
        
        //Draw map
        
        //I haven't gotten all of it to work yet. If you run this with the commented code below it will compile, but it not what I want and I know it isn't what we are trying to do. I'll work on it more tomorrow.
        
        if ( Tilemap::nextLevel == 0)
            window.draw(map);
        if (Tilemap::nextLevel == 1) {
            window.draw(map2);
            //player.setLocation(sf::Vector2f(365, 450));
        }
        if ( Tilemap::nextLevel == 2) {
            window.draw(map3);
            //player.setLocation(sf::Vector2f(75, 230));
        }
        if ( Tilemap::nextLevel == 3) {
            window.draw(map4);
            //player.setLocation(sf::Vector2f(665, 230));
        }
        
        //Draws the Player sprite (Don't do this before drawing the map!)
        window.draw(player.getSprite());
        window.draw(player2.getSprite());
        
        //Draw attack
        for(int i =0; i < attackVector.size(); i++){
            
            attackVector[i].draw(window);
            attackVector[i].fire(8, direction);
            if(attackVector[i].getPosition().x < 0 || attackVector[i].getPosition().x > window.getSize().x || attackVector[i].getPosition().y < 0 || attackVector[i].getPosition().y > window.getSize().y){
                attackVector.erase(attackVector.begin() + i);
            }
        }
        
        // Update the window
        window.display();
        

    }

    return EXIT_SUCCESS;
}
