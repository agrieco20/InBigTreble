/**
 * @author: Anthony Grieco
 * Date: 1/21/2022
 *
 * Description: Designed to store the location of each player as they progress through the game.
 * Player objects tend to communicate directly with the Space objects in order the determine where they need to travel to on the board.
*/

#include "Player.h"
#include "SFML/Graphics.hpp" //SFML Graphics Libraries

using namespace std;
using namespace sf;

Player::Player(string myTeamName, string spriteMemoryLocation, int currentSpaceBeingOccupied, float xPos, float yPos) {
	teamName = myTeamName;
	spriteLocation = spriteMemoryLocation;
	currentSpaceOccupied = currentSpaceBeingOccupied;
	positionX = xPos;
	positionY = yPos;
}

string Player::getName() {
	return teamName;
}

string Player::getSpriteLocation() {
	return spriteLocation;
}

//Initiates the texture for each Player Object's Sprite and scales it to the appropriate size corresponding to the gameboard [only needs to be declared once in the code and has no impact on the starting location of each sprite]
void Player::setSprite() {
	//Texture spriteTexture;
	spriteTexture.loadFromFile(getSpriteLocation());

	//Sprite player_Sprite;
	player_Sprite.setTexture(spriteTexture);
	player_Sprite.setScale(0.5, 0.45);
	//player_Sprite.setPosition(500, 500);

	//return player_Sprite;
}

//Sets the location of the sprite for each Player Object
Sprite Player::getSprite(float positionX, float positionY) {
	player_Sprite.setPosition(positionX - 31.25, positionY - 28.575);
	return player_Sprite;
}

/*void Player::setSpritePosition(float positionX, float positionY) {
	getSprite().setPosition(positionX, positionY);
} */