#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "tara.cpp"
#include "button.cpp"
#include "Geoguessr.hpp"
#include "game.hpp"
int main()
{
    std::vector<Tara> tari = incarcaTari();
    std::vector<std::pair<std::string, Tara>> imaginiDeGhicit = incarcaImaginiDeGhicit(tari);
    int randomIndex = RandomIndex(imaginiDeGhicit.size());
    auto imagineAleasa = imaginiDeGhicit[randomIndex];

    std::string caleImagine = imagineAleasa.first;
    Tara taraCorecta = imagineAleasa.second;
    sf::Texture normalTexture, hoverTexture, clickedTexture,introTexture,startNormalTexture,startHoverTexture,startClickedTexture;
    sf::Font font;
    incarcaTexture("buttons/normal.png",normalTexture);
    incarcaTexture("buttons/hover.png",hoverTexture);
    incarcaTexture("buttons/clicked.png",clickedTexture);
    incarcaTexture("buttons/start_normal.png",startNormalTexture);
    incarcaTexture("buttons/start_hover.png",startHoverTexture);
    incarcaTexture("buttons/start_clicked.png",startClickedTexture);
    incarcaFont("fonts/Dosis-Light.ttf",font);
    incarcaTexture(caleImagine,introTexture);
    sf::Sprite introSprite(introTexture);

    Button startButton(startNormalTexture, startHoverTexture, startClickedTexture, font, "",0,0.4);
    startButton.setPosition(470, 420);

    Button guessButton(normalTexture, hoverTexture, clickedTexture, font, "Open map",60,0.6);
    guessButton.setPosition(600, 50);

    std::cout<<taraCorecta.getNume();
    sf::Texture texture,harta_alba,startImg, backPoze ,victoryTexture,lostTexture;
    incarcaTexture("visuals/worldmap_colorat.png",texture);
    incarcaTexture("visuals/worldmap.png",harta_alba);
    incarcaTexture("visuals/startImg.png",startImg);
    incarcaTexture("visuals/backgroundPoze.png",backPoze);
    incarcaTexture("visuals/victorie.png",victoryTexture);
    incarcaTexture("visuals/lost.png",lostTexture);

    sf::Sprite sprite(texture);
    sf::Sprite harta(harta_alba);
    sf::Sprite startBackground(startImg);
    sf::Sprite backImg(backPoze);
    sf::Sprite victorySprite(victoryTexture);
    sf::Sprite lostSprire(lostTexture);
    sf::Vector2u mapSize = texture.getSize();


    sf::RenderWindow window(sf::VideoMode({mapSize.x, mapSize.y}), "Harta");
    window.setFramerateLimit(60);

    scaleSpriteExtend(startImg.getSize(),window.getSize(),startBackground);
    scaleSpriteExtend(backPoze.getSize(),window.getSize(),backImg);
    scaleSpriteExtend(victoryTexture.getSize(),window.getSize(),victorySprite);
    scaleSpriteExtend(lostTexture.getSize(),window.getSize(),lostSprire);
    scaleSpriteRatio(introTexture.getSize(),window.getSize(),introSprite);
    spriteCenter(window.getSize(),introSprite);


    sf::View view = window.getDefaultView();
    sf::Image image = texture.copyToImage();
    sf::Image hartaAlbaGoala = harta_alba.copyToImage();
    sf::Text selectedCountryText(font,"Selecteaza o tara!",50);
    selectedCountryText.setFillColor(sf::Color::Black);
    selectedCountryText.setPosition({1450.f, 880.f});

    //   sf::Text selectedCountryText(font,"Selecteaza o tara!",50);

    Button confirmButton(normalTexture, hoverTexture, clickedTexture, font, "Confirm!",60,0.6);
    confirmButton.setPosition(1450.f,950.f);

    sf::Color ocean(182,220,243);
    bool dragging=false, answered=false;
    sf::Vector2i lastMousePos;
    Tara* taraSelectata=nullptr;//, *taraConfirmata=nullptr;
    Tara taraConfirmata;
    int vieti=3;
    int gameState=2;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
            {
                window.close();
            }
            else if (const auto* scroll = event->getIf<sf::Event::MouseWheelScrolled>())
            {
                if (scroll->wheel == sf::Mouse::Wheel::Vertical)
                    if(gameState==1)
                    {
                        float zoomFactor = (scroll->delta > 0) ? 0.9f : 1.1f;
                        zoomViewAt(sf::Mouse::getPosition(window), window, view, zoomFactor);
                    }
            }
            else if (startButton.Clicked())
            {
                if(gameState==2)
                    gameState=0;
                startButton.setClickedFalse();
            }
            else if (guessButton.Clicked())
            {
                if (gameState==0)
                    gameState=1;

                guessButton.setClickedFalse();
            }

            else if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if(gameState==1)
                {
                    if (mouseButton->button == sf::Mouse::Button::Right)
                    {
                        dragging = true;
                        lastMousePos = sf::Mouse::getPosition(window);
                    }

                    else if (mouseButton->button == sf::Mouse::Button::Left)
                    {


                        sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        if(confirmButton.getSprite().getGlobalBounds().contains({sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y}))
                        {
                            if (taraSelectata!=nullptr)
                            {

                                taraConfirmata=*taraSelectata;
                                // std::cout<<taraConfirmata.getNume();
                                bool answered=1;
                                if(taraConfirmata.getNume()==taraCorecta.getNume())
                                {
                                    gameState=3;
                                }
                                else
                                {
                                    std::cout<<"Mai incearca mai ai "<<--vieti<<"vieti\n";
                                    selectedCountryText.setString("Gresit!");

                                    if(vieti<0)
                                        gameState=3;
                                }

                            }
                        }
                        else
                        {
                            sf::Color color = image.getPixel({worldPos.x,worldPos.y});

                            if (color!=ocean)
                                taraSelectata = cautaTaraDupaCuloare(color, tari);
                            //std::cout<<taraSelectata->getNume();
                            if (taraSelectata != nullptr)
                            {
                                selectedCountryText.setString("Ai selectat: " + taraSelectata->getNume());
                                harta_alba.loadFromImage(hartaAlbaGoala);
                                sf::Image hartaImage = harta_alba.copyToImage(); // copie imagine din sprite-ul alb
                                selecteazaTara(mapSize,image,taraSelectata->getCuloare(),hartaImage);
                                harta_alba.loadFromImage(hartaImage); // reincarca textura hartii albe din imagine modificata
                                harta.setTexture(harta_alba);

                            }
                        }
                    }
                }


            }
            else if (event->is<sf::Event::MouseButtonReleased>())
            {
                if (gameState==1)
                    if (event->getIf<sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Right)
                    {
                        dragging = false;
                    }
            }
            else if (event->is<sf::Event::MouseMoved>())
            {
                if (gameState==1)
                    if (dragging)
                    {
                        sf::Vector2i newMousePos = sf::Mouse::getPosition(window);
                        sf::Vector2f delta = window.mapPixelToCoords(lastMousePos, view) - window.mapPixelToCoords(newMousePos, view);
                        view.move(delta);
                        lastMousePos = newMousePos;
                    }
            }


        }



        window.clear();
        if (gameState==2)
        {
            startButton.update(window);
            window.draw(startBackground);
            startButton.draw(window);
            window.display();

        }
        else if (gameState==0)
        {
            guessButton.update(window);
            window.draw(backImg);
            window.draw(introSprite);
            guessButton.draw(window);
            window.display();
        }
        else if (gameState==3)
        {
             if(taraConfirmata.getNume()==taraCorecta.getNume())
            window.draw(victorySprite);
            else
                window.draw(lostSprire);

            window.display();
        }
        else
        {
            confirmButton.update(window);
            window.setView(view);
            window.draw(harta);


            window.setView(window.getDefaultView());
            window.draw(selectedCountryText);
            confirmButton.draw(window);

            window.setView(view);
            window.display();
        }
    }
    std::cout<<taraCorecta.getNume();
    if(taraConfirmata.getNume()==taraCorecta.getNume())
        std::cout<<"Raspuns corect";
    else
        std::cout<<"Ai pierdut";
}
