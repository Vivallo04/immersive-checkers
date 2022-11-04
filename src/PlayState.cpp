#include "../include/PlayState.hpp"
#include "../src/util.hpp"
#include <SFML/Graphics.hpp>

PlayState::PlayState(Piece *whitePieces, Piece *redPieces)
{
    for (int i = 0;i < 12;i++)
    {
        whitePieces[i].color = sf::Color::White;
        redPieces[i].color = sf::Color::Red;
    }
    Init();
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
    bgMusic.play();
}

void PlayState::Update(float delta)
{

}

void PlayState::SetView()
{
    sf::Vector2f viewSize(1024, 576);
    sf::View view(sf::FloatRect(0, 0, viewSize.x, viewSize.y));

    view.zoom(1.0f);
}

void PlayState::Setup(Piece *redPieces, Piece *whitePieces)
{
    int m = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = (int)!(i%2 & 1);j < 8;j += 2) {
            whitePieces[m].isAlive = true;
            whitePieces[m].x = j;
            whitePieces[m].y = i;
            m++;
        }

    }
    m = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = (int)(i % 2 & 1);j < 8;j += 2) {
            redPieces[m].isAlive = true;
            redPieces[m].x = j;
            redPieces[m].y = 7-i;
            m++;
        }
    }
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

Piece *PlayState::FindPiece(int x, int y, Piece *redPiece, Piece *whitePiece)
{
    for (int i = 0; i < 12; i++)
    {
        if (redPiece[i].x == x && redPiece[i].y == y)
        {
            if (redPiece[i].isAlive)
            {
                return &redPiece[i];
            }
        }
        if (whitePiece[i].x == x && whitePiece[i].y == y)
        {
            if (whitePiece[i].isAlive)
            {
                return &whitePiece[i];
            }
        }
    }
    return nullptr;
}

void PlayState::KillPiece(int x, int y, Piece *redPiece, Piece *whitePiece, int *turn)
{
    FindPiece(x, y, redPiece, whitePiece)->isAlive = false;
    *turn = ((*turn == 1) ? 2 : 1);
    return;
}

int PlayState::MovePiece(int x, int y, Piece *isPiece, Piece *redPieces, Piece *whitePieces, int *turn)
{
    if (isPiece->color == sf::Color::Red || isPiece->color == sf::Color::White && isPiece->isKing)
    {
        if (x == isPiece->x - 1 && isPiece->y - 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                *turn = ((*turn == 1) ? 2 : 1);
                isPiece->x = x;
                isPiece->y = y;
                return 1;
            }
        }
    }

    if (isPiece->x + 1 && y == isPiece->y - 1)
    {
        if (!FindPiece(x, y, redPieces, whitePieces))
        {
            *turn = ((*turn == 1) ? 2 : 1);
            isPiece->x = x;
            isPiece->y = y;
            return 1;
        }
    }

    if (x == isPiece->x - 2 && y == isPiece->y - 2)
    {
        if (!FindPiece(x, y, redPieces, whitePieces) &&
            FindPiece(x + 1, y + 1, redPieces, whitePieces) != nullptr &&
            FindPiece(x + 1, y + 1, redPieces, whitePieces)->color != isPiece->color)
        {
            *turn = ((*turn == 1) ? 2 : 1);
            KillPiece(x + 1, y + 1, redPieces, whitePieces, turn);
            isPiece->x = x;
            isPiece->y = y;
            return 1;
        }
    }

    if (x == isPiece->x + 2 && y == isPiece->y - 2)
    {
        if (!FindPiece(x, y, redPieces, whitePieces) &&
            FindPiece(x - 1, y + 1, redPieces, whitePieces) != nullptr &&
            FindPiece(x - 1, y + 1, redPieces, whitePieces)->color != isPiece->color)
        {
            *turn = ((*turn == 1) ? 2 : 1);
            KillPiece(x - 1, y + 1, redPieces, whitePieces, turn);
            isPiece->x = x;
            isPiece->y = y;
            return 1;
        }
    }

    if (isPiece->color == sf::Color::White || isPiece->color == sf::Color::Red && isPiece->isKing)
    {
        if (x == isPiece->x - 1 && y == isPiece->y + 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                *turn = ((*turn == 1) ? 2 : 1);
                isPiece->x = x;
                isPiece->y = y;
                return 1;
            }
        }

        if (x == isPiece->x + 1 && y == isPiece->y + 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                *turn = ((*turn == 1) ? 2 : 1);
                isPiece->x = x;
                isPiece->y = y;
                return 1;
            }
        }

        if (x == isPiece->x - 2 && y == isPiece->y + 2)
        {
            if (!FindPiece(x, y, redPieces, whitePieces) &&
                FindPiece(x + 1, y - 1, redPieces, whitePieces) != nullptr &&
                FindPiece(x + 1, y - 1, redPieces, whitePieces)->color != isPiece->color)
            {
                *turn = ((*turn == 1) ? 2 : 1);
                isPiece->x = x;
                isPiece->y = y;
                KillPiece(x + 1, y - 1, redPieces, whitePieces, turn);
                return 1;
            }
        }

        if (x == isPiece->x + 2 && y == isPiece->y + 2)
        {
            if (!FindPiece(x, y, redPieces, whitePieces) &&
                FindPiece(x - 1, y - 1, redPieces, whitePieces) != nullptr &&
                FindPiece(x - 1, y - 1, redPieces, whitePieces)->color != isPiece->color)
            {
                *turn = ((*turn == 1) ? 2 : 1);
                isPiece->x = x;
                isPiece->y = y;
                KillPiece(x - 1, y - 1, redPieces, whitePieces, turn);
                return 1;
            }
        }
    }
    return 0;
}

int PlayState::CalculateMove(int x, int y, Piece* isPiece, Piece* redPieces, Piece* whitePieces, int *turn)
{
    if (isPiece->color == sf::Color::Red || isPiece->color == sf::Color::White && isPiece->isKing)
    {
        if (x == isPiece->x - 1 && y == isPiece->y - 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                return 1;
            }
        }
        if (x == isPiece->x + 1 && y == isPiece->y - 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                return 1;
            }
        }
        if (x == isPiece->x - 2 && y == isPiece->y - 2)
        {
            if (!FindPiece(x, y, redPieces, whitePieces) &&
                FindPiece(x + 1, y + 1, redPieces, whitePieces) != NULL &&
                FindPiece(x + 1, y + 1, redPieces, whitePieces)->color != isPiece->color)
            {
                return 1;
            }
        }
        if (x == isPiece->x + 2 && y == isPiece->y - 2)
        {
            if (!FindPiece(x, y, redPieces, whitePieces) &&
                FindPiece(x - 1, y + 1, redPieces, whitePieces) != NULL &&
                FindPiece(x - 1, y + 1, redPieces, whitePieces)->color != isPiece->color)
            {
                return 1;
            }
        }
    }
    if (isPiece->color == sf::Color::White || isPiece->color == sf::Color::Red && isPiece->isKing)
    {
        if (x == isPiece->x - 1 && y == isPiece->y + 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                return 1;
            }
        }
        if (x == isPiece->x + 1 && y == isPiece->y + 1)
        {
            if (!FindPiece(x, y, redPieces, whitePieces))
            {
                return 1;
            }
        }
    }
}

