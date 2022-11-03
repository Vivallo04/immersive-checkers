#include <SFML/System.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include "boost/log/trivial.hpp"


void LoadFont(sf::Font &font, const std::string &path)
{
    if (!font.loadFromFile(path))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to load font from " << path;
    }
    BOOST_LOG_TRIVIAL(info) << "Loaded font from " << path;
    font.loadFromFile(path);
}

void LoadTexture(sf::Texture &texture, const std::string &path)
{
    if (!texture.loadFromFile(path))
    {
        BOOST_LOG_TRIVIAL(error) << "Error loading texture from " << path;
    }
    BOOST_LOG_TRIVIAL(info) << "Loaded texture from " << path;
    texture.loadFromFile(path);
}

void LoadSoundBuffer(sf::SoundBuffer &soundBuffer, const std::string &path)
{
    if (!soundBuffer.loadFromFile(path))
    {
        BOOST_LOG_TRIVIAL(error) << "Error loading sound buffer from " << path;
    }
    soundBuffer.loadFromFile(path);
    BOOST_LOG_TRIVIAL(info) << "Loaded sound buffer from " << path;

}

void LoadMusic(sf::Music &music, const std::string &path)
{
    if (!music.openFromFile(path))
    {
        BOOST_LOG_TRIVIAL(error) << "Error loading music from " << path;
    }
    music.openFromFile(path);
    BOOST_LOG_TRIVIAL(info) << "Loaded music from " << path;
}

sf::Sprite ResizeTexture(sf::Texture &texture, float width, float height)
{
    sf::Sprite sprite;
    sf::Vector2f targetSize(width, height);

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height
    );
    BOOST_LOG_TRIVIAL(info) << "Resized texture to " << width << "x" << height;
    return sprite;
}