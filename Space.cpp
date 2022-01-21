/**
 * @author: Anthony Grieco
 * Date: 1/20/2022
 * 
 * Description: Designed to store the location of each of the spaces players can land on while playing the game
*/

#include "Space.h"
using namespace std;

Space::Space(int SpaceNum, float centerX, float centerY, bool isOccupied) {
	this->spaceNum = spaceNum;
	this->centerX = centerX;
	this->centerY = centerY;
	this->isOccupied = isOccupied;
}

int Space::getSpaceNum() {
	return spaceNum;
}

float Space::getCenterX() {
	return centerX;
}

float Space::getCenterY() {
	return centerY;
}