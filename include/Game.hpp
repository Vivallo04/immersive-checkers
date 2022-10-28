#ifndef IMMERSIVE_CHECKERS_GAME_HPP
#define IMMERSIVE_CHECKERS_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Board.hpp"
#include "Piece.hpp"


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

    // Textures
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::RenderWindow window;

    Board* board = new Board(window);

    Game();
    void UpdateInput();
    void Update(float delta);
    void Draw(float delta);
    void Reset();
    void HandleControllerInput();
private:
    void Init();
    void SetView();
    void DrawBackground(float delta);
};


#endif //IMMERSIVE_CHECKERS_GAME_HPP