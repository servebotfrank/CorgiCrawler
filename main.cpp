
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


// Here is a small helper for you! Have a look.

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("Black.jpg")) {
        return EXIT_FAILURE;
    }
    
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("Corgi.png"))
        std::cout << "Texture Error" << std::endl;
    
    sf::Sprite sprite(playerTexture);
    


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
    
    
    Player player(playerTexture);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Move Up
            player.moveUp();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Move Right
            player.moveRight();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Move Down
            player.moveDown();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Move Left
            player.moveLeft();
        




        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        window.draw(text);
        window.draw(player.getSprite());



        // Update the window
        window.display();
        

    }

    return EXIT_SUCCESS;
}
