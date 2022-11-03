#include "../include/PlayState.hpp"
#include "../src/util.hpp"
#include <SFML/Graphics.hpp>

PlayState::PlayState(): window(sf::VideoMode(windowWidth, windowHeight, 32), "Immersive Checkers")
{
    Init();
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
}

void PlayState::Init()
{
    BOOST_LOG_TRIVIAL(info) << "Initializing Play State";
    // font
    LoadFont(headingFont, "../assets/fonts/font.ttf");

    // music
    LoadMusic(bgMusic, "../assets/sound/music3.wav");

    // texture
    LoadTexture(backgroundTexture, "../assets/graphics/day_sky.png");
    backgroundTexture.setRepeated(true);

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

void PlayState::Update(float delta)
{

}

void PlayState::SetView()
{
    sf::Vector2f viewSize(1024, 576);
    sf::View view(sf::FloatRect(0, 0, viewSize.x, viewSize.y));

    view.zoom(1.0f);
    window.setView(view);
}


void PlayState::Draw(float delta)
{
    this -> SetView();
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect({200, 200, 1280, 720});
    window.draw(backgroundSprite);
    //DrawBackground(delta);
    board -> Init();
    board -> RenderPieces();
    board -> HandleEvents();

}

void PlayState::DrawBackground(float delta)
{
    int backgroundSpeed = 200;
    if ((backgroundSprite.getPosition().x + backgroundSprite.getScale().x) < -1000)
    {
        backgroundSprite.setPosition((1280), (backgroundSprite.getPosition().y));
    } else
    {

    }
    backgroundSprite.move(-delta * backgroundSpeed, 0);
}