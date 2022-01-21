/**
 * @author: Anthony Grieco
 * Date: 1/19/2022
 *
 * Description: Designed to simulate the movement of players as they travel around the game board
 * Intended only for the use of Dr. Stephen Grieco. This program was built for the benefit of his students and to bring his game "In Big Treble" to life.
*/

#include <iostream>
#include "SFML/Graphics.hpp" //Graphics Libraries
#include "SFML/Window/Mouse.hpp" //Mouse Libraries
#include "Space.h" //Designed to store the location of each of the spaces players can land on while playing the game
//#include "Player.h"

using namespace sf;
using namespace std;

int main()
{
    //-------------------------------------------------------
    /* Initialization of each Space Object, which are each used by the player objects to determine 
    the cordinates where they need to be placed when the move around the board.
    */
    Space space1(1, 790.f, 1612.f, false);      //Space space51(51, .f, .f, false);
    //Space space2(2, .f, .f, false);       //Space space52(52, .f, .f, false);
    //Space space3(3, .f, .f, false);       //Space space53(53, .f, .f, false);
    //Space space4(4, .f, .f, false);       //Space space54(54, .f, .f, false);
    //Space space5(5, .f, .f, false);       //Space space55(55, .f, .f, false);
    //Space space6(6, .f, .f, false);       //Space space56(56, .f, .f, false);
    //Space space7(7, .f, .f, false);       //Space space57(57, .f, .f, false);
    //Space space8(8, .f, .f, false);       //Space space58(58, .f, .f, false);
    //Space space9(9, .f, .f, false);       //Space space59(59, .f, .f, false);
    //Space space10(10, .f, .f, false);       //Space space60(60, .f, .f, false);
    //Space space12(11, .f, .f, false);       //Space space61(61, .f, .f, false);
    //Space space12(12, .f, .f, false);       //Space space62(62, .f, .f, false);
    //Space space13(13, .f, .f, false);       //Space space63(63, .f, .f, false);
    //Space space14(14, .f, .f, false);       //Space space64(64, .f, .f, false);
    //Space space15(15, .f, .f, false);       //Space space65(65, .f, .f, false);
    //Space space16(16, .f, .f, false);       //Space space66(66, .f, .f, false);
    //Space space17(17, .f, .f, false);       //Space space67(67, .f, .f, false);
    //Space space18(18, .f, .f, false);       //Space space68(68, .f, .f, false);
    //Space space19(19, .f, .f, false);       //Space space69(69, .f, .f, false);
    //Space space20(20, .f, .f, false);       //Space space70(70, .f, .f, false);
    //Space space21(21, .f, .f, false);       //Space space71(71, .f, .f, false);
    //Space space22(22, .f, .f, false);       //Space space72(72, .f, .f, false);
    //Space space23(23, .f, .f, false);       //Space space73(73, .f, .f, false);
    //Space space24(24, .f, .f, false);       //Space space74(74, .f, .f, false);
    //Space space25(25, .f, .f, false);       //Space space75(75, .f, .f, false);
    //Space space26(26, .f, .f, false);       //Space space76(76, .f, .f, false);
    //Space space27(27, .f, .f, false);       //Space space77(77, .f, .f, false);
    //Space space28(28, .f, .f, false);       //Space space78(78, .f, .f, false);
    //Space space29(29, .f, .f, false);       //Space space79(79, .f, .f, false);
    //Space space30(30, .f, .f, false);       //Space space80(80, .f, .f, false);
    //Space space31(31, .f, .f, false);       //Space space81(81, .f, .f, false);
    //Space space32(32, .f, .f, false);       //Space space82(82, .f, .f, false);
    //Space space33(33, .f, .f, false);       //Space space83(83, .f, .f, false);
    //Space space34(34, .f, .f, false);       //Space space84(84, .f, .f, false);
    //Space space35(35, .f, .f, false);       //Space space85(85, .f, .f, false);
    //Space space36(36, .f, .f, false);       //Space space86(86, .f, .f, false);
    //Space space37(37, .f, .f, false);       //Space space87(87, .f, .f, false);
    //Space space38(38, .f, .f, false);       //Space space88(88, .f, .f, false);
    //Space space39(39, .f, .f, false);       //Space space89(89, .f, .f, false);
    //Space space40(40, .f, .f, false);       //Space space90(90, .f, .f, false);
    //Space space41(41, .f, .f, false);       //Space space91(91, .f, .f, false);
    //Space space42(42, .f, .f, false);       //Space space92(92, .f, .f, false);
    //Space space43(43, .f, .f, false);       //Space space93(93, .f, .f, false);
    //Space space44(44, .f, .f, false);       //Space space94(94, .f, .f, false);
    //Space space45(45, .f, .f, false);       //Space space95(95, .f, .f, false);
    //Space space46(46, .f, .f, false);       //Space space96(96, .f, .f, false);
    //Space space47(47, .f, .f, false);       //Space space97(97, .f, .f, false);
    //Space space48(48, .f, .f, false);
    //Space space49(49, .f, .f, false);
    //Space space50(50, .f, .f, false);

    /*Each Space object is then added to an array so that they can be conveniently accessed to be
      compared to the player objects 
    */
    
    //Space * arrayOfSpaces = new Space[97];

    //Space arrayOfSpaces = { space1, space2 };

    //array<int, 1> arrayOfSpaces{ space1 };

    //for (int i = 0; i < arrayofSpaces.length; i++) {}
    //int * numarray = new int[10];

    //-------------------------------------------------------
    //Circle Test

    //***Window***
    int windowWidth = 1750;//1195;//2384; //temporary value
    int windowHeight = 2000;//3990 - 3990/2; //temporary value
    float myCircleRadius = 200.0;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "In Big Treble");

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
    //myCircle.setFillColor(sf::Color(0, 210, 255)); //Circle Color: Aqua
    myCircle.setFillColor(sf::Color(128, 128, 128)); //Circle Color: Gray

    myCircle.setPosition((windowWidth) - myCircleRadius -200, (windowHeight / 10) - myCircleRadius); // Center circle

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
    //myImageTexture.loadFromFile("ImageFiles/Bach_Edited.png");
    myImageTexture.loadFromFile("ImageFiles/Verdi_Edited.png");

    Sprite mySprite;
    mySprite.setTexture(myImageTexture);
    mySprite.setPosition(0, 0);
    
    Sprite mySprite2;
    mySprite2.setTexture(myImageTexture);
    //mySprite2.setPosition(1195, 0);
    mySprite2.setScale(0.5, 0.45); //All player sprites will need to be scaled
    //----

    //----
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("ImageFiles/InBigTrebleGAMEBOARD_2.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(0, 0);
    //----


    //-------------------------------------------------------
    //Mouse Initialization
    Mouse mouse;
    //mouse.getPosition(window).x;

    //-------------------------------------------------------
    //Event Execution


    //float widthRatio = 1.0;
    //float heightRatio = 1.0;

    //float screenRatio = 1.0;

    //-------------
    //View gameView(FloatRect(0, 0, 1750.f, 2000.f));
    //View gameView(FloatRect(0, 0, 500.f, 200.f));
    //gameView.setSize(1000, 500);
    //gameView.zoom(0.5);
    //gameView.setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    //-------------
    View gameView;//Gameboard Camera View

    float gameView_CameraWidth = 1195;
    float gameView_CameraHeight = 597.5;

    //-------------------------------------------------
    View dice6View;
    View dice20View;

    //dice6View.reset(FloatRect(1195,0,))

    //dice6View.setViewport(FloatRect(0.8f, 0.f, 0.1, 0.1));
    //dice20View.setViewport(FloatRect(0.8f, 0.f, 0.1, 0.1));
    
    int dice6Roll = rand() % 6 + 1;
    int dice20Roll = rand() % 20 + 1;
    //-------------------------------------------------

    //gameView.reset(FloatRect(0.f, 0.f, gameView_CameraWidth, gameView_CameraHeight));
    //gameView.setCenter(597.5, 1250);
    //window.setView(View(gameView));

    sf::Vector2i pixelPos; //Initializes mouse position tracker
    // = sf::Mouse::getPosition(window);

    sf::Vector2f worldPos; //Initializes mouse to world position converter
    // = window.mapPixelToCoords(pixelPos);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Closing Window (either with the "X" in Top Right or with the "ESC" key)
            if (event.type == Event::Closed || event.key.code == Keyboard::Escape) {
                window.close();
            }

            //Window Resized -> Intended to be played in Full Screen for Now
            if (event.type == Event::Resized) {
                //gameView.reset(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height));
                //sf::FloatRect gameView(0.f, 0.f, event.size.width, event.size.height);
                //window.setView(sf::View(gameView)); //For View
                
                
                gameView.reset(FloatRect(0.f, 0.f, gameView_CameraWidth + 200, gameView_CameraHeight));
                gameView.setCenter(597.5 + 100, 1250);
                window.setView(View(gameView));
            }

            //Temporary
        /*    if (event.type == sf::Event::MouseButtonPressed && worldPos.x < 500 && worldPos.y < 500) {//mouse.getPosition().x < 500 && mouse.getPosition().y < 500) { //Temporary
                gameView.setCenter(773,1207);
                //gameView.zoom(0.25f);
                window.setView(View(gameView));
            } */

            //Screen Movement Input with Arrow Keys from User
            if (event.type == Event::KeyPressed) {
                if (gameView.getCenter().y - gameView_CameraHeight/2 > 50 && (event.key.code == Keyboard::Up || event.key.code == Keyboard::PageUp)) { //Up Pressed
                    //gameView.getCenter().y - gameView_CameraHeight/2 > 0;
                    gameView.move(0, -50);
                    window.setView(View(gameView));
                    //mySprite2.setPosition(1195, gameView.getCenter().y - gameView_CameraHeight/2); //Temporary
                }

                if (gameView.getCenter().y + gameView_CameraHeight/2 < 1950 && (event.key.code == Keyboard::Down || event.key.code == Keyboard::PageDown)) { //Down Pressed
                    gameView.move(0, 50);
                    window.setView(View(gameView));
                    //mySprite2.setPosition(1195, gameView.getCenter().y - gameView_CameraHeight/2); //Temporary
                }
                
            }
            //Temporary Sprite Value here but concept can be used so that the dice [both 6 and 20 sided ones] and 'Dr. Grieco Has the POWER!!!' icons can "follow" the "view/camera" wherever it is moved to -> Dice and Power should be accessed using mousePosition unlike the rest of the game[players, spaces, etc.] which instead should use worldPos 
            mySprite2.setPosition(1195, gameView.getCenter().y - gameView_CameraHeight/2);

            //cout << gameView.getSize().y << endl;
            /*if (event.type == Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (event.mouseWheelScroll.y > 0) {
                        cout << "User Scrolled Up - " << event.mouseWheelScroll.y << endl;
                    }
                    if (event.mouseWheelScroll.y < 0) {
                        cout << "User Scrolled Down - " << event.mouseWheelScroll.y << endl;
                    }
                }
               
            } */

        }
        pixelPos = sf::Mouse::getPosition(window); //Gets current mouse position in window
        worldPos = window.mapPixelToCoords(pixelPos); //Converts mouse position to world coordinates
        
        //window.clear(sf::Color(255, 255, 255)); // Background Color: White
        
        //View gameView(FloatRect(0, 0, 175.f, 200.f));
        //window.setView(gameView);

        window.clear(sf::Color(0, 0, 0)); //Background Color: Black

        window.draw(backgroundSprite);

        //window.draw(myCircle); //Temporary
        
        //Temporary
        if (mouse.getPosition(window).x < 500) {
            window.draw(mySprite);
        }
            
        window.draw(mySprite2); //Temporary
            
        //Tests to find the approximate center of each of the spaces
        //cout << "Mouse: " << mouse.getPosition(window).x << "," << mouse.getPosition(window).y << endl; //Mouse Position
        cout << "World: " << worldPos.x << "," << worldPos.y << endl; //World Position

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