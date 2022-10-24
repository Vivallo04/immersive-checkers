#include <SFML/Graphics.hpp>
#include "include/Game.hpp"
#include <boost/log/trivial.hpp>

/**
 * @brief Main entry point of the Game
 * @return EXIT_SUCCESS
 */
int main()
{
    BOOST_LOG_TRIVIAL(info) << "Starting Game";
    // SFML Logic
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Immersive Checkers");
    sf::Event event{};
    sf::Clock clock;

    // Game
    Game* game = new Game();

    while (true)
    {
        sf::Time delta = clock.restart();
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        if (!game -> isGameOver)
            game -> Update(delta.asSeconds());

        window.clear(sf::Color(0, 200, 0, 255));

        // game -> Draw();
        window.display();
    }
}