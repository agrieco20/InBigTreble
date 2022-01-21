/**
 * @author: Anthony Grieco
 * Date: 1/20/2022
 *
 * Description: Designed to store the location of each of the spaces players can land on while playing the game
*/

#pragma once
using namespace std;

class Space
{
private:
	int spaceNum;
	float centerX;
	float centerY;

public:
	bool isOccupied;

	Space(int, float, float, bool);

	int getSpaceNum();
	float getCenterX();
	float getCenterY();
};