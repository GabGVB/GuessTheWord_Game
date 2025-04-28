#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "tara.cpp"
#include "button.cpp"

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



