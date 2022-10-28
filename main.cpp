#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include <boost/log/trivial.hpp>

// TODO: HANDLE EVENTS
//  - Populate the boardMatrix
//  - Resize background
//  - Infinite Scroll
//  - Game logic
//  - Player UI
//  - Score and UX
//  - Arduino Integration
//  - Backtracking Algorithm logic
//  - AI logic
//  - Mouse Controls
//  - Sound Effects
//  - Update Azure
//  - Internal documentation
//  - Update README
//  - Class Diagram

/**
 * @brief Main entry point of the Game
 * @return EXIT_SUCCESS
 */
int main()
{
    BOOST_LOG_TRIVIAL(info) << "Starting Game";
    // SFML Logic
    sf::Event event{};
    sf::Clock clock;

    // Game
    Game* game = new Game();

    BOOST_LOG_TRIVIAL(info) << "The Game is being drawn";
    while (true)
    {
        sf::Time delta = clock.restart();
        while (game -> window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game -> window.close();
                return EXIT_SUCCESS;
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                game -> window.setView(sf::View(visibleArea));
            }
        }

        if (!game -> isGameOver)
            game -> Update(delta.asSeconds());

        game -> window.clear(sf::Color(255, 255, 255, 255));

        game -> Draw(delta.asSeconds());
        game -> window.display();
    }
}