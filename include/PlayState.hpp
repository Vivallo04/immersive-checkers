#ifndef IMMERSIVE_CHECKERS_PLAYSTATE_HPP
#define IMMERSIVE_CHECKERS_PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../include/BaseState.hpp"
#include "Board.hpp"
#include "Piece.hpp"


class PlayState: public BaseState
{
public:
    // Window
    int windowWidth = 1280;
    int windowHeight = 720;

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

    // -- Game Objects --
    sf::RenderWindow window;
    Board* board = new Board(window);

    Piece redPieces[12];
    Piece whitePieces[12];
    Piece* selectedPiece = NULL;
    bool selected = false;
    int turn = 1;

    PlayState();
    void Update(float delta) override;
    void Draw(float delta);

private:
    sf::Clock clock;

    // Game Initialization
    void Init() override;
    void SetView();
    void DrawPieces();
    void Play();
    void DrawBackground(float delta);
    void Setup(Piece* redPieces, Piece* whitePiece);
    Piece* FindPiece(int x, int y, Piece* redPiece, Piece* whitePiece);
    void KillPiece(int x, int y, Piece* redPiece, Piece* whitePiece, int *turn);
    int MovePiece(int x, int y, Piece* isPiece, Piece* redPieces, Piece* whitePieces, int *turn);
};


#endif //IMMERSIVE_CHECKERS_PLAYSTATE_HPP