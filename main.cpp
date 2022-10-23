#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow win(sf::VideoMode(1280, 720), "Immersive Checkers");
    sf::Event event{};

    while (true)
    {
        win.clear(sf::Color(0, 200, 0, 255));
        while(win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
                return 0;
            }
        }
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
                return 0;
            }
        }
        win.display();
    }
}