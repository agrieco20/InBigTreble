/**
 * @author: Anthony Grieco
 * Date: 1/19/2022
 *
 * Description: Designed to simulate the movement of players as they travel around the game board.
 * Intended only for the use of Dr. Stephen Grieco. This program was built for the benefit of his students and to bring his game "In Big Treble" to life.
*/

#include <iostream>
#include "SFML/Graphics.hpp" //SFML Graphics Libraries
#include "SFML/Window/Mouse.hpp" //Mouse Libraries
#include "Space.h" //Designed to store the location of each of the spaces players can land on while playing the game
#include "Player.h" //Designed to store the location of each player as they progress through the game. Player objects tend to communicate directly with the Space objects in order the determine where they need to travel to on the board.
#include <list> //ArrayList Library
#include <array>

#include <ctime>
#include <random>

using namespace sf;
using namespace std;

int main()
{
    //-------------------------------------------------------
    /* Initialization of each Space Object, which are each used by the player objects to determine 
    the cordinates where they need to be placed when the move around the board.
    */
    Space space1(1, 790.f, 1612.f, false);                Space space51(51, 508.f, 582.f, false);
    Space space2(2, 868.f, 1651.f, false);                Space space52(52, 492.f, 648.f, false);
    Space space3(3, 961.f, 1623.f, false);                Space space54(54, 446.f, 758.f, false);
    Space space4(4, 1020.f, 1560.f, false);               Space space55(55, 421.f, 817.f, false);
    Space space5(5, 1029.f, 1490.f, false);               Space space56(56, 402.f, 873.f, false);
    Space space6(6, 1014.f, 1433.f, false);               Space space57(57, 389.f, 927.f, false);
    Space space7(7, 983.f, 1381.f, false);                Space space58(58, 376.f, 982.f, false);
    Space space8(8, 949.f, 1331.f, false);                Space space59(59, 368.f, 1037.f, false);
    Space space9(9, 909.f, 1281.f, false);                Space space60(60, 375.f, 1097.f, false);
    Space space10(10, 876.f, 1234.f, false);/* Also #71 */Space space61(61, 387.f, 1151.f, false);
    Space space11(11, 854.f, 1205.f, false);              Space space62(62, 412.f, 1203.f, false);
    Space space12(12, 832.f, 1177.f, false);              Space space63(63, 443.f, 1247.f, false);
    Space space13(13, 808.f, 1145.f, false);              Space space64(64, 503.f, 1291.f, false);
    Space space14(14, 784.f, 1116.f, false);              Space space65(65, 565.f, 1318.f, false);
    Space space15(15, 763.f, 1087.f, false);              Space space66(66, 623.f, 1327.f, false);
    Space space16(16, 744.f, 1061.f, false);              Space space67(67, 675.f, 1326.f, false);
    Space space17(17, 720.f, 1033.f, false);              Space space68(68, 732.f, 1315.f, false);
    Space space18(18, 695.f, 998.f, false);               Space space69(69, 787.f, 1295.f, false);
    Space space19(19, 646.f, 931.f, false);/* Also #88 */ Space space70(70, 841.f, 1267.f, false);
    Space space20(20, 600.f, 876.f, false);               Space space72(72, 902.f, 1206.f, false);
    Space space21(21, 580.f, 851.f, false);               Space space73(73, 922.f, 1173.f, false);
    Space space22(22, 560.f, 824.f, false);               Space space74(74, 934.f, 1142.f, false);
    Space space23(23, 536.f, 792.f, false);               Space space75(75, 942.f, 1114.f, false);
    Space space24(24, 477.f, 716.f, false);/* Also #53 */ Space space76(76, 947.f, 1085.f, false);
    Space space25(25, 410.f, 629.f, false);               Space space77(77, 945.f, 1053.f, false);
    Space space26(26, 389.f, 603.f, false);               Space space78(78, 937.f, 1024.f, false);
    Space space27(27, 368.f, 571.f, false);               Space space79(79, 924.f, 994.f, false);
    Space space28(28, 349.f, 538.f, false);               Space space80(80, 906.f, 964.f, false);
    Space space29(29, 329.f, 503.f, false);               Space space81(81, 882.f, 935.f, false);
    Space space30(30, 314.f, 469.f, false);               Space space82(82, 849.f, 916.f, false);
    Space space31(31, 305.f, 436.f, false);               Space space83(83, 819.f, 906.f, false);
    Space space32(32, 299.f, 404.f, false);               Space space84(84, 788.f, 895.f, false);
    Space space33(33, 295.f, 369.f, false);               Space space85(85, 752.f, 895.f, false);
    Space space34(34, 295.f, 342.f, false);               Space space86(86, 713.f, 898.f, false);
    Space space35(35, 295.f, 312.f, false);               Space space87(87, 677.f, 912.f, false);
    Space space36(36, 303.f, 282.f, false);               Space space89(89, 614.f, 958.f, false);
    Space space37(37, 313.f, 250.f, false);               Space space90(90, 593.f, 985.f, false);
    Space space38(38, 325.f, 222.f, false);               Space space91(91, 580.f, 1015.f, false);
    Space space39(39, 346.f, 196.f, false);               Space space92(92, 576.f, 1046.f, false);
    Space space40(40, 381.f, 202.f, false);               Space space93(93, 573.f, 1078.f, false);
    Space space41(41, 418.f, 229.f, false);               Space space94(94, 578.f, 1112.f, false);
    Space space42(42, 447.f, 263.f, false);               Space space95(95, 592.f, 1148.f, false);
    Space space43(43, 467.f, 283.f, false);               Space space96(96, 621.f, 1178.f, false);
    Space space44(44, 488.f, 318.f, false);               Space space97(97, 649.f, 1199.f, false);
    Space space45(45, 507.f, 355.f, false);               Space space98(98, 684.f, 1208.f, false);
    Space space46(46, 518.f, 383.f, false);               Space space99(99, 725.f, 1209.f, false);
    Space space47(47, 523.f, 412.f, false);               Space space100(100, 776.f, 1210.f, false); //Final Space
    Space space48(48, 528.f, 441.f, false);
    Space space49(49, 528.f, 479.f, false);
    Space space50(50, 526.f, 531.f, false);

    //Special Duplicate Spaces
    Space space71(71, 876.f, 1234.f, false);/* Also #10 */
    Space space88(88, 646.f, 931.f, false);/* Also #19 */
    Space space53(53, 477.f, 716.f, false);/* Also #24 */

    //Used to quickly spit out all the space named without having to type them all out for array declaration [below]
    /* for (int i = 1; i < 99; i++) {
        cout << "space" << i << ", ";
    }
    cout << endl; */

    //Each Space object is then added to an array so that they can be conveniently accessed to be compared to the player objects
    //Note: Spaces #53, #71, #88 are identical to Spaces #24, #10, #19 on the Gameboard (in that order)
    Space arrayOfSpaces[100]{space1, space2, space3, space4, space5, space6, space7, space8, space9,
        space10, space11, space12, space13, space14, space15, space16, space17, space18, space19, 
        space20, space21, space22, space23, space24, space25, space26, space27, space28, space29, 
        space30, space31, space32, space33, space34, space35, space36, space37, space38, space39, 
        space40, space41, space42, space43, space44, space45, space46, space47, space48, space49, 
        space50, space51, space52, space53, space54, space55, space56, space57, space58, space59, space60, 
        space61, space62, space63, space64, space65, space66, space67, space68, space69, space70, space71,
        space72, space73, space74, space75, space76, space77, space78, space79, space80, space81, 
        space82, space83, space84, space85, space86, space87, space88, space89, space90, space91, space92,
        space93, space94, space95, space96, space97, space98, space99, space100};

    //Checks Size of Array
    //cout << sizeof(arrayOfSpaces) / sizeof(arrayOfSpaces[0]) << endl;
    
    //All Possible Players are Defined Here
    Player Vivaldi("Vivaldi", "ImageFiles/Vivaldi_Edited.png", 1, 320.f, 1749.f);
    Player Mendelssohn("Mendelssohn", "ImageFiles/Mendelssohn_Edited.png", 1, 540.f, 1749.f);
    Player Mozart("Mozart", "ImageFiles/Mozart_Edited.png", 1, 760.f, 1749.f);
    Player Joplin("Joplin", "ImageFiles/Joplin_Edited.png", 1, 980.f, 1749.f);
    
    Player Bach("Bach", "ImageFiles/Bach_Edited.png", 1, 320.f, 1856.f);
    Player Verdi("Verdi", "ImageFiles/Verdi_Edited.png", 1, 540.f, 1856.f); ///aaaa
    Player Beethoven("Beethoven", "ImageFiles/Beethoven_Edited.png", 1, 760.f, 1856.f);
    Player Holst("Holst", "ImageFiles/Holst_Edited.png", 1, 980.f, 1856.f);
    
    //Initiates the texture for each Player Object's Sprite and scales it to the appropriate size corresponding to the gameboard [only needs to be declared once in the code and has no impact on the starting location of each sprite]
    Vivaldi.setSprite();
    Mendelssohn.setSprite();
    Mozart.setSprite();
    Joplin.setSprite();

    Bach.setSprite();
    Verdi.setSprite();
    Beethoven.setSprite();
    Holst.setSprite();
    
    //Verdi.getSprite().setPosition(Verdi.positionX, Verdi.positionY);

     /*
    //-----------
    //Testing array and arraylist declarations

    //Old Array... DO NOT USE THIS DECLARATION -> Player * totalPossiblePlayers[8] = {&Vivaldi, &Mendelssohn, &Mozart, &Joplin, &Bach, &Verdi, &Beethoven, &Holst};
    array <Player *, 8> totalPossiblePlayers = {&Vivaldi, &Mendelssohn, &Mozart, &Joplin, &Bach, &Verdi, &Beethoven, &Holst};

    //Tests to see if the test array is working [it does]
    for (int i = 0; i < totalPossiblePlayers.size(); i++) {
        cout << totalPossiblePlayers[i]->getName() << endl;
    }
    */

    //Successful ArrayList Declaration [ITERATOR WORKS NOW -> See test below]
    list<Player*> listOfPlayers;
    
    //listOfPlayers.push_back(&Vivaldi);
    //listOfPlayers.push_back(&Mendelssohn);
    //listOfPlayers.push_back(&Mozart);
    //listOfPlayers.push_back(&Joplin);
    //listOfPlayers.push_back(&Bach);
    //listOfPlayers.push_back(&Verdi);
    //listOfPlayers.push_back(&Beethoven);
    //listOfPlayers.push_back(&Holst);
    
    list <Player *> :: iterator it;
    it = listOfPlayers.begin();

    //------------- //Tests [WORKS] to see if the arrayList "listOfPlayers" is working by iterating through each of the elements currently being held within it and printing out the names and according "X Positions" where each of the elements are located on the board to the console
    /*for (it = listOfPlayers.begin(); it != listOfPlayers.end(); it++) {
        cout << (*it)->getName() << " " << (*it)->positionX << endl;
    }*/

    //In the final version of the game the iterator will be incremented and reset [see possible code for this task below] without the use of a specific "for loop" because this would cause all the elements to be cycled through every time the program "redraws" the screen (which occurs 60 times every second) and would then be completely useless [iterator will only incremented when specific conditions are met -> search for "Verdi.[blank]" statements throughout the code for those appropriate conditions]

    /*if (it != listOfPlayers.end()){
        it++;
    }
    else{
        it = listOfPlayers.begin();
    } */
    //-------------
    
    //-------------------------------------------------------
    //Circle Test

    //***Window***
    int windowWidth = 1750;//1195;//2384; //temporary value
    int windowHeight = 2000;//3990 - 3990/2; //temporary value
    float myCircleRadius = 200.0; //TEMPORARY
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "In Big Treble");

    View gameView;//Gameboard Camera View

    float gameView_CameraWidth = 1195;
    float gameView_CameraHeight = 597.5;

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

    //***Circle*** //CIRCLE IS TEMPORARY
    sf::CircleShape myCircle(myCircleRadius, 100);
    //myCircle.setFillColor(sf::Color(0, 210, 255)); //Circle Color: Aqua
    myCircle.setFillColor(sf::Color(128, 128, 128)); //Circle Color: Gray

    //myCircle.setPosition((windowWidth) - myCircleRadius -200, (windowHeight / 10) - myCircleRadius); // Center circle

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
    //TEMPORARY

    Texture myImageTexture;
    //myImageTexture.loadFromFile("ImageFiles/Bach_Edited.png");
    myImageTexture.loadFromFile("ImageFiles/Holst_Edited.png");
    
    Sprite mySprite;
    mySprite.setTexture(myImageTexture);
    mySprite.setPosition(0, 0);
    
    /*
    Sprite mySprite2;
    mySprite2.setTexture(myImageTexture);
    //mySprite2.setPosition(1195, 0);
    mySprite2.setScale(0.5, 0.45); //All player sprites will need to be scaled
    */
    //----

    //-------------------------------------------------------
    //Initializes the Background Image, Used as the Gameboard shown in the main game
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("ImageFiles/InBigTrebleGAMEBOARD_2.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(0, 0);
    
    //-------------------------------------------------------
    //Initializes the Game Setup Menu that opens before the main game starts and allows the user to select the number of participating teams and which icons/game pieces they will each use
    Texture playerSelectMenuTexture;
    playerSelectMenuTexture.loadFromFile("ImageFiles/TeamNumberSelect.png");

    Sprite playerSelectMenuSprite;
    playerSelectMenuSprite.setTexture(playerSelectMenuTexture);
    
    playerSelectMenuSprite.setPosition(0,1350);

    //-------------------------------------------------------
    //Initializes the button used in the Game Setup Menu to indicate how many players/teams will be participating in the game
    Texture playerSelectMenu_Buttton_Texture;
    playerSelectMenu_Buttton_Texture.loadFromFile("ImageFiles/TeamNumberSelect_Button.png");

    Sprite playerSelectMenu_Button_Sprite;
    playerSelectMenu_Button_Sprite.setTexture(playerSelectMenu_Buttton_Texture);

    playerSelectMenu_Button_Sprite.setPosition(333, -1464);

    //-------------------------------------------------------
    //Initializes the Background Image, Used as the Gameboard shown in the Secret Menu
    Texture secretMenuTexture;
    secretMenuTexture.loadFromFile("ImageFiles/InBigTrebleGAMEBOARD_2_secretView.png");

    Sprite secretMenuSprite;
    secretMenuSprite.setTexture(secretMenuTexture);

    secretMenuSprite.setPosition(0, 0);
    
    //-------------------------------------------------------
    //Initializes a Black Box used as an underlay/background for the buttons [both Dice and POWER] to be 'placed' on in the mini menu
    RectangleShape buttonBlock;
    buttonBlock.setSize(Vector2f(gameView_CameraWidth, 184)); //680
    buttonBlock.setFillColor(Color(0, 0, 0)); //Black

    //-------------------------------------------------------
    //Initializes the Dice Images, which are clicked on by the User so that they can simulate a dice being rolled when a random number is generated based on which dice is clicked
    //6 Sided Dice
    Texture Dice6_Texture;
    Dice6_Texture.loadFromFile("ImageFiles/Dice_6_Sides.png");
    
    Sprite dice6_Sprite;
    dice6_Sprite.setTexture(Dice6_Texture);
    
    dice6_Sprite.setScale(0.75, 0.75);
    //dice6_Sprite.setPosition(0, 10);
    ///dice6_Sprite.setPosition(10, 0); //X value TEMPORARY and Y value will need to be able to move as the "gameView" changes/is moved by the user with the arrow keys (and eventually with scrolling)

    //------
    //20 Sided Dice
    Texture dice20_Texture;
    dice20_Texture.loadFromFile("ImageFiles/Dice_20_Sides.png");

    Sprite dice20_Sprite;
    dice20_Sprite.setTexture(dice20_Texture);

    dice20_Sprite.setScale(0.5, 0.5);
    //dice20_Sprite.setPosition(5, 180);
    ///dice20_Sprite.setPosition(200, 5);
    
    //-------------------------------------------------------
    //Initializes the "Dr. Grieco has the POWER!!" icon, which when clicked, will allow the user to open the 'backdoor mechanic' [will let them change the locations of the players on the board if a special condition is met or if an error occurs]
    Texture GriecoPower_Texture;
    GriecoPower_Texture.loadFromFile("ImageFiles/GriecoPower.png");
    
    Sprite GriecoPower_Sprite;
    GriecoPower_Sprite.setTexture(GriecoPower_Texture);

    GriecoPower_Sprite.setScale(0.45,0.45);
    
    //-------------------------------------------------------
    //Initializes the "Dr. Grieco lets the POWER Return!!" icon, which when clicked, will allow the user to close the 'backdoor mechanic' and resume the normal game
    Texture GriecoPowerReturn_Texture;
    GriecoPowerReturn_Texture.loadFromFile("ImageFiles/GriecoPower_Return.png");

    Sprite GriecoPowerReturn_Sprite;
    GriecoPowerReturn_Sprite.setTexture(GriecoPowerReturn_Texture);

    //GriecoPower_Sprite.setScale(0.45, 0.45);


    //-------------------------------------------------------
    //Initializes the font type: Calibri
    Font calibriFont;
    calibriFont.loadFromFile("FontFiles/Calibri Regular.ttf");
    
    //-------------------------------------------------------
    //Initializes the text that prompts each team to select an icon/game piece to represent as they travel around the gameboard
    Text playerIconSelectPrompt;
    playerIconSelectPrompt.setFont(calibriFont);
    playerIconSelectPrompt.setCharacterSize(48);
    playerIconSelectPrompt.setStyle(Text::Bold);
    playerIconSelectPrompt.setFillColor(Color(255, 255, 255)); //White Text
    
    //-------------------------------------------------------
    //Initializes the text used to indicate to the user what the dice roll was (removes necessity of reading it from the console script)
    Text diceRoll_Text;
    diceRoll_Text.setFont(calibriFont);
    diceRoll_Text.setCharacterSize(48);
    diceRoll_Text.setStyle(Text::Bold);
    diceRoll_Text.setFillColor(Color(255, 255, 255)); //White Text
    diceRoll_Text.setString("Dice Roll: "); //Reset for when no dice have been thrown yet

    //string bob = "dude";
    //-------------------------------------------------------
    //TEMPORARY: Try to reduce the following section into a method stored in the Player Class Declaration
    //Initializes the text used to indicate what space each of the players are currently on [only active whenever the "Secret Menu" has been opened]
    Text Vivaldi_currSpacePos_Text;
    Vivaldi_currSpacePos_Text.setFont(calibriFont);
    Vivaldi_currSpacePos_Text.setCharacterSize(100);
    Vivaldi_currSpacePos_Text.setStyle(Text::Bold);
    Vivaldi_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Mendelssohn_currSpacePos_Text;
    Mendelssohn_currSpacePos_Text.setFont(calibriFont);
    Mendelssohn_currSpacePos_Text.setCharacterSize(100);
    Mendelssohn_currSpacePos_Text.setStyle(Text::Bold);
    Mendelssohn_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Mozart_currSpacePos_Text;
    Mozart_currSpacePos_Text.setFont(calibriFont);
    Mozart_currSpacePos_Text.setCharacterSize(100);
    Mozart_currSpacePos_Text.setStyle(Text::Bold);
    Mozart_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Joplin_currSpacePos_Text;
    Joplin_currSpacePos_Text.setFont(calibriFont);
    Joplin_currSpacePos_Text.setCharacterSize(100);
    Joplin_currSpacePos_Text.setStyle(Text::Bold);
    Joplin_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Bach_currSpacePos_Text;
    Bach_currSpacePos_Text.setFont(calibriFont);
    Bach_currSpacePos_Text.setCharacterSize(100);
    Bach_currSpacePos_Text.setStyle(Text::Bold);
    Bach_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Verdi_currSpacePos_Text;
    Verdi_currSpacePos_Text.setFont(calibriFont);
    Verdi_currSpacePos_Text.setCharacterSize(100);
    Verdi_currSpacePos_Text.setStyle(Text::Bold);
    Verdi_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Beethoven_currSpacePos_Text;
    Beethoven_currSpacePos_Text.setFont(calibriFont);
    Beethoven_currSpacePos_Text.setCharacterSize(100);
    Beethoven_currSpacePos_Text.setStyle(Text::Bold);
    Beethoven_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White

    Text Holst_currSpacePos_Text;
    Holst_currSpacePos_Text.setFont(calibriFont);
    Holst_currSpacePos_Text.setCharacterSize(100);
    Holst_currSpacePos_Text.setStyle(Text::Bold);
    Holst_currSpacePos_Text.setFillColor(Color(255, 255, 255)); //White
    
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
    
    /*
    View gameView;//Gameboard Camera View

    float gameView_CameraWidth = 1195;
    float gameView_CameraHeight = 597.5;
    */

    //-------------------------------------------------
    View dice6View;
    View dice20View;

    //dice6View.reset(FloatRect(1195,0,))

    //dice6View.setViewport(FloatRect(0.8f, 0.f, 0.1, 0.1));
    //dice20View.setViewport(FloatRect(0.8f, 0.f, 0.1, 0.1));
    
    int diceRoll = 0;
    //int dice20Roll = 0;

    //Depending on whether the user chooses the 6-Sided-Dice ("randDistro6") or the 20-Sided-Dice ("randDistro20"), the value (a true randomly generated number) is assigned to "diceRoll"
    default_random_engine rand(time(0));
    uniform_int_distribution <int>randDistro6(1, 6); //Randomly chooses value between 1 - 6
    //int dice6Roll = rand() % 6 + 1;
    uniform_int_distribution <int>randDistro20(1, 20); //Randomly chooses value between 1 - 20
    //int dice20Roll = rand() % 20 + 1;

    //-------------------------------------------------

    //gameView.reset(FloatRect(0.f, 0.f, gameView_CameraWidth, gameView_CameraHeight));
    //gameView.setCenter(597.5, 1250);
    //window.setView(View(gameView));
    
    //Initializes mouse position tracker
    sf::Vector2i pixelPos;
        // = sf::Mouse::getPosition(window);

    //Initializes mouse to world position converter
    sf::Vector2f worldPos;
        // = window.mapPixelToCoords(pixelPos);

    int rollDifferential = 0; //Records the difference between the space the player is currently on and the space they need to travel to after the dice has been rolled
    bool gameover = false; //When switched to "true" the game is over
    
    bool secretMenuView = false; //When true, the "Secret Menu" is activated so that the user has the POWER to move players/teams around as the desire (ex: if a team plays a treasure card or if the game were to crash the user can place players/teams back where the previously were)
    
    bool playerSelectionComplete = false; //When "true" the menu that allows the user to choose how many teams/players will be competing in the game [along with choosing which icons will represent them on the gameboard] will stop being drawn
    int numberOfPlayersTotal = 9; //This variable is set to decrement every time a player/team chooses an icon to represent them on the gameboard, when it hits zero the "playerSelectionComplete" boolean will be set to true and the actual game will begin [initially set to 9 instead of 0 to prevent an error where the actual game can never start because the "playerSelectionComplete" boolean would be immediately set to true despite there being no selected teams -> The "9" will be overwritten with the actual number of participating teams/players depending on which button the user selects while the according menu is being displayed]
    bool numberOfPlayersSelected = false; //Set to true once the user has selected how many players/teams will be competing, which then allows each team to select which icon/game piece will represent them as they travel around the board
    bool anyPlayerSelected = false; //If any player/team icon has already been selected, the user can no longer change the number of participating players/teams
    int teamNumIncrementor = 1; //Increments the value by one in the text "Team _ Selects:" when teams are picking which icon/game piece will represent them as they travel around the gameboard

    bool vivaldi_Selected = false; //Indicates that "Vivaldi" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool mendelssohn_Selected = false; //Indicates that "Mendelssohn" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool mozart_Selected = false; //Indicates that "Mozart" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool joplin_Selected = false; //Indicates that "Joplin" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool bach_Selected = false; //Indicates that "Bach" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool verdi_Selected = false; //Indicates that "Verdi" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool beethoven_Selected = false; //Indicates that "Beethoven" has already been selected as an icon/game piece and cannot be picked again by another player/team
    bool holst_Selected = false; //Indicates that "Holst" has already been selected as an icon/game piece and cannot be picked again by another player/team

    //ddddddd

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
                
                //---------
                //Testing...(if works, will be able to resize borders without distorting the images...) [https://stackoverflow.com/questions/21363557/resizing-in-sfml-2-0]
                
                // /*
                //Resizes the images/sprites based on window size (when the full implementation works)
                Vector2f targetSize(gameView_CameraWidth, 1000);
                backgroundSprite.setScale(targetSize.x / (backgroundSprite.getLocalBounds().width), targetSize.y / (backgroundSprite.getLocalBounds().height/2));
                secretMenuSprite.setScale(targetSize.x / (secretMenuSprite.getLocalBounds().width), targetSize.y / (secretMenuSprite.getLocalBounds().height/2));

                gameView.reset(FloatRect(0.f, 0.f, gameView_CameraWidth, gameView_CameraHeight));
                
                if (Verdi.positionY < 1650){//TEMPORARY - "Verdi" will be changed to the name of the arrayList storing all the player objects with the current player whose turn it is being the one the view refocuses on whenever the window size is altered/changed
                    gameView.setCenter(gameView_CameraWidth / 2, Verdi.positionY); //TEMPORARY - "Verdi" will be changed to the name of the arrayList storing all the player objects with the current player whose turn it is being the one the view refocuses on whenever the window size is altered/changed
                }
                else {
                    gameView.setCenter(gameView_CameraWidth / 2, 1650);
                }

                window.setView(View(gameView));
                // */
                //---------
                
                //Original Code:
                 /*
                gameView.reset(FloatRect(0.f, 0.f, gameView_CameraWidth + 200, gameView_CameraHeight));
                gameView.setCenter(597.5 + 100, 1250);
                window.setView(View(gameView));
                 */
            }
            
            /*
            //Will not be in final build: Used to determine the center of each of the spaces by sending the approximate center of each space in the world [worldPos] via a mouse click to the console
            if (event.type == sf::Event::MouseButtonPressed) {//}&& worldPos.x < 500 && worldPos.y < 500) {//mouse.getPosition().x < 500 && mouse.getPosition().y < 500) { //Temporary
                cout << rollDifferential << ": " << worldPos.x << "," << worldPos.y << endl;
                rollDifferential++;

                //gameView.setCenter(773,1207);
                //gameView.zoom(0.25f);
                //window.setView(View(gameView));
            } */

            //When either one of the dice is clicked, the result of that random roll is displayed on the screen and is automatically used to move the player's piece around the board
            //In addition, if the "POWER" button is clicked, a secret menu is opened that allows the user to change player positions at their discretion
            if (event.type == Event::MouseButtonPressed && secretMenuView == false && (mouse.getPosition().y < 680) && ((worldPos.x > 20 && worldPos.x <= 190)/* 1-6 Dice */ || (worldPos.x > 213 && worldPos.x < 361) /* 1-20 Dice */ || (worldPos.x > 805 && worldPos.x < 1195)) /* POWER!! */ && gameover != true) {
                
                //If one of the two dice buttons are chosen...
                if ((worldPos.x > 20 && worldPos.x <= 190) || (worldPos.x > 213 && worldPos.x < 361)) {

                    //If 6 Sided Dice Chosen, assign random value between 1 - 6
                    if (worldPos.x > 20 && worldPos.x <= 190) {
                        diceRoll = randDistro6(rand);
                    }

                    //If 20 Sided Dice Chosen, assign random value between 1 - 20
                    else if (worldPos.x > 213 && worldPos.x < 361) {
                        diceRoll = randDistro20(rand);
                    }

                    cout << diceRoll << endl; //TEMPORARY
                    diceRoll_Text.setString("Dice Roll: " + to_string(diceRoll));
                    rollDifferential = Verdi.currentSpaceOccupied + diceRoll; //"Verdi" to be changed to the 'current player arraylist' with apprpriate rotating index depending on whose turn it is

                    //"Verdi" would be replaced with the name of the arrayList and current iterator position in the final version
                    //Moves the pieces around the board
                    if (Verdi.currentSpaceOccupied != rollDifferential && rollDifferential < 101) {
                        arrayOfSpaces[Verdi.currentSpaceOccupied - 1].isOccupied = false;
                        Verdi.positionX = arrayOfSpaces[rollDifferential - 1].getCenterX();
                        Verdi.positionY = arrayOfSpaces[rollDifferential - 1].getCenterY();
                        Verdi.currentSpaceOccupied = arrayOfSpaces[rollDifferential - 1].getSpaceNum();
                        //arrayOfSpaces[rollDifferential - 1].isOccupied = true;
                        
                        //If iterator "it" has reached the end of the alloted spaces in the arraylist structure "listOfPlayers", it will be reset to the beginning of the list
                        if (it != listOfPlayers.end()) {
                            it++;
                        }
                        else {
                            it = listOfPlayers.begin();
                        }
                    }

                    if (Verdi.currentSpaceOccupied == 100) {
                        cout << "Verdi landed on Space 100 and WINS!!!" << endl; //TEMPORARY (prints to the console when the player reaches the end of the game), REPLACEMENT: Prints that Player/Team X won the game
                        gameover = true;
                    }
                }
                //If the "POWER" button is chosen... [Button within this Range: (worldPos.x > 805 && worldPos.x < 1195)]
                else {
                    cout << "POWER!!" << endl; //TEMPORARY (tests to make sure button works)
                    //if (secretMenuView == true) {
                        //secretMenuView = false;
                    //}
                    //else {
                        secretMenuView = true;
                        gameView.zoom(3.375);
                        gameView.setCenter((gameView_CameraWidth / 2) + 1500, (gameView_CameraHeight / 2) + 650);
                        window.setView(View(gameView));

                        //Text for each possible player is updated with its most recent values
                        Vivaldi_currSpacePos_Text.setString(Vivaldi.getName() + "\t\tCurrent Occupied Space: " + to_string(Vivaldi.currentSpaceOccupied));
                        Mendelssohn_currSpacePos_Text.setString(Mendelssohn.getName() + "\t\tCurrent Occupied Space: " + to_string(Mendelssohn.currentSpaceOccupied));
                        Mozart_currSpacePos_Text.setString(Mozart.getName() + "\t\tCurrent Occupied Space: " + to_string(Mozart.currentSpaceOccupied));
                        Joplin_currSpacePos_Text.setString(Joplin.getName() + "\t\tCurrent Occupied Space: " + to_string(Joplin.currentSpaceOccupied));
                        Bach_currSpacePos_Text.setString(Bach.getName() + "\t\tCurrent Occupied Space: " + to_string(Bach.currentSpaceOccupied));
                        Verdi_currSpacePos_Text.setString(Verdi.getName() + "\t\tCurrent Occupied Space: " + to_string(Verdi.currentSpaceOccupied));
                        Beethoven_currSpacePos_Text.setString(Beethoven.getName() + "\t\tCurrent Occupied Space: " + to_string(Beethoven.currentSpaceOccupied));
                        Holst_currSpacePos_Text.setString(Holst.getName() + "\t\tCurrent Occupied Space: " + to_string(Holst.currentSpaceOccupied));
                        
                    //}

                    //Need to implement an introductory game menu [offers way to start the game, open up the rules{PDF file stored in images}<with a back button>, and open the credits<with a back button>]
                    //Working on it - Need to implement a menu that allows the number of players to be chosen by the user and which pieces they going to use while playing the game [appears in-between the introductory menu and the actual game menu]
                        //The actual image for the menu has been implemented, need to be able to take in user input through [worldPos.x and worldPos.y] to select how many players/teams will be participating [that button is then "pressed" by covering it with the "playerSelectMenu_Button_Sprite" and the value for the # of teams that will participate is saved in a int variable that decrements every time a team's icon is selected {that player icon is added to the arraylist "listOfPlayers"} which will eventually make the boolean "playerSelectioComplete" true and stop the "playerSelectMenuSprite" menu from being shown] and then take user input again through [worldPos.x and worldPos.y] to select which icon/game piece will be used to represent that team as they move around the game board [which is added to the arraylist -> see previous {...} comment for further details on how it works]
                    //Done - Need to change from gameView to secretView when the "POWER" button is pressed
                    //Done [as an additional image] - Need to implement numbering for each space (through text) with the attribute assigned to each space that refers to their position on the map (Broad Example [could be implemented through a for loop]: "arrayOfSpaces[i].getSpaceNum();" | Specific Example: "space1.getSpaceNum();")
                    //Working on it [current spaces are updated and told to the user, still need to implement a way for the user to update the placement of the actual players still...] - Need to implement the menu that allows player positions to be changed and current order of the players (including who the next player/team is in line) to be changed
                        //Need to implement a "Skip Turn" Button
                    //Done - Need to reimplement both dice and text that tells user what they rolled (but doesn't actually move the player while on the secretView)
                    //Need to add a way so that the order that player's take their turn can be adjusted as deemed fit by the user
                    //Done - Need to implement a return button that changes the view back from secretView to gameView
                    //Working on it - Need to add a way [through the arraylist function that will replace "Verdi.[blank]" everywhere in the program] so that teams can choose their game pieces and the order in which they will take turns rolling the dice to move around the board
                        //Just need to replace "Verdi.[blank]" with "(*it)->" now...
                }
            }

            //If "Power!!" Button Pressed again, regular game is resumed
            if (event.type == sf::Event::MouseButtonPressed && secretMenuView == true && worldPos.y < 410 && (worldPos.x > 1195 && worldPos.x < 2064)) {
                secretMenuView = false;
                diceRoll_Text.setString("Dice Roll: ");

                //Perfect Reset of View when the button is pressed to leave the "Secret Menu" and return to the main game
                gameView.zoom(1/3.375);
                
                if (Verdi.positionY < 1650) {//TEMPORARY - "Verdi" will be changed to the name of the arrayList storing all the player objects with the current player whose turn it is being the one the view refocuses on whenever the window size is altered/changed
                    gameView.setCenter(gameView_CameraWidth / 2, Verdi.positionY); //TEMPORARY - "Verdi" will be changed to the name of the arrayList storing all the player objects with the current player whose turn it is being the one the view refocuses on whenever the window size is altered/changed
                }
                else {
                    gameView.setCenter(gameView_CameraWidth / 2, 1650);
                }

                window.setView(View(gameView));
            }

            //While the Secret Menu is open and one of the dice blocks are pressed, a value is returned but doesn't affect any players' actual position on the game board (just acts like a random number generator)
            if (event.type == Event::MouseButtonPressed && secretMenuView == true && gameover == false) {
                
                //If 6 Sided Dice is Selected, generate random number between 1-6
                if (worldPos.x > 2095 && worldPos.x <= 2275 && worldPos.y > 5 && worldPos.y < 160) {
                    diceRoll = randDistro6(rand);
                    //cout << "6 Sided Dice Clicked" << endl; //Temporary
                }

                //If 20 Sided Dice is Selected, generate random number between 1-20
                if (worldPos.x > 2305 && worldPos.x < 2465 && worldPos.y > 0 && worldPos.y < 170) {
                    diceRoll = randDistro20(rand);
                    //cout << "20 Sided Dice Clicked" << endl; //Temporary
                }
                
                diceRoll_Text.setString("Dice Roll: " + to_string(diceRoll));
            }

            //Logic for Menu that determines how many players/teams will be participating and which icons/game pieces they will have to represent them as they travel around the gameboard
            if (event.type == Event::MouseButtonPressed && playerSelectionComplete == false) {
                
                //User selects how many players/teams will be competing
                if (anyPlayerSelected == false && worldPos.y >= 1463 && worldPos.y <= 1508) {
                    
                    //Button: 1 Team Participating
                    if (worldPos.x > 333 && worldPos.x < 414) {
                        numberOfPlayersTotal = 1;
                        playerSelectMenu_Button_Sprite.setPosition(333, 1464);
                    }

                    //Button: 2 Teams Participating
                    if (worldPos.x > 414 && worldPos.x < 495) {
                        numberOfPlayersTotal = 2;
                        playerSelectMenu_Button_Sprite.setPosition(414, 1464);
                    }

                    //Button: 3 Teams Participating
                    if (worldPos.x > 495 && worldPos.x < 576) {
                        numberOfPlayersTotal = 3;
                        playerSelectMenu_Button_Sprite.setPosition(495, 1464);
                    }

                    //Button: 4 Teams Participating
                    if (worldPos.x > 576 && worldPos.x < 657) {
                        numberOfPlayersTotal = 4;
                        playerSelectMenu_Button_Sprite.setPosition(576, 1464);
                    }

                    //Button: 5 Teams Participating
                    if (worldPos.x > 657 && worldPos.x < 738) {
                        numberOfPlayersTotal = 5;
                        playerSelectMenu_Button_Sprite.setPosition(657, 1464);
                    }
                    
                    //Button: 6 Teams Participating
                    if (worldPos.x > 738 && worldPos.x < 819) {
                        numberOfPlayersTotal = 6;
                        playerSelectMenu_Button_Sprite.setPosition(738, 1464);
                    }

                    //Button: 7 Teams Participating
                    if (worldPos.x > 819 && worldPos.x < 900) {
                        numberOfPlayersTotal = 7;
                        playerSelectMenu_Button_Sprite.setPosition(819, 1464);
                    }

                    //Button: 8 Teams Participating
                    if (worldPos.x > 900 && worldPos.x < 981) {
                        numberOfPlayersTotal = 8;
                        playerSelectMenu_Button_Sprite.setPosition(900, 1464);
                    }
                    numberOfPlayersSelected = true;
                    teamNumIncrementor = 1;
                }

                //User selects which icons/game pieces will represent the different players/teams 
                if (numberOfPlayersSelected == true){
                    if (worldPos.y > 1704 && worldPos.y < 1806) {

                        //Selected Icon/Game Piece: Vivaldi
                        if (vivaldi_Selected == false && worldPos.x > 160 && worldPos.x < 375) {
                            listOfPlayers.push_back(&Vivaldi);
                            vivaldi_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Vivaldi Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Mendelssohn
                        if (mendelssohn_Selected == false && worldPos.x > 381 && worldPos.x < 595) {
                            listOfPlayers.push_back(&Mendelssohn);
                            mendelssohn_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Mendelssohn Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Mozart
                        if (mozart_Selected == false && worldPos.x > 601 && worldPos.x < 816) {
                            listOfPlayers.push_back(&Mozart);
                            mozart_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Mozart Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Joplin
                        if (joplin_Selected == false && worldPos.x > 822 && worldPos.x < 1036) {
                            listOfPlayers.push_back(&Joplin);
                            joplin_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Joplin Selected" << endl; //TEMPORARY
                        }
                        anyPlayerSelected = true;
                    }
                    
                    if (worldPos.y > 1815 && worldPos.y < 1917) {
                        
                        //Selected Icon/Game Piece: Bach
                        if (bach_Selected == false && worldPos.x > 160 && worldPos.x < 375) {
                            listOfPlayers.push_back(&Bach);
                            bach_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Bach Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Verdi
                        if (verdi_Selected == false && worldPos.x > 381 && worldPos.x < 595) {
                            listOfPlayers.push_back(&Verdi);
                            verdi_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Verdi Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Beethoven
                        if (beethoven_Selected == false && worldPos.x > 601 && worldPos.x < 816) {
                            listOfPlayers.push_back(&Beethoven);
                            beethoven_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Beethoven Selected" << endl; //TEMPORARY
                        }

                        //Selected Icon/Game Piece: Holst
                        if (holst_Selected == false && worldPos.x > 822 && worldPos.x < 1036) {
                            listOfPlayers.push_back(&Holst);
                            holst_Selected = true;
                            numberOfPlayersTotal--;
                            teamNumIncrementor++;

                            cout << "Holst Selected" << endl; //TEMPORARY
                        }
                        anyPlayerSelected = true;
                    }

                    playerIconSelectPrompt.setString("Team " + to_string(teamNumIncrementor) + " Selects: ");
                    playerIconSelectPrompt.setPosition(100, 1600);
                }
                
                if (numberOfPlayersTotal == 0) {
                    playerSelectionComplete = true;
                }

            }

            //ddddddd
            
            //Screen Movement Input with Arrow Keys and Mouse Scroll from User (if user input [via arrows and scrolling] does not exceed the values set to "lock" the screen, then the Camera will move to cover a different portion of the screen based on the user's inputs)
            if (event.type == Event::KeyPressed && secretMenuView == false) { //FOLLOWING WILL BE IMPLEMENTED WHEN SCROLLING WORKS: || (event.type == Event::MouseWheelScrolled && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)) {
                
                //"Up Arrow" or "Page Up" Pressed
                if (gameView.getCenter().y - gameView_CameraHeight / 2 > -130/*50*/ && (event.key.code == Keyboard::Up || event.key.code == Keyboard::PageUp)) {
                    //gameView.getCenter().y - gameView_CameraHeight/2 > 0;
                    gameView.move(0, -50);
                    window.setView(View(gameView));
                    //mySprite2.setPosition(1195, gameView.getCenter().y - gameView_CameraHeight/2); //Temporary
                }

                /*
                //User Scrolls Up (Has its own code because the scrolling above was too quick with the previously set parameters but were appropriate with the buttons being pressed)
                if (gameView.getCenter().y - gameView_CameraHeight / 2 > -130 /*50*/ /* && event.mouseWheelScroll.delta > 0) {
                    gameView.move(0, -10);
                    window.setView(View(gameView));
                }
                */

                //"Down Arrow" or "Page Down" Pressed
                if (gameView.getCenter().y + gameView_CameraHeight / 2 < 1950 && (event.key.code == Keyboard::Down || event.key.code == Keyboard::PageDown || event.mouseWheelScroll.delta < 0)) {
                    gameView.move(0, 50);
                    window.setView(View(gameView));
                    //mySprite2.setPosition(1195, gameView.getCenter().y - gameView_CameraHeight/2); //Temporary
                }

                /*
                //User Scrolls Down (Has its own code because the scrolling above was too quick with the previously set parameters but were appropriate with the buttons being pressed)
                if (gameView.getCenter().y - gameView_CameraHeight / 2 > 50 && event.mouseWheelScroll.delta < 0) {
                    gameView.move(0, 10);
                    window.setView(View(gameView));
                }
                */

            }
            
            //Tests if scroll is working
            //cout << gameView.getSize().y << endl;
            /*if (event.type == Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (event.mouseWheelScroll.delta > 0) {
                        cout << "User Scrolled Up - " << event.mouseWheelScroll.delta << endl;
                    }
                    if (event.mouseWheelScroll.delta < 0) {
                        cout << "User Scrolled Down - " << event.mouseWheelScroll.delta << endl;
                    }
                }
            }*/

            //myCircle.setPosition(mouse.getPosition(window).x -200, mouse.getPosition().y -350);
            //Verdi.setSpritePosition(mouse.getPosition().x, mouse.getPosition().y);
        }
        
        //-------------------------------------------------
        pixelPos = sf::Mouse::getPosition(window); //Gets current mouse position in window
        worldPos = window.mapPixelToCoords(pixelPos); //Converts mouse position to world coordinates
        
        //-------------------------------------------------
        //The following commands are what are actually producing the graphics throughout the program
        window.clear(sf::Color(0, 0, 0)); //Background Color: Black
        //window.clear(sf::Color(255, 255, 255)); // Background Color: White

        window.draw(backgroundSprite);

        //Opens [Draws] the "Secret Menu" which is activated by pressing the "POWER!!" Button
        if (secretMenuView == true) {
            window.draw(secretMenuSprite); //Temporary, will also pull up a menu that will allow the player positions to be changed
            
            GriecoPowerReturn_Sprite.setPosition(1195, 0);
            window.draw(GriecoPowerReturn_Sprite);

            //Vivaldi.positionX = ?
            //Vivaldi.positionY = 500
            //window.draw(Vivaldi.getSprite(Vivaldi.positionX, Vivaldi.positionY));
            Vivaldi_currSpacePos_Text.setPosition(1750, 500);
            window.draw(Vivaldi_currSpacePos_Text);
            
            Mendelssohn_currSpacePos_Text.setPosition(1750, 650);
            window.draw(Mendelssohn_currSpacePos_Text);

            Mozart_currSpacePos_Text.setPosition(1750, 800);
            window.draw(Mozart_currSpacePos_Text);

            Joplin_currSpacePos_Text.setPosition(1750, 950);
            window.draw(Joplin_currSpacePos_Text);

            Bach_currSpacePos_Text.setPosition(1750, 1100);
            window.draw(Bach_currSpacePos_Text);

            Verdi_currSpacePos_Text.setPosition(1750, 1250);
            window.draw(Verdi_currSpacePos_Text);

            Beethoven_currSpacePos_Text.setPosition(1750, 1400);
            window.draw(Beethoven_currSpacePos_Text);

            Holst_currSpacePos_Text.setPosition(1750, 1550);
            window.draw(Holst_currSpacePos_Text);
        }

        //window.draw(myCircle); //Temporary
        
        //Temporary
        if (mouse.getPosition(window).x < 500) {
            window.draw(mySprite);
        }
            
        //window.draw(mySprite2); //Temporary

        //Verdi.getSprite().setPosition(windowWidth/2,windowHeight/2);//Verdi.positionX, Verdi.positionY); //aaaa
        //Verdi.setSpritePosition(mouse.getPosition().x, mouse.getPosition().y);
        window.draw(Vivaldi.getSprite(Vivaldi.positionX, Vivaldi.positionY));
        window.draw(Mendelssohn.getSprite(Mendelssohn.positionX, Mendelssohn.positionY));
        window.draw(Mozart.getSprite(Mozart.positionX, Mozart.positionY));
        window.draw(Joplin.getSprite(Joplin.positionX, Joplin.positionY));

        window.draw(Bach.getSprite(Bach.positionX, Bach.positionY));
        window.draw(Verdi.getSprite(Verdi.positionX, Verdi.positionY));
        window.draw(Beethoven.getSprite(Beethoven.positionX, Beethoven.positionY));
        window.draw(Holst.getSprite(Holst.positionX, Holst.positionY));

        if (playerSelectionComplete == false) { //Used to determine when to actually start the game [playerSelectionComplete is initiated after the user selects how many players/teams are playing and will become true after the same number of icons/game pieces have been selected, starting the actual game]
            window.draw(playerSelectMenuSprite);
            window.draw(playerSelectMenu_Button_Sprite);
            window.draw(playerIconSelectPrompt);
        }

        //The Black Box Background along with the Dice and POWER buttons only appear if the Secret Menu is closed and the user places the mouse "above" Pixel y = 680 ("above" referring to how the user sees the program and not how the coordinate grid actually works in programming with graphics)
        if (mouse.getPosition().y < 680 && secretMenuView == false && playerSelectionComplete == true) {
            
            //The dice [both the 6 and 20 sided ones] and 'Dr. Grieco Has the POWER!!!' icons/buttons can now "follow" the gameView camera to wherever it is moved to -> Dice and Power can be accessed using a combination and translation between the Mouse's Position (pixelPos) and the World's Position (worldPos) [see below]
            buttonBlock.setPosition(0, gameView.getCenter().y - gameView_CameraHeight / 2);
            diceRoll_Text.setPosition(400, (gameView.getCenter().y - gameView_CameraHeight / 2) + 55);

            dice6_Sprite.setPosition(10, (gameView.getCenter().y - gameView_CameraHeight / 2) + 5);
            dice20_Sprite.setPosition(200, (gameView.getCenter().y - gameView_CameraHeight / 2));
            GriecoPower_Sprite.setPosition(805, (gameView.getCenter().y - gameView_CameraHeight / 2) + 0);
            
            window.draw(buttonBlock);
            window.draw(diceRoll_Text);

            window.draw(dice6_Sprite);
            window.draw(dice20_Sprite);
            window.draw(GriecoPower_Sprite);
        }

        //Reassigns the locations of the dice if the Secret Menu is Open
        if (secretMenuView == true) {
            diceRoll_Text.setPosition(2095, 200);
            dice6_Sprite.setPosition(2095, 5);
            dice20_Sprite.setPosition(2295, 0);
            
            window.draw(diceRoll_Text);
            window.draw(dice6_Sprite);
            window.draw(dice20_Sprite);
        }

        //Tests to find the approximate center of each of the spaces and other boundaries for things like buttons
        //cout << "Mouse: " << mouse.getPosition(window).x << "," << mouse.getPosition(window).y << endl; //Mouse Position
        //cout << "World: " << worldPos.x << "," << worldPos.y << endl; //World Position

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
        /*if (mouse.getPosition().y < 680) {
            window.draw(diceRoll_Text);
        } */

        window.display();
    }

    cout << "Hello World!" << endl; //Not Permanent
    return 0;
}