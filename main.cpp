#include <SFML/Graphics.hpp>
#include "include/PlayState.hpp"
#include <boost/log/trivial.hpp>


/**
 * @brief Main entry point of the PlayState
 * @return EXIT_SUCCESS
 */
int main()
{
    BOOST_LOG_TRIVIAL(info) << "Starting PlayState";
    // SFML Logic
    sf::ContextSettings settings;
    sf::Event event{};
    sf::Clock clock;

    // PlayState
    auto* game = new PlayState();
    settings.antialiasingLevel = 16.0;

    BOOST_LOG_TRIVIAL(info) << "The PlayState is being drawn";
    while (true)
    {
        sf::Time delta = clock.restart();
        while (game -> window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game -> window.close();
                delete game;
                return EXIT_SUCCESS;
            }
            if (event.type == sf::Event::Resized)
            {
                // Update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, (float) event.size.width,
                                                                             (float) event.size.height);
                game -> window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    game -> window.close();
                    delete game;
                    return EXIT_SUCCESS;
                }
            }
            if (game -> isGameOver)
            {
                game -> window.close();
                delete game;
                return EXIT_SUCCESS;
            }
        }

        if (!game -> isGameOver)
            game -> Update(delta.asSeconds());

        game -> window.clear(sf::Color(255, 255, 255, 255));

        game -> Draw(delta.asSeconds());
        game -> window.display();
    }
}