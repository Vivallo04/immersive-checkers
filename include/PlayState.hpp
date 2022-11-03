#ifndef IMMERSIVE_CHECKERS_PLAYSTATE_HPP
#define IMMERSIVE_CHECKERS_PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../include/BaseState.hpp"
#include "Board.hpp"


class PlayState: public BaseState
{
public:
    // Window
    int windowWidth = 1280;
    int windowHeight = 720;

    // Logic
    //float currentTime{};
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

    // -- Game Objects --
    sf::RenderWindow window;
    Board* board = new Board(window);

    PlayState();
    void Update(float delta) override;
    void Draw(float delta);

private:
    sf::Clock clock;
    void Init() override;
    void SetView();
    void DrawBackground(float delta);
};


#endif //IMMERSIVE_CHECKERS_PLAYSTATE_HPP