/*
  Definitions of class Button member functions.
*/

#include "../include/Button.hpp"

namespace btn {

sf::RectangleShape Button::button() {
  return button_;
}

sf::Text Button::button_text() {
  return button_text_;
}

} // namespace btn