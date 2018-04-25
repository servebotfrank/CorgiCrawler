
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
#include "Enemy.hpp"


// Here is a small helper for you! Have a look.

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    
    //Define the level with an array
    const int level[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
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
    
    // Load a sprite to display
    Tilemap map;
    if (!map.load("corgi crawler tiles.png", sf::Vector2u(32, 32), level, 25, 19)) {
        return -1;
    }
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("Corgi.png"))
        std::cout << "Texture Error" << std::endl;
    
    sf::Sprite sprite(playerTexture);
    
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("evil vacuum sprite.png"))
        std::cout << "Texture Error" << std::endl;
    
    
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    
    Enemy enemy(sf::Vector2f(600 - 20, 350 - 32), sf::Vector2f(50, 50), sf::Vector2f(1.0f, 1.0f), enemyTexture);
    
    Player player(sf::Vector2f(600 - 32, 350 - 32), sf::Vector2f(48, 45), sf::Vector2f(1.5f, 1.5f), playerTexture);
    player.map = &map;
    
    // Start the game loop
    while (window.isOpen())
    {
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //Move Up
            player.moveUp();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //Move Right
            player.moveRight();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) //Move Down
            player.moveDown();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //Move Left
            player.moveLeft();
        
        
        
        
        
        
        // Draw the string
        window.draw(text);
        
        //Draw map
        window.draw(map);
        
        //Draws the Player sprite (Don't do this before drawing the map!)
        window.draw(player.getSprite());
        
        window.draw(enemy.getSprite());
        
        
        // Update the window
        window.display();
        
        
    }
    
    return EXIT_SUCCESS;
}
