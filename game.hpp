#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tara.cpp"
#include "button.cpp"
#include "Geoguessr.hpp"


void MouseInteractions(const sf::Event& event, sf::RenderWindow& window, sf::View& view, bool &dragging, sf::Vector2i &lastMousePos)
{
    if (const auto* scroll = event.getIf<sf::Event::MouseWheelScrolled>())
    {
        if (scroll->wheel == sf::Mouse::Wheel::Vertical)
        {
            float zoomFactor = (scroll->delta > 0) ? 0.9f : 1.1f;
            zoomViewAt(sf::Mouse::getPosition(window), window, view, zoomFactor);
        }
    }
    else if (const auto* mouseButton = event.getIf<sf::Event::MouseButtonPressed>())
    {

        if (mouseButton->button == sf::Mouse::Button::Right)
        {
            dragging = true;
            lastMousePos = sf::Mouse::getPosition(window);
        }
    }
    else if (event.is<sf::Event::MouseButtonReleased>())
    {

        if (event.getIf<sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Right)
        {
            dragging = false;
        }
    }
    /*

    else if (event.is<sf::Event::MouseMoved>())
    {

        if (dragging)
        {
            sf::Vector2i newMousePos = sf::Mouse::getPosition(window);
            sf::Vector2f delta = window.mapPixelToCoords(lastMousePos, view) - window.mapPixelToCoords(newMousePos, view);
            view.move(delta);
            lastMousePos = newMousePos;
        }
    }
    */
}

Tara* cautaTaraDupaCuloare(const sf::Color& color, std::vector<Tara>& tari)
{
    for (auto& tara : tari)
    {
        if (tara.getCuloare() == color)
        {
            return &tara;
        }
    }
    return nullptr; // nu a gãsit
}

void selecteazaTara(const sf::Vector2u &mapSize,const sf::Image &image, const sf::Color & colorTara, sf ::Image &hartaImage)
{
    sf::Color pixelColor;
    for (unsigned int x = 0; x < mapSize.x; ++x)
    {
        for (unsigned int y = 0; y < mapSize.y; ++y)
        {
            pixelColor = image.getPixel({x, y}); // pixel din harta colorata
            if (pixelColor == colorTara) // daca e culoarea tarii selectate

                hartaImage.setPixel({x, y}, sf::Color::Blue); // coloreaza-l albastru pe harta alba

        }
    }
}



