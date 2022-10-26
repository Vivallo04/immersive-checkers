#include "../include/Game.hpp"
#include "../src/util.hpp"
#include <SFML/Graphics.hpp>

Game::Game(): window(sf::VideoMode(1280, 720, 32), "Immersive Checkers")
{
    Init();
    window.setVerticalSyncEnabled(true);
    sf::Vector2f viewSize(1280, 720);

}

void Game::Init()
{
    // font
    LoadFont(headingFont, "../assets/fonts/font.ttf");

    // music
    LoadMusic(bgMusic, "../assets/sound/music3.wav");

    // texture
    LoadTexture(backgroundTexture, "../assets/graphics/background.png");

    headingText.setFont(headingFont);
    headingText.setString("Immersive Checkers");
    headingText.setCharacterSize(100);
    headingText.setFillColor(sf::Color::White);
    headingText.setPosition(300, 300);

    scoreText.setFont(scoreFont);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(100, 200);

    // play music
    bgMusic.setLoop(true);
    //bgMusic.play();
}

void Game::UpdateInput()
{

}

void Game::Update(float delta)
{

}

void Game::SetView()
{
    sf::Vector2f viewSize(1024, 576);
    sf::View view(sf::FloatRect(0, 0, viewSize.x, viewSize.y));

    view.zoom(1.0f);
    window.setView(view);

}


void Game::Draw(float delta)
{
    this -> SetView();

    backgroundSprite.setTexture(backgroundTexture);
    window.draw(backgroundSprite);
    DrawBackground(delta);
    board -> Init();
}

void Game::Reset()
{
    BOOST_LOG_TRIVIAL(info) << "The game has been reset";
}

void Game::HandleControllerInput()
{

}

void Game::DrawBackground(float delta)
{
    int backgroundSpeed = 400;
    if ((backgroundSprite.getPosition().x + backgroundSprite.getScale().x) < -1000)
    {
        backgroundSprite.setPosition((window.getSize().x), (backgroundSprite.getPosition().y));
    }
    backgroundSprite.move(-delta * backgroundSpeed, 0);
}