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

    sf::RenderWindow introWindow(sf::VideoMode({1280,720}), "Ghiceste Locatia!");
    introWindow.setFramerateLimit(60);

    sf::Texture normalTexture, hoverTexture, clickedTexture,introTexture;
    sf::Font font;
    incarcaTexture("buttons/normal.png",normalTexture);
    incarcaTexture("buttons/hover.png",hoverTexture);
    incarcaTexture("buttons/clicked.png",clickedTexture);
    incarcaFont("fonts/Dosis-Light.ttf",font);
    incarcaTexture(caleImagine,introTexture);
    sf::Sprite introSprite(introTexture);
    scaleSprite(introTexture.getSize(),introWindow.getSize(),introSprite);
    Button guessButton(normalTexture, hoverTexture, clickedTexture, font, "Open map",60,0.6);
    guessButton.setPosition(950, 600);



    bool readyToGuess = false;


    while (introWindow.isOpen() && !readyToGuess)
    {
        while (const std::optional event = introWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                introWindow.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
            {
                readyToGuess = true;
                introWindow.close();
            }
            else if (guessButton.Clicked())
            {
                readyToGuess = true;
                introWindow.close();
            }
        }

        introWindow.clear();
        guessButton.update(introWindow);
        introWindow.draw(introSprite);
        guessButton.draw(introWindow);
        introWindow.display();
    }

std::cout<<taraCorecta.getNume();

    if (readyToGuess==false)
        return 0;

    sf::Texture texture;
    sf::Texture harta_alba;
    incarcaTexture("worldmap_colorat.png",texture);
    incarcaTexture("worldmap.png",harta_alba);

    sf::Sprite sprite(texture);
    sf::Sprite harta(harta_alba);
    sf::Vector2u mapSize = texture.getSize();


    sf::RenderWindow window(sf::VideoMode({mapSize.x, mapSize.y}), "Harta");
    window.setFramerateLimit(30);

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
                                window.close();
                            }
                            else
                            {
                                std::cout<<"Mai incearca mai ai "<<--vieti<<"vieti\n";
                                selectedCountryText.setString("Gresit!");

                                if(vieti<0)
                                    window.close();
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



        window.clear();

        confirmButton.update(window);
        window.setView(view);
        //  std::cout<<clicked;
        window.draw(harta);


        window.setView(window.getDefaultView());
        window.draw(selectedCountryText);
        confirmButton.draw(window);

        window.setView(view);
      //  if (taraSelectata!=nullptr)
      //      std::cout<<taraSelectata->getNume();
        window.display();
    }
        std::cout<<taraCorecta.getNume();
        if(taraConfirmata.getNume()==taraCorecta.getNume())
            std::cout<<"Raspuns corect";
            else
                std::cout<<"Ai pierdut";
}
