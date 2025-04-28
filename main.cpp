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

    sf::Texture normalTexture, hoverTexture, clickedTexture,introTexture,
    startNormalTexture,startHoverTexture,startClickedTexture,
    closeNormalTexture,closeHoverTexture,closeClickedTexture;

    sf::Font font;
    incarcaTexture("buttons/normal.png",normalTexture);
    incarcaTexture("buttons/hover.png",hoverTexture);
    incarcaTexture("buttons/clicked.png",clickedTexture);
    incarcaTexture("buttons/start_normal.png",startNormalTexture);
    incarcaTexture("buttons/start_hover.png",startHoverTexture);
    incarcaTexture("buttons/start_clicked.png",startClickedTexture);
    incarcaTexture("buttons/closeButonNormal.png",closeNormalTexture);
    incarcaTexture("buttons/closeButonHover.png",closeHoverTexture);
    incarcaTexture("buttons/closeButonClicked.png",closeClickedTexture);
    incarcaFont("fonts/Dosis-Light.ttf",font);
    incarcaTexture(caleImagine,introTexture);
    sf::Sprite introSprite(introTexture);



    std::cout<<taraCorecta.getNume();
    sf::Texture texture,harta_alba,startImg, backPoze,victoryTexture,lostTexture,heartTexture, noheartTexture;
    incarcaTexture("visuals/worldmap_colorat.png",texture);
    incarcaTexture("visuals/worldmap.png",harta_alba);
    incarcaTexture("visuals/startImg.png",startImg);
    incarcaTexture("visuals/backgroundPoze.png",backPoze);
    incarcaTexture("visuals/victorie.png",victoryTexture);
    incarcaTexture("visuals/lost.png",lostTexture);
    incarcaTexture("visuals/heart.png",heartTexture);
    incarcaTexture("visuals/nonheart.png",noheartTexture);

    sf::Sprite sprite(texture);
    sf::Sprite harta(harta_alba);
    sf::Sprite startBackground(startImg);
    sf::Sprite backImg(backPoze);
    sf::Sprite victorySprite(victoryTexture);
    sf::Sprite lostSprire(lostTexture);

    std::vector<sf::Sprite> hearts =
    {
        sf::Sprite(heartTexture),
        sf::Sprite(heartTexture),
        sf::Sprite(heartTexture)
    };

    std::vector<sf::Sprite> noHearts =
    {
        sf::Sprite(noheartTexture),
        sf::Sprite(noheartTexture),
        sf::Sprite(noheartTexture)
    };



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

    sf::Text correctAnswer(font,"",100);
    correctAnswer.setFillColor(sf::Color::White);
    correctAnswer.setPosition({600,450});

    Button confirmButton(normalTexture, hoverTexture, clickedTexture, font, "Confirm!",60,0.6);
    confirmButton.setPosition(1450.f,950.f);

    Button startButton(startNormalTexture, startHoverTexture, startClickedTexture, font, "",0,0.4);
    startButton.setPosition(470, 420);

    Button guessButton(normalTexture, hoverTexture, clickedTexture, font, "Guess",60,0.6);
    guessButton.setPosition(850, 950);

    Button seeAgainButton(normalTexture, hoverTexture, clickedTexture, font, "Back",60,0.6);
    seeAgainButton.setPosition(150, 950);

    Button playAgainButton(normalTexture, hoverTexture, clickedTexture, font, "Play again",80,1);
    playAgainButton.setPosition(700, 800);

    Button closeButton(closeNormalTexture, closeHoverTexture, closeClickedTexture, font, "",0,0.3);
    closeButton.setPosition(1880, 10);




    sf::Color ocean(182,220,243);

    bool dragging=false;
    sf::Vector2i lastMousePos;
    Tara* taraSelectata=nullptr, taraConfirmata;
    int vieti=3, gameState=0;
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
            else if(closeButton.Clicked())
            {
                window.close();
            }


            if (gameState==0)
            {

                if (startButton.Clicked())
                {
                    gameState=1;
                    startButton.setClickedFalse();
                }
            }

            else if (gameState==1)
            {
                if (guessButton.Clicked())
                {
                    gameState=2;
                    guessButton.setClickedFalse();
                }
                else if (seeAgainButton.Clicked())
                {
                    gameState=1;
                    seeAgainButton.setClickedFalse();
                }
            }
            else if (gameState==2)
            {
                if (const auto* scroll = event->getIf<sf::Event::MouseWheelScrolled>())
                {
                    if (scroll->wheel == sf::Mouse::Wheel::Vertical)
                    {
                        float zoomFactor = (scroll->delta > 0) ? 0.9f : 1.1f;
                        zoomViewAt(sf::Mouse::getPosition(window), window, view, zoomFactor);
                    }

                }

                else if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
                {

                    if (mouseButton->button == sf::Mouse::Button::Right)
                    {
                        dragging = true;
                        lastMousePos = sf::Mouse::getPosition(window);
                    }

                    else if (mouseButton->button == sf::Mouse::Button::Left)
                    {

                        auto mousePosition=sf::Mouse::getPosition(window);

                        if(ButtonPressed(confirmButton.getSprite(),(sf::Vector2f)mousePosition))
                        {
                            if (taraSelectata!=nullptr)
                            {

                                taraConfirmata=*taraSelectata;

                                if(taraConfirmata.getNume()==taraCorecta.getNume())
                                    gameState=3;

                                else
                                {
                                    vieti--;
                                    selectedCountryText.setString("Gresit!");
                                    if(vieti==0)
                                        gameState=3;
                                }
                            }
                        }
                        else if (ButtonPressed(seeAgainButton.getSprite(),(sf::Vector2f)mousePosition))
                        {
                            window.setView(window.getDefaultView());
                            gameState=1;
                        }
                        else
                        {
                            sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);

                            sf::Color color = image.getPixel({worldPos.x,worldPos.y});

                            if (color!=ocean)
                                taraSelectata = cautaTaraDupaCuloare(color, tari);
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
                else if (event->is<sf::Event::MouseButtonReleased>())
                {

                    if (event->getIf<sf::Event::MouseButtonReleased>()->button == sf::Mouse::Button::Right)
                    {
                        dragging = false;
                    }
                }
                else if (event->is<sf::Event::MouseMoved>())
                {

                    if (dragging)
                    {
                        sf::Vector2i newMousePos = sf::Mouse::getPosition(window);
                        sf::Vector2f delta = window.mapPixelToCoords(lastMousePos, view) - window.mapPixelToCoords(newMousePos, view);
                        view.move(delta);
                        lastMousePos = newMousePos;
                    }
                }
            }
            else if (gameState==3)
            {
                correctAnswer.setString("Raspunsul corect a fost \n"+taraCorecta.getNume());
                if(playAgainButton.Clicked())
                {

                    vieti=3;
                    changeImage(imaginiDeGhicit,taraCorecta,introTexture,introSprite);
                    harta_alba.loadFromImage(hartaAlbaGoala);
                    selectedCountryText.setString("Selecteaza o tara!");
                    scaleSpriteRatio(introTexture.getSize(),window.getSize(),introSprite);
                    spriteCenter(window.getSize(),introSprite);
                    gameState=1;
                }

            }

        }



        window.clear();

        closeButton.update(window);
        if (gameState==0)
        {
            startButton.update(window);
            window.draw(startBackground);
            closeButton.draw(window);
            startButton.draw(window);

        }
        else if (gameState==1)
        {
            guessButton.update(window);

            window.draw(backImg);
            window.draw(introSprite);
            closeButton.draw(window);
            guessButton.draw(window);
            drawHearts(hearts,noHearts,window,vieti);
        }
        else if (gameState==3)
        {
            window.setView(window.getDefaultView());
            playAgainButton.update(window);



            if(taraConfirmata.getNume()==taraCorecta.getNume())
                window.draw(victorySprite);
            else
                window.draw(lostSprire);
            window.draw(correctAnswer);
            closeButton.draw(window);
            playAgainButton.draw(window);

        }
        else
        {
            confirmButton.update(window);
            seeAgainButton.update(window);
            window.setView(view);
            window.draw(harta);

            window.setView(window.getDefaultView());
            window.draw(selectedCountryText);
            closeButton.draw(window);
            confirmButton.draw(window);
            seeAgainButton.draw(window);
            drawHearts(hearts,noHearts,window,vieti);
            window.setView(view);
        }
      //  window.setView(window.getDefaultView());
       // closeButton.draw(window);
      //  window.setView(view);
        window.display();
    }
}
