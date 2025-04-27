#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Button
{
private:
    sf::Sprite sprite;
    sf::Texture normalTexture;
    sf::Texture hoverTexture;
    sf::Texture clickedTexture;

    sf::Text text;
    sf::Font font;

    bool isHovered = false;
    bool isClicked = false;

public:
    Button(const sf::Texture& normalTexture, const sf::Texture& hoverTexture, const sf::Texture& clickedTexture,
           const sf::Font& font, const std::string& textString, unsigned int charSize=40 , float marime=1)
        :sprite(normalTexture), normalTexture( normalTexture),
         hoverTexture(hoverTexture), clickedTexture(clickedTexture),
         font(font), text(font,textString,charSize)

    {

           text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        sprite.setScale({marime, marime});
    }

    void setPosition(float x, float y)
    {
        sprite.setPosition({x, y});
        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();

    text.setPosition(
        {spriteBounds.position.x + (spriteBounds.size.x / 2.f) - (textBounds.size.x / 2.f),
        spriteBounds.position.y + (spriteBounds.size.y / 2.f) - (textBounds.size.y / 2.f)- textBounds.position.y}
    );
    }

    void update(const sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

        bool mouseOver = sprite.getGlobalBounds().contains(worldPos);

        if (mouseOver)
        {
            // std::cout<<"Trece mouseul";
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sprite.setTexture(clickedTexture);
                isClicked = true;
            }
            else
            {
                sprite.setTexture(hoverTexture);
                isClicked = false;
            }
            isHovered = true;
        }
        else
        {
            //  std::cout<<"Nu trece";
            sprite.setTexture(normalTexture);
            isHovered = false;
            isClicked = false;
        }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
        window.draw(text);
    }

    bool Clicked ()
    {
        return isClicked;
    }

};

/*
private:
    sf::Sprite sprite;
    sf::Texture normalTexture;
    sf::Texture hoverTexture;
    sf::Texture clickedTexture;

    sf::Text text;
    sf::Font font;

    bool isHovered = false;
    bool isClicked = false;

public:
    Button(const sf::Texture& normalTexture, const sf::Texture& hoverTexture, const sf::Texture& clickedTexture,
           const sf::Font& font, const std::string& textString, unsigned int charSize = 20)
        :sprite(normalTexture), normalTexture( normalTexture),
         hoverTexture(hoverTexture), clickedTexture(clickedTexture),
         font(font), text(font,textString,charSize)

    {

           text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        sprite.setScale({0.5f, 0.5f});
    }
*/
