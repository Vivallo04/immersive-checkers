#ifndef IMMERSIVE_CHECKERS_GAME_HPP
#define IMMERSIVE_CHECKERS_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.hpp"

//sf::RenderWindow window(sf::VideoMode(1280, 720), "Immersive Checkers");
/*
sf::Sprite backgroundSprite;
sf::Vector2f viewSize(1280, 720);
*/

class Game
{
public:
    // Logic
    float currentTime{};
    float prevTime = 0.0f;
    bool isGameOver = false;

    // Text
    sf::Font headingFont;
    sf::Font scoreFont;
    sf::Text headingText;
    sf::Text scoreText;

    // Audio
    sf::Music bgMusic;

    Game();
    void Init();
    void UpdateInput();
    void Update(float delta);
    void Draw();
    void Reset();
    void HandleControllerInput();

    Board *board = new Board();
};


#endif //IMMERSIVE_CHECKERS_GAME_HPP