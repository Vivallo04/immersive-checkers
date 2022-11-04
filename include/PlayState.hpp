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
    Board board;
    bool selected = false;
    Piece *selectedPiece = nullptr;
    int turn = 1;

    PlayState(Piece *whitePieces, Piece *redPieces);

    void Update(float delta) override;

    void Setup(Piece *redPieces, Piece *whitePieces);

    Piece *FindPiece(int x, int y, Piece *redPiece, Piece *whitePiece);

    void KillPiece(int x, int y, Piece *redPiece, Piece *whitePiece, int *turn);

    int CalculateMove(int x, int y, Piece *isPiece, Piece *redPieces, Piece *whitePieces, int *turn);

    int MovePiece(int x, int y, Piece *isPiece, Piece *redPieces, Piece *whitePieces, int *turn);

private:
    // Game Initialization
    void Init() override;
    void SetView();
    void DrawBackground(float delta);
};

#endif //IMMERSIVE_CHECKERS_PLAYSTATE_HPP