#ifndef IMMERSIVE_CHECKERS_BOARD_HPP
#define IMMERSIVE_CHECKERS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <boost/timer/timer.hpp>

class Board
{
public:
    int highlightedTileX = 0;
    int highlightedTileY = 0;

    ~Board();
    void HandleEvents(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
    void HighlightGreen(sf::RenderWindow& window, int x, int y) const;
    void HighlightWithRectangle(sf::RenderWindow& window, int x, int y) const;
    [[maybe_unused]] void MoveHighlightWithArrowKeys();
    [[maybe_unused]] void CheckForJump();
    [[maybe_unused]] void CheckForWin();
    void HighlightJumpableTiles(int x, int y);

    int tileSize = 75;
private:
    sf::RenderWindow *gameWindow{};
    int size = 8;
    int** board = new int*[size];
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP