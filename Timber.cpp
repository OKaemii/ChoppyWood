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
    Texture textureTree;
    Texture textureBee;
    Texture textureCloud;

    // load background img into GPU
    textureBackground.loadFromFile("graphics/background.png");
    textureTree.loadFromFile("graphics/tree.png");
    textureBee.loadFromFile("graphics/bee.png");
    textureCloud.loadFromFile("graphics/cloud.png");

    // init background, and tree as sprite for placement
    Sprite spriteBackground;
    Sprite spriteTree;
    Sprite spriteBee;

    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    
    
    // link sprite and graphics
    spriteBackground.setTexture(textureBackground);
    spriteTree.setTexture(textureTree);
    spriteBee.setTexture(textureBee);

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // set position of background and sprite relative to viewscreen
    spriteBackground.setPosition(0,0);
    spriteTree.setPosition(810, 0);
    spriteBee.setPosition(0, 800);

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    // clouds current on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    // cloud stats
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3speed = 0.0f;

    // is bee currently mobile?
    bool beeAcive = false;
    // bee stats
    float beeSpeed = 0.0f;

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
        window.draw(spriteTree);

        window.display();
    }

    return 0;
}
