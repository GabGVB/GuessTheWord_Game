// geoguessr.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "vector"
#include "tara.cpp"


void drawHearts(std::vector <sf::Sprite> hearts, std::vector <sf::Sprite> noHearts, sf::RenderWindow& window, int vieti)
{
    hearts[0].setPosition({1700,20});
    hearts[1].setPosition({1760,20});
    hearts[2].setPosition({1820,20});

    hearts[0].setScale({0.1,0.1});
    hearts[1].setScale({0.1,0.1});
    hearts[2].setScale({0.1,0.1});

    noHearts[0].setPosition({1700,20});
    noHearts[1].setPosition({1760,20});
    noHearts[2].setPosition({1820,20});

    noHearts[0].setScale({0.1,0.1});
    noHearts[1].setScale({0.1,0.1});
    noHearts[2].setScale({0.1,0.1});

    switch(vieti)
    {
    case 3:
        window.draw(hearts[0]);
        window.draw(hearts[1]);
        window.draw(hearts[2]);
        break;
    case 2:
        window.draw(hearts[0]);
        window.draw(hearts[1]);
        window.draw(noHearts[2]);
        break;
    case 1:
        window.draw(hearts[0]);
        window.draw(noHearts[1]);
        window.draw(noHearts[2]);
        break;
    default:
        window.draw(noHearts[0]);
        window.draw(noHearts[1]);
        window.draw(noHearts[2]);

    };

}
int RandomIndex(int nrImg)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return std::rand() %nrImg;
}

void incarcaTexture (std::string cale, sf::Texture &t)
{

    if (!t.loadFromFile(cale))
    {
        std::cerr << "Nu am putut încãrca texturile!\n";
        throw std::runtime_error("Eroare texturi!");
    }
}
void changeImage(std::vector<std::pair<std::string, Tara>> img, Tara &taraCorecta,sf::Texture &texture, sf::Sprite &s)
{
    int randomIndex = RandomIndex(img.size());
    taraCorecta = img[randomIndex].second;
    incarcaTexture(img[randomIndex].first,texture);
    sf::Sprite newintroSprite(texture);
    s=newintroSprite;
    s.setScale({1,1});
}


bool ButtonPressed (sf::Sprite s, sf::Vector2f mousePos)
{
    return  s.getGlobalBounds().contains(mousePos);
}

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, sf::View& view, float zoomFactor)
{
    const sf::Vector2f beforeCoord = window.mapPixelToCoords(pixel, view);

    view.zoom(zoomFactor);

    const sf::Vector2f afterCoord = window.mapPixelToCoords(pixel, view);
    const sf::Vector2f offset = beforeCoord - afterCoord;
    view.move(offset);
}

void incarcaFont (std::string cale, sf::Font &f)
{
    if (!f.openFromFile(cale))
    {
        std::cerr << "Nu am putut încãrca fonutl!\n";
        throw std::runtime_error("Eroare font!");
    }
}



void scaleSpriteExtend (sf::Vector2u textureSize,sf::Vector2u windowSize, sf::Sprite &s)
{
    s.setScale(
    {
        (float)windowSize.x / textureSize.x,
        (float)windowSize.y / textureSize.y}

    );
}

void scaleSpriteRatio (sf::Vector2u textureSize,sf::Vector2u windowSize, sf::Sprite &s)
{
    unsigned int xSize=windowSize.x;
    unsigned int ySize=windowSize.y;
    float scaleX = xSize / textureSize.x;
    float scaleY = ySize/ textureSize.y;

    float finalScale = std::max(scaleX, scaleY);

    s.setScale({finalScale*0.6,finalScale*0.6});
}
void spriteCenter (sf::Vector2u windowSize, sf::Sprite &s)
{
    sf::FloatRect spriteBounds = s.getLocalBounds();
    s.setOrigin({spriteBounds.size.x / 2.f, spriteBounds.size.y / 2.f});
    s.setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
}

std::vector<std::pair<std::string, Tara>> incarcaImaginiDeGhicit ( std::vector<Tara> tari)
{
    std::vector<std::pair<std::string, Tara>> imagini=
    {
        {"locatii/romania.png", tari[103]},
        {"locatii/brazilia.png", tari[17]},
        {"locatii/australia.png", tari[154]},
        {"locatii/grecia.png", tari[109]}
    };
    return imagini;
}
std::vector<Tara> incarcaTari()
{
    std::vector<Tara> tari =
    {
        Tara("Canada", sf::Color(0, 250, 0)),
        Tara("USA", sf::Color(0, 250, 10)),
        Tara("Mexic", sf::Color(0, 250, 20)),
        Tara("Guatemala", sf::Color(50, 250, 0)),
        Tara("Belize", sf::Color(50, 250, 10)),
        Tara("El Salvador", sf::Color(50, 250, 20)),
        Tara("Honduras", sf::Color(50, 250, 30)),
        Tara("Nicaragua", sf::Color(50, 250, 40)),
        Tara("Costa Rica", sf::Color(50, 250, 50)),
        Tara("Panama", sf::Color(50, 250, 60)),
        Tara("Cuba", sf::Color(50, 250, 70)),
        Tara("Haiti", sf::Color(50, 250, 80)),
        Tara("Republica Dominicana", sf::Color(50, 250, 90)),
        Tara("Colombia", sf::Color(100, 250, 0)),
        Tara("Ecuador", sf::Color(100, 250, 10)),
        Tara("Peru", sf::Color(100, 250, 20)),
        Tara("Venezuela", sf::Color(100, 250, 30)),
        Tara("Brazilia", sf::Color(100, 250, 40)),
        Tara("Guyana", sf::Color(100, 250, 50)),
        Tara("Suriname", sf::Color(100, 250, 60)),
        Tara("Bolivia", sf::Color(100, 250, 70)),
        Tara("Chile", sf::Color(100, 250, 80)),
        Tara("Paraguay", sf::Color(100, 250, 90)),
        Tara("Argentina", sf::Color(100, 250, 100)),
        Tara("Uruguay", sf::Color(100, 250, 110)),
        Tara("Maroc", sf::Color(150, 250, 0)),
        Tara("Algeria", sf::Color(150, 250, 10)),
        Tara("Tunisia", sf::Color(150, 250, 20)),
        Tara("Libia", sf::Color(150, 250, 30)),
        Tara("Egipt", sf::Color(150, 250, 40)),
        Tara("Mauritania", sf::Color(150, 250, 50)),
        Tara("Mali", sf::Color(150, 250, 60)),
        Tara("Niger", sf::Color(150, 250, 70)),
        Tara("Chad", sf::Color(150, 250, 80)),
        Tara("Sudan", sf::Color(150, 250, 90)),
        Tara("Eritreea", sf::Color(150, 250, 100)),
        Tara("Senegal", sf::Color(150, 250, 110)),
        Tara("Guinea Bissau", sf::Color(150, 250, 120)),
        Tara("Guinea", sf::Color(150, 250, 130)),
        Tara("Sierra Leone", sf::Color(150, 250, 140)),
        Tara("Liberia", sf::Color(150, 250, 150)),
        Tara("Coasta de fildes", sf::Color(150, 250, 160)),
        Tara("Burkina Faso", sf::Color(150, 250, 170)),
        Tara("Ghana", sf::Color(150, 250, 180)),
        Tara("Togo", sf::Color(150, 250, 190)),
        Tara("Benin", sf::Color(150, 250, 200)),
        Tara("Nigeria", sf::Color(150, 250, 210)),
        Tara("Cameroon", sf::Color(150, 250, 220)),
        Tara("Africa Centrala", sf::Color(150, 250, 230)),
        Tara("Sudanul de sud", sf::Color(150, 250, 240)),
        Tara("Ethiopia", sf::Color(150, 250, 250)),
        Tara("Djibuti", sf::Color(150, 250, 5)),
        Tara("Somalia", sf::Color(150, 250, 15)),
        Tara("Kenya", sf::Color(150, 250, 25)),
        Tara("Uganda", sf::Color(150, 250, 35)),
        Tara("Congo", sf::Color(150, 250, 45)),
        Tara("Rep. Congo", sf::Color(150, 250, 55)),
        Tara("Gabon", sf::Color(150, 250, 65)),
        Tara("Guinea Ecuatoriala", sf::Color(150, 250, 75)),
        Tara("Angola", sf::Color(150, 250, 85)),
        Tara("Zambia", sf::Color(150, 250, 95)),
        Tara("Tanzania", sf::Color(150, 250, 105)),
        Tara("Rwanda", sf::Color(150, 250, 115)),
        Tara("Burundi", sf::Color(150, 250, 125)),
        Tara("Malawi", sf::Color(150, 250, 135)),
        Tara("Mozambique", sf::Color(150, 250, 145)),
        Tara("Zimbabwe", sf::Color(150, 250, 155)),
        Tara("Botswana", sf::Color(150, 250, 165)),
        Tara("Namibia", sf::Color(150, 250, 175)),
        Tara("Africa de sud", sf::Color(150, 250, 185)),
        Tara("Lesotho", sf::Color(150, 250, 195)),
        Tara("Eswatini", sf::Color(150, 250, 205)),
        Tara("Madagascar", sf::Color(150, 250, 215)),
        Tara("Islanda", sf::Color(200, 250, 0)),
        Tara("Irlanda", sf::Color(200, 250, 10)),
        Tara("UK", sf::Color(200, 250, 20)),
        Tara("Franta", sf::Color(200, 250, 30)),
        Tara("Spania", sf::Color(200, 250, 40)),
        Tara("Portugalia", sf::Color(200, 250, 50)),
        Tara("Belgia", sf::Color(200, 250, 60)),
        Tara("Olanda", sf::Color(200, 250, 70)),
        Tara("Luxemburg", sf::Color(200, 250, 80)),
        Tara("Germania", sf::Color(200, 250, 90)),
        Tara("Elvetia", sf::Color(200, 250, 100)),
        Tara("Italia", sf::Color(200, 250, 110)),
        Tara("Danemarca", sf::Color(200, 250, 120)),
        Tara("Norvegia", sf::Color(200, 250, 130)),
        Tara("Suedia", sf::Color(200, 250, 140)),
        Tara("Finlanda", sf::Color(200, 250, 150)),
        Tara("Estonia", sf::Color(200, 250, 160)),
        Tara("Letonia", sf::Color(200, 250, 170)),
        Tara("Lituania", sf::Color(200, 250, 180)),
        Tara("Polonia", sf::Color(200, 250, 190)),
        Tara("Cehia", sf::Color(200, 250, 200)),
        Tara("Austria", sf::Color(200, 250, 210)),
        Tara("Slovenia", sf::Color(200, 250, 220)),
        Tara("Croatia", sf::Color(200, 250, 230)),
        Tara("Bosnia si Hertz", sf::Color(200, 250, 240)),
        Tara("Ungaria", sf::Color(200, 250, 250)),
        Tara("Slovacia", sf::Color(200, 250, 5)),
        Tara("Ucraina", sf::Color(200, 250, 15)),
        Tara("Belarus", sf::Color(200, 250, 25)),
        Tara("Moldova", sf::Color(200, 250, 35)),
        Tara("Romania", sf::Color(200, 250, 45)),
        Tara("Bulgaria", sf::Color(200, 250, 55)),
        Tara("Serbia", sf::Color(200, 250, 65)),
        Tara("Muntenegru", sf::Color(200, 250, 75)),
        Tara("Albania", sf::Color(200, 250, 85)),
        Tara("Macedonia", sf::Color(200, 250, 95)),
        Tara("Grecia", sf::Color(200, 250, 105)),
        Tara("Rusia", sf::Color(200, 250, 115)),
        Tara("Turcia", sf::Color(200, 250, 125)),
        Tara("Cipru", sf::Color(200, 250, 135)),
        Tara("Kazackstan", sf::Color(250, 250, 0)),
        Tara("Uzbekistan", sf::Color(250, 250, 10)),
        Tara("Turkmenistan", sf::Color(250, 250, 20)),
        Tara("Kirghistan", sf::Color(250, 250, 30)),
        Tara("Tajikistan", sf::Color(250, 250, 40)),
        Tara("Georgia", sf::Color(250, 250, 50)),
        Tara("Armenia", sf::Color(250, 250, 60)),
        Tara("Azerbaijan", sf::Color(250, 250, 70)),
        Tara("Iran", sf::Color(250, 250, 80)),
        Tara("Afganistan", sf::Color(250, 250, 90)),
        Tara("Pakistan", sf::Color(250, 250, 100)),
        Tara("India", sf::Color(250, 250, 110)),
        Tara("Nepal", sf::Color(250, 250, 120)),
        Tara("Bangladesh", sf::Color(250, 250, 130)),
        Tara("Myan Mar", sf::Color(250, 250, 140)),
        Tara("China", sf::Color(250, 250, 150)),
        Tara("Mongolia", sf::Color(250, 250, 160)),
        Tara("Vietnam", sf::Color(250, 250, 170)),
        Tara("Laos", sf::Color(250, 250, 180)),
        Tara("Thailanda", sf::Color(250, 250, 190)),
        Tara("Malaesia", sf::Color(250, 250, 200)),
        Tara("Cambodia", sf::Color(250, 250, 210)),
        Tara("Sri Lanka", sf::Color(250, 250, 220)),
        Tara("Coreea de nord", sf::Color(250, 250, 230)),
        Tara("Coreea de sud", sf::Color(250, 250, 240)),
        Tara("Japonia", sf::Color(250, 250, 5)),
        Tara("Taiwan", sf::Color(250, 250, 15)),
        Tara("Philipine", sf::Color(250, 250, 25)),
        Tara("Indonesia", sf::Color(250, 250, 35)),
        Tara("Iraq", sf::Color(250, 250, 45)),
        Tara("Syria", sf::Color(250, 250, 55)),
        Tara("Israel", sf::Color(250, 250, 65)),
        Tara("Liban", sf::Color(250, 250, 75)),
        Tara("Iordania", sf::Color(250, 250, 85)),
        Tara("Arabia Saudita", sf::Color(250, 250, 95)),
        Tara("Yemen", sf::Color(250, 250, 105)),
        Tara("Oman", sf::Color(250, 250, 115)),
        Tara("EAU", sf::Color(250, 250, 125)),
        Tara("Qatar", sf::Color(250, 250, 135)),
        Tara("Kuwait", sf::Color(250, 250, 145)),
        Tara("Buthan", sf::Color(250, 250, 155)),
        Tara("Australia", sf::Color(75, 250, 0)),
        Tara("Papa noua guinee", sf::Color(75, 250, 10)),
        Tara("Noua Zeelanda", sf::Color(75, 250, 20)),

        Tara("Antartica", sf::Color(150, 150, 150))
    };
    return tari;
}



