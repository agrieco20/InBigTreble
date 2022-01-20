// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
}

*/

//#include <windows.h> //Was used for commented out below but outdated....

#include "SFML/Graphics.hpp" //Graphics Libraries
#include "SFML/Window/Mouse.hpp" //Mouse Libraries
using namespace sf;
using namespace std;

int main()
{
    //-------------------------------------------------------
    //Below should be used to determine where mouse position is while program is running...
/* ********OUTDATED********

    string input = "";
    POINT p;

    while (input != "Stop") {
        GetCursorPos(&p);
        if (p.x > 500) {
            cout << "X above 500" << endl;
        } else {
            cout << "X below 500" << endl;
        }
    }
        //ScreenToClient(hwnd;&p);
    */


    //-------------------------------------------------------
    //Circle Test

    //***Window***
    int windowWidth = 1750;//1195;//2384; //temporary value
    int windowHeight = 2000;//3990 - 3990/2; //temporary value
    float myCircleRadius = 200.0;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Graphics Test");

    /*if (window.getSize().x > windowWidth) {
        cout << "Width Bigger" << endl;
    }
    else if (window.getSize().x < windowWidth) {
        cout << "Width Smaller" << endl;
    }

    if (window.getSize().y > windowHeight) {
        cout << "Height Bigger" << endl;
    }
    else if (window.getSize().x < windowHeight) {
        cout << "Height Smaller" << endl;
    }*/

    //***Circle***
    sf::CircleShape myCircle(myCircleRadius, 100);
    myCircle.setFillColor(sf::Color(0, 210, 255)); // Color circle

    //circle.setOrigin(circleRadius/2, circleRadius/2);

    myCircle.setPosition((windowWidth / 2) - myCircleRadius, (windowHeight / 2) - myCircleRadius); // Center circle

    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255)); // Color background
        window.draw(myCircle);
        window.display();
    } */

    //-------------------------------------------------------
    //Image Test
    //Image myImage;
    //myImage.loadFromFile("ImageFiles/Verdi.png");

    //----
    Texture myImageTexture;
    myImageTexture.loadFromFile("ImageFiles/Verdi.png");

    Sprite mySprite;
    mySprite.setTexture(myImageTexture);

    mySprite.setPosition(0, 0);
    //----

    //----
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("ImageFiles/InBigTrebleGAMEBOARD_2.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(0, 0);
    //----


    //-------------------------------------------------------
    //Mouse Test
    Mouse mouse;
    //mouse.getPosition(window).x;

    //-------------------------------------------------------
    //RUNNING IT!!!! (Event Execution)

    float widthRatio = 1.0;
    float heightRatio = 1.0;

    float screenRatio = 1.0;

    //-------------
    View gameView(FloatRect(0, 0, 1750.f, 2000.f));
    //gameView.setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    //-------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect gameView(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(gameView)); //For View
            }
        }

        //window.clear(sf::Color(255, 255, 255)); // Colored Background White
        window.clear(sf::Color(0, 0, 0)); // Colored Background Black

        window.draw(backgroundSprite);

        window.draw(myCircle);

        if (mouse.getPosition(window).x < 500) {
            window.draw(mySprite);
        }

        /*Attempt to resize images based on dimensions of window below
        Result: Initial failure led to unintentional success
        Notes: Some progress was made but found it would be easier to instead use a "View" [See above]
        */

        //screenRatio = (float(window.getSize().y) / float(window.getSize().x));
        //screenRatio;

        //widthRatio = (float(window.getSize().x) / float(window.getSize().y));
        //heightRatio = (float(window.getSize().y) / float(window.getSize().x));

        //cout << widthRatio<<","<< heightRatio<< endl;
        //myCircle.setScale(widthRatio, heightRatio);

        //backgroundSprite.scale(window);

        //widthRatio = float(window.getSize().x / window.getSize().y);
        //heightRatio = float(window.getSize().y / window.getSize().x);

        //myCircle.setScale(widthRatio, heightRatio);
        //backgroundSprite.scale(widthRatio, heightRatio);

        //cout << window.getSize().x<<endl;
        //myCircle.setScale(widthRatio, heightRatio);
        //mySprite.setScale();

        /*
        if (window.getSize().x == windowWidth) {
            widthRatio = 1;
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);

            //cout << "Same Width" << endl;
            //window.draw(myCircle);
        }

        if (window.getSize().y == windowHeight) {
            heightRatio = 1;
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);


            //cout << "Same Height" << endl;
            //window.draw(myCircle);
        }

        if (window.getSize().x > windowWidth) { //Width Difference [Bigger]
            widthRatio = float(float(1 + float(window.getSize().x - windowWidth) / window.getSize().x));
            //widthRatio = 2; //TEMPORARY
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);
            //All images/sprites to be listed here

            //window.draw(myCircle);
        }

        if (window.getSize().x < windowWidth) { //Width Difference [Smaller]
            widthRatio = float(float(1-float(windowWidth - window.getSize().x)/windowWidth));
            //widthRatio = 0.5; //TEMPORARY
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);
            //All images/sprites to be listed here

            //window.draw(myCircle);
        }

        if (window.getSize().y > windowHeight) { //Height Difference [Bigger]
            heightRatio = float(float(1 + float(window.getSize().y - windowHeight) / window.getSize().y));
            //heightRatio = 2; //TEMPORARY
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);

            //All images/sprites to be listed here

            //window.draw(myCircle);
        }

        if (window.getSize().y < windowHeight) { //Width Difference [Smaller]
            heightRatio = float(float(1 - float(windowHeight - window.getSize().y) / windowHeight));
            //heightRatio = 0.5; //TEMPORARY
            cout << widthRatio << "," << heightRatio << endl; //TEMPORARY

            myCircle.setScale(widthRatio, heightRatio);
            //mySprite.setScale(widthRatio, heightRatio);
            //backgroundSprite.setScale(widthRatio, heightRatio);
            //All images/sprites to be listed here

            //window.draw(myCircle);
        } */

        //Test with Cout
        /*if (window.getSize().x > windowWidth) {

            cout << "Width Bigger" << endl; //Not Permanent
        }
        if (window.getSize().x < windowWidth) {

            cout << "Width Smaller" << endl; //Not Permanent
        }

        if (window.getSize().y > windowHeight) {

            cout << "Height Bigger" << endl; //Not Permanent
        }
        if (window.getSize().y < windowHeight) {

            cout << "Height Smaller" << endl; //Not Permanent
        } */

        window.display();
    }

    cout << "Hello World!" << endl;
    return 0;
}