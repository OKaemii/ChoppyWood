//#include <iostream>
#include <sstream>
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

	// HUD
	int score = 0;

	Font fontKOMIKAP_;
	fontKOMIKAP_.loadFromFile("fonts/KOMIKAP_.ttf");

	Text textGamePrompt;
	Text textScore;
	// game prompt text properties
	textGamePrompt.setString("Press Enter to start!");
	textScore.setString("Score = 0");
	// size -- want it really big
	textGamePrompt.setCharacterSize(75);
	textScore.setCharacterSize(100);
	// colour
	textGamePrompt.setFillColor(Color::White);
	textScore.setFillColor(Color::White);
	// font
	textGamePrompt.setFont(fontKOMIKAP_);
	textScore.setFont(fontKOMIKAP_);

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
	spriteBackground.setPosition(0, 0);
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
	float cloud3Speed = 0.0f;

	// is bee currently mobile?
	bool beeActive = false;
	// bee stats
	float beeSpeed = 0.0f;

	// object to measure time
	Clock clock;
	// to halt the game
	bool paused = true;

	while (window.isOpen())
	{
		/*
		* Handle Player Input
		*/
		// exit game
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
		}

		/*
		* Update the Scene
		*/
		if (!paused)
		{
			// measure time
			Time dt = clock.restart();

			// bee animation
			if (!beeActive)
			{
				// assign rand speed to bee
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;
				// assign rand bee to altitude
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			// bee to move across screen
			else
			{
				spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
				// if bee at end of screen
				if (spriteBee.getPosition().x < -100)
				{
					// reset bee and random height
					beeActive = false;
				}
			}

			// cloud animation
			// cloud 1
			if (!cloud1Active)
			{
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else
			{
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
				if (spriteCloud1.getPosition().x > 1920)
				{
					cloud1Active = false;
				}
			}
			// Cloud 2
			if (!cloud2Active)
			{
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else
			{
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
				if (spriteCloud2.getPosition().x > 1920)
				{
					cloud2Active = false;
				}
			}
			if (!cloud3Active)
			{
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			}
			else
			{
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
				if (spriteCloud3.getPosition().x > 1920)
				{
					cloud3Active = false;
				}
			}
		}

		/*
		* Draw the Scene
		*/
		// draw a new scene
		window.clear();

		// background
		window.draw(spriteBackground);

		// clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// tree
		window.draw(spriteTree);

		// bee
		window.draw(spriteBee);

		// display onto viewscreen
		window.display();
	}

	return 0;
}
