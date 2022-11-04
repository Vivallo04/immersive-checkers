#ifndef IMMERSIVE_CHECKERS_BOARD_HPP
#define IMMERSIVE_CHECKERS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <boost/timer/timer.hpp>

class Board
{
public:
    ~Board();

    void HandleEvents();
    void Draw(sf::RenderWindow& window);
    void Highlight(sf::RenderWindow& window, int x, int y) const;
    void HighlightWithRectangle(int x, int y);
    [[maybe_unused]] void MoveHighlightWithArrowKeys();
    [[maybe_unused]] void CheckForJump();
    [[maybe_unused]] void CheckForWin();
    void HighlightJumpableTiles(int x, int y);

private:
    sf::RenderWindow *gameWindow{};
    int size = 8;
    int tileSize = 75;
    int highlightedTileX = 0;
    int highlightedTileY = 0;
    int** board = new int*[size];
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP