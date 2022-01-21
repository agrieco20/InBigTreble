/**
 * @author: Anthony Grieco
 * Date: 1/21/2022
 *
 * Description: Designed to store the location of each player as they progress through the game.
 * Player objects tend to communicate directly with the Space objects in order the determine where they need to travel to on the board.
*/

#pragma once

#include <string>
#include <SFML/Graphics.hpp> //SFML Graphics Libraries

using namespace std;
using namespace sf;

class Player
{
private:
	string teamName;
	string spriteLocation; //Sprite location on hard-drive that corresponds to each player
	Sprite player_Sprite;
	Texture spriteTexture;

public:
	int currentSpaceOccupied;
	float positionX;
	float positionY;

	Player(string, string, int, float, float);

	string getName();
	string getSpriteLocation();
	void setSprite();
	Sprite getSprite(float, float);
	//void setSpritePosition(float, float);
};