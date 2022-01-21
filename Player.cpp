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

Player::Player(string teamName, string spriteLocation, int currentSpaceOccupied, float positionX, float positionY) {
	this->teamName = teamName;
	this->spriteLocation = spriteLocation;
	this->currentSpaceOccupied = currentSpaceOccupied;
	this->positionX = positionX;
	this->positionY = positionY;
}

string Player::getName() {
	return teamName;
}

string Player::getSpriteLocation() {
	return spriteLocation;
}

void Player::setSprite() {
	//Texture spriteTexture;
	spriteTexture.loadFromFile(getSpriteLocation());

	//Sprite player_Sprite;
	player_Sprite.setTexture(spriteTexture);
	//player_Sprite.setPosition(500, 500);

	//return player_Sprite;
}

Sprite Player::getSprite(float positionX, float positionY) {
	player_Sprite.setPosition(positionX, positionY);
	return player_Sprite;
}

/*void Player::setSpritePosition(float positionX, float positionY) {
	getSprite().setPosition(positionX, positionY);
} */