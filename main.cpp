#include <SFML/Graphics.hpp>
using namespace sf;
#define X 700.0f
#define Y 75.0f
#define gapX 2.0f
#define gapY 52.0f
#define boardColor Color(150,100,45,255)
#define board_path "images\\board.jpg"
#define black_queen_path "images\\black-queen.png"
#define white_queen_path "images\\white-queen.png"
#define black_pawn_path "images\\black-pawn.png"
#define white_pawn_path "images\\white-pawn.png"
#define black_king_path "images\\black-king.png"
#define white_king_path "images\\white-king.png"
#define black_bishop_path "images\\black-bishop.png"
#define white_bishop_path "images\\white-bishop.png"
#define white_rook_path "images\\white-rook.png"
#define black_rook_path "images\\black-rook.png"
#define white_knight_path "images\\white-knight.png"
#define black_knight_path "images\\black-knight.png"
int boardLayout[8][8] = {{-1,-2,-3,-4,-5,-3,-2,-1},
                         {-6,-6,-6,-6,-6,-6,-6,-6},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0},
                         {6,6,6,6,6,6,6,6},
                         {1,2,3,4,5,3,2,1}};
int main()
{
    // Creating a window for containing all the elements
    RenderWindow window(VideoMode(1200, 600), "Chess");

    // Creating a texture and assigning an image to it
    Texture text;
    text.loadFromFile(board_path);
    text.setSmooth(true);

    // Creating a sprite for the board
    Sprite chessBoard;
    chessBoard.setTexture(text);
    chessBoard.setScale(0.4f,0.4f);
    chessBoard.setPosition({700.0f,75.0f});


    // Creating all the sprites
    text.loadFromFile(white_queen_path);
    Sprite whiteQueen;
    whiteQueen.setTexture(text);

    text.loadFromFile(black_queen_path);
    Sprite blackQueen;
    whiteQueen.setTexture(text);

    text.loadFromFile(black_bishop_path);
    Sprite blackBishop;
    blackBishop.setTexture(text);

    text.loadFromFile(white_bishop_path);
    Sprite whiteBishop;
    whiteBishop.setTexture(text);

    text.loadFromFile(black_knight_path);
    Sprite blackKnight;
    blackKnight.setTexture(text);

    text.loadFromFile(white_knight_path);
    Sprite whiteKnight;
    whiteKnight.setTexture(text);

    text.loadFromFile(black_rook_path);
    Sprite blackRook;
    blackRook.setTexture(text);

    text.loadFromFile(white_rook_path);
    Sprite whiteRook;
    whiteRook.setTexture(text);

    text.loadFromFile(black_king_path);
    Sprite blackKing;
    blackKing.setTexture(text);

    text.loadFromFile(white_king_path);
    Sprite whiteKing;
    whiteKing.setTexture(text);

    text.loadFromFile(black_pawn_path);
    Sprite blackPawn;
    blackPawn.setTexture(text);

    text.loadFromFile(white_pawn_path);
    Sprite whitePawn;
    whitePawn.setTexture(text);
    // All sprites created


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
        window.clear(boardColor);
        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                switch (boardLayout[i][j])
                {
                case -6:    window.draw(blackPawn);
                            break;
                case -5:    window.draw(blackKing);
                            break;
                case -4:    window.draw(blackQueen);
                            break;
                case -3:    window.draw(blackBishop);
                            break;
                case -2:    window.draw(blackKnight);
                            break;
                case -1:    window.draw(blackRook);
                            break;
                case 0:
                            break;
                case 1:     window.draw(whiteRook);
                            break;
                case 2:     window.draw(whiteKnight);
                            break;
                case 3:     window.draw(whiteBishop);
                            break;
                case 4:     window.draw(whiteKing);
                            break;
                case 5:     window.draw(whiteQueen);
                            break;
                case 6:     window.draw(whitePawn);
                            break;
                }
            }
        }
        window.draw(chessBoard);
        window.display();
    }

    return 0;
}