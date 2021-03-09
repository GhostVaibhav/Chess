#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;
// For spacing the board and the pieces
#define X 702.0f
#define Y 75.0f
// Spacing between the pieces
#define spacing 51.0f
// Background board color
#define boardColor Color(150,100,45,255)
// Paths to all the files
std::string paths[] {"images\\white-rook.png","images\\white-knight.png","images\\white-bishop.png","images\\white-queen.png","images\\white-king.png","images\\white-pawn.png","images\\black-rook.png","images\\black-knight.png","images\\black-bishop.png","images\\black-queen.png","images\\black-king.png","images\\black-pawn.png"};
// Board image path
#define board_path "images\\board.jpg"
// Heart of the program (Starting poistion and most probably updated after every move)
// const int boardLayout[8][8] = {{-1,-2,-3,-4,-5,-3,-2,-1},
//                                {-6,-6,-6,-6,-6,-6,-6,-6},
//                                {0,0,0,0,0,0,0,0},
//                                {0,0,0,0,0,0,0,0},
//                                {0,0,0,0,0,0,0,0},
//                                {0,0,0,0,0,0,0,0},
//                                {6,6,6,6,6,6,6,6},
//                                {1,2,3,4,5,3,2,1}};
const int board[8][8] = {{0,1,2,3,4,5,6,7},
                         {8,9,10,11,12,13,14,15},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {31,30,29,28,27,26,25,24},
                         {16,17,18,19,20,21,22,23}};
// Loading the textures in the texture array
Texture pieces_text[12];
// Loading the sprites in the sprite array
Sprite pieces[32];
void set_position() {
    // Main drawing loop that should be executed every single frame
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            if(board[i][j] != 0 || (i == 0 && j == 0)) {
                pieces[board[i][j]].setPosition({X+j*spacing,Y+i*spacing});
            }
        }
    }
}
int main()
{
    // Font used in the game
    Font game_font;
    game_font.loadFromFile("Fonts/Montserrat-Regular.ttf");
    // Creating a window for containing all the elements
    RenderWindow window(VideoMode(1200, 600), "Chess");
    // Limiting the framerate to 60 to decrease the load from GPU
    window.setFramerateLimit(60);
    
    // Creating a texture and assigning an image to it
    Texture text;
    text.loadFromFile(board_path);
    text.setSmooth(true);

    // Creating a sprite for the board
    Sprite chessBoard;
    chessBoard.setTexture(text);
    chessBoard.setScale(0.4f,0.4f);
    chessBoard.setPosition({700.0f,75.0f});

    // Loading the textures from the files in the "path" array
    for(int i = 0 ; i < 12 ; i++)
        pieces_text[i].loadFromFile(paths[i]);

    // Setting the textures to different spirites
    for(int i = 0 ; i < 32 ; i++) {
        if(i >= 8 && i <= 15)
            pieces[i].setTexture(pieces_text[11]);
        else if(i >= 24 && i <= 31)
            pieces[i].setTexture(pieces_text[5]);
        else if(i == 0 || i == 7)
            pieces[i].setTexture(pieces_text[6]);
        else if(i == 1 || i == 6)
            pieces[i].setTexture(pieces_text[7]);
        else if(i == 2 || i == 5)
            pieces[i].setTexture(pieces_text[8]);
        else if(i == 3)
            pieces[i].setTexture(pieces_text[9]);
        else if(i == 4)
            pieces[i].setTexture(pieces_text[10]);
        else if(i == 16 || i == 23)
            pieces[i].setTexture(pieces_text[0]);
        else if(i == 17 || i == 22)
            pieces[i].setTexture(pieces_text[1]);
        else if(i == 18 || i == 21)
            pieces[i].setTexture(pieces_text[2]);
        else if(i == 19)
            pieces[i].setTexture(pieces_text[3]);
        else
            pieces[i].setTexture(pieces_text[4]);
    }

    bool move = false;
    int n = 0;
    Vector2f oldPos,newPos;
    Vector2f d;
    set_position();

    // Main game loop
    while (window.isOpen())
    {
        // Creating an event which will look on all the activities related to the game window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == Keyboard::Q) {
                    for(int i = 0 ; i < 32 ; i++) {
                        std::cout << pieces[i].getGlobalBounds().left << "," << pieces[i].getGlobalBounds().top << "\n";
                    }
                }
                if (event.key.code == Keyboard::R) {
                    for(int i = 0 ; i < 8 ; i++) {
                        for(int j = 0 ; j < 8 ; j++) {
                            RectangleShape rec({48,48});
                            rec.setPosition({X+j*spacing,Y+i*spacing});
                            rec.setFillColor(Color::Black);
                            window.draw(rec);
                        }
                    }
                }
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left) {
                    if(!move) {
                        for(int i = 0 ; i < 32 ; i++) {
                            if(pieces[i].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition (window).y)) {
                                move = true;
                                n = i;
                                d.x = Mouse::getPosition(window).x - pieces[i].getPosition().x;
                                d.y = Mouse::getPosition(window).y - pieces[i].getPosition().y;
                                oldPos = pieces[n].getPosition();
                            }
                        }
                    }
                    else {
                        move = false;
                        for(int i = 0 ; i < 8 ; i++) {
                            for(int j = 0 ; j < 8 ; j++) {
                                if((Mouse::getPosition(window).x > X+j*spacing && Mouse::getPosition(window).x < X+(j+1)*spacing) && (Mouse::getPosition(window).y > Y+i*spacing && Mouse::getPosition(window).y < Y+(i+1)*spacing)) {
                                    pieces[n].setPosition({X+j*spacing,Y+i*spacing});
                                }
                            }
                        }
                    }
                }
            }
        }
        // Clearing with the board color so that it looks good :)
        window.clear(boardColor);
        // Setting the required text and font for displaying the mouse coordinates for debugging purposes
        Text mouse_coord;
        mouse_coord.setFont(game_font);
        mouse_coord.setCharacterSize(18);
        mouse_coord.setFillColor(Color::Black);
        mouse_coord.setString(std::to_string(Mouse::getPosition(window).x) + "," + std::to_string(Mouse::getPosition(window).y));
        window.draw(mouse_coord);
        // Drawing the chess board
        window.draw(chessBoard);
        // Drawing the pieces on the chess board
        for(int i = 0 ; i < 32 ; i++)
            window.draw(pieces[i]);
        // Displaying all the sprites that were drawn on the window
        window.display();
    }

    return 0;
}