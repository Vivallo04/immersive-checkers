#include <SFML/Graphics.hpp>
#include <boost/log/trivial.hpp>
#include "include/Piece.hpp"
#include "include/PlayState.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"

/**
 * @brief Main entry point of the PlayState
 * @return EXIT_SUCCESS
 */
int main()
{
    BOOST_LOG_TRIVIAL(info) << "Starting PlayState";
    sf::ContextSettings settings;
    //settings.antialiasingLevel = 16.0;
    sf::RenderWindow window(sf::VideoMode(600, 600), "Immersive Checkers", sf::Style::Default, settings);
    sf::Event event{};

    Piece redPieces[12];
    Piece whitePieces[12];

    auto *game = new PlayState(whitePieces, redPieces);
    game->Setup(redPieces, whitePieces);

    BOOST_LOG_TRIVIAL(info) << "The PlayState was setup";

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                delete game;
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    game->selected = !game->selected;
                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    if (game->board.highlightedTileY > 0)
                    {
                        game->board.highlightedTileY--;
                    }
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (game->board.highlightedTileY < 7)
                    {
                        game->board.highlightedTileY++;
                    }
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    if (game->board.highlightedTileX > 0)
                    {
                        game->board.highlightedTileX--;
                    }
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    if (game->board.highlightedTileX < 7)
                    {
                        game->board.highlightedTileX++;
                    }
                }
                if (event.key.code == sf::Keyboard::Enter)
                {
                    game->board.HighlightGreen(window,
                                               game->board.highlightedTileX,
                                               game->board.highlightedTileY);
                }
            }
        }

        window.clear();
        game->board.Draw(window);
        game->board.HighlightWithRectangle(window, game->board.highlightedTileX, game->board.highlightedTileY);


        if (game->selectedPiece != nullptr)
        {
            BOOST_LOG_TRIVIAL(info) << "Piece selected at: " << game->selectedPiece->x << ", " << game->selectedPiece->y;
            game->board.HighlightGreen(window, game->selectedPiece->x, game->selectedPiece->y);
        }

        for (int i = 0; i < 12; i++)
        {
            whitePieces[i].Draw(window);
            redPieces[i].Draw(window);
        }

        if (game->selected)
        {
            int x = sf::Mouse::getPosition(window).x / game->board.tileSize;
            int y = sf::Mouse::getPosition(window).y / game->board.tileSize;
            if (game->FindPiece(x, y, redPieces, whitePieces) &&
                (game->FindPiece(x, y, redPieces, whitePieces)->color == sf::Color::Red && game->turn == 1 ||
                 game->FindPiece(x, y, redPieces, whitePieces)->color == sf::Color::White && game->turn == 2))
            {
                if (game->FindPiece(x, y, redPieces, whitePieces) == game->selectedPiece)
                {
                    game->selectedPiece = NULL;
                } else
                {
                    game->selectedPiece = game->FindPiece(x, y, redPieces, whitePieces);
                }
                game->selected = false;
            } else if (game->selectedPiece != NULL &&
                       game->MovePiece(x, y, game->selectedPiece, redPieces, whitePieces, &game->turn))
            {
                game->selected = false;
                game->selectedPiece = NULL;
            }
            game->selected = false;
        }
        for (int i = 0; i < 12; i++)
        {
            if (redPieces[i].y == 0)
            {
                redPieces[i].isKing = true;
            }
            if (whitePieces[i].y == 7)
            {
                whitePieces[i].isKing = true;
            }
        }
        window.display();
    }
    return 0;
}

#pragma clang diagnostic pop