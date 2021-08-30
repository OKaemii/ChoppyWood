//#include <iostream>
#include <SFML/Graphics.hpp>

// make code easier to read
using namespace sf;

// this is where game starts
int main()
{
    // create a video mode object of 1920x1080 pixels
    VideoMode vm(1920, 1080);

    // create and open a window for the game
    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    // texture to hold graphics on the GPU
    Texture textureBackground;

    // load background img into GPU
    textureBackground.loadFromFile("graphics/background.png");

    // init background as sprite for placement
    Sprite spriteBackground;
    
    // link sprite and graphics
    spriteBackground.setTexture(textureBackground);

    // set position of background relative to viewscreen
    spriteBackground.setPosition(0,0);

    while (window.isOpen())
    {
        /*
        * Handle Player Input
        */
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
        * Update the Scene
        */
        // nothing to do for now

        /*
        * Draw the Scene
        */
        // draw a new scene
        window.clear();

        // display background onto screenview
        window.draw(spriteBackground);

        window.display();
    }

    return 0;

}
