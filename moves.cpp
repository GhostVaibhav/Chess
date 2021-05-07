// For determining if the moves are valid or not
#include <iostream>
#include <SFML/Graphics.hpp>
// Flow of calls
// 1. Declare a moves::move classes' object
// 2. Call the init function with specific arguments
// 3. Call display() function
namespace moves {
    // For displaying a square around the valid moves' square
    class sq {
    public:
        sf::RectangleShape square[64];
        int max;
        sq() {
            for(int i = 0 ; i < 64 ; i++) {
                square[i].setSize({spacing,spacing});
                square[i].setFillColor(sf::Color::Transparent);
                square[i].setOutlineColor(sf::Color::Green);
                square[i].setOutlineThickness(1.0f);
            }
            this->max = 0;
        }
        void demo(sf::RenderWindow* window) {
            for(int i = 0 ; i < 8 ; i++)
                for(int j = 0 ; j < 8 ; j++)
                    square[i].setPosition({X+j*spacing,Y+i*spacing});
            for(int i = 0 ; i < 64 ; i++)
                window->draw(square[i]);
        }
        void clear() {
            this->max = 0;
        }
        void display(sf::RenderWindow *window) {
            for(int i = 0 ; i < max ; i++)
                window->draw(square[i]);
        }
    };
    class move {
        // Signifies the type of piece
        char name;
        // Keys for name
        // Q -> Queen
        // K -> King
        // P -> Pawn
        // R -> Rook
        // N -> Knight
        // B -> Bishop
    public:
        int id;
        std::string position;
        void init(int,std::string);
    };
    namespace pawn {
        void valid(move m) {
            int col = m.position[0] - 'a';
            int row = m.position[1] - '0';

        }
    }
    namespace king {
        void valid(move m) {
            
        }
    }
    namespace queen {
        void valid(move m) {
            
        }
    }
    namespace bishop {
        void valid(move m) {
            
        }
    }
    namespace rook {
        void valid(move m) {

        }
    }
    namespace knight {
        void valid(move m) {
            
        }
    }
    void move::init(int id, std::string position) {
        this->id = id;
        this->position = position;
        if((id >= 8 && id <= 15) || (id >= 24 && id <= 31)) {
            this->name = 'P';
            pawn::valid(*this);
        }
        else if(id == 0 || id == 7 || id == 16 || id == 23) {
            this->name = 'R';
            rook::valid(*this);
        }
        else if(id == 1 || id == 6 || id == 17 || id == 22) {
            this->name = 'N';
            knight::valid(*this);
        }
        else if(id == 2 || id == 5 || id == 18 || id == 21) {
            this->name = 'B';
            bishop::valid(*this);
        }
        else if(id == 3 || id == 19) {
            this->name = 'Q';
            queen::valid(*this);
        }
        else if(id == 4 || id == 20) {
            this->name = 'K';
            king::valid(*this);
        }
    }
}