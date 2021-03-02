#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
// For spacing the board and the pieces
#define X 702.0f
#define Y 75.0f
// Spacing between the pieces
#define spacing 51
// Background board color
#define boardColor Color(150,100,45,255)
// Paths to all the files
std::string paths[] {"images\\white-rook.png","images\\white-knight.png","images\\white-bishop.png","images\\white-queen.png","images\\white-king.png","images\\white-pawn.png","images\\black-rook.png","images\\black-knight.png","images\\black-bishop.png","images\\black-queen.png","images\\black-king.png","images\\black-pawn.png"};
// Board image path
#define board_path "images\\board.jpg"
// Heart of the program (Starting poistion and most probably updated after every move)
const int boardLayout[8][8] = {{-1,-2,-3,-4,-5,-3,-2,-1},
                               {-6,-6,-6,-6,-6,-6,-6,-6},
                               {0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0},
                               {6,6,6,6,6,6,6,6},
                               {1,2,3,4,5,3,2,1}};
// Loading the textures in the texture array
Texture pieces_text[12];
// Loading the sprites in the sprite array
Sprite pieces[12];
int main()
{
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
    for(int i = 0 ; i < 12 ; i++)
        pieces[i].setTexture(pieces_text[i]);

    // Main game loop
    while (window.isOpen())
    {
        // Creating an event which will look on all the activities related to the game window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        // Clearing with the board color so that it looks good :)
        window.clear(boardColor);
        // Drawing the chess board
        window.draw(chessBoard);
        // Main drawing loop that should be executed every single frame
        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                if(boardLayout[i][j] != 0) {
                    if(boardLayout[i][j] > 0) {
                        pieces[boardLayout[i][j] - 1].setPosition({X+j*spacing,Y+i*spacing});
                        window.draw(pieces[boardLayout[i][j] - 1]);
                    }
                    else {
                        pieces[std::abs(boardLayout[i][j]) + 5].setPosition({X+j*spacing,Y+i*spacing});
                        window.draw(pieces[std::abs(boardLayout[i][j]) + 5]);
                    }
                }
            }
        }
        // Displaying all the sprites that were drawn on the window
        window.display();
    }

    return 0;
}