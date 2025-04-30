#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    const int windowWidth = 1200;
    const int windowHeight = 800;


    sf::Image originalImage;
    if (!originalImage.loadFromFile("panorama.png"))
    {
        std::cerr << "Eroare la încărcarea imaginii!\n";
        return -1;
    }

    int originalWidth = originalImage.getSize().x;
    int height = originalImage.getSize().y;

    std::vector<Tara> tari = incarcaTari();
    std::vector<std::pair<std::string, Tara>> imaginiDeGhicit = incarcaImaginiDeGhicit(tari);
    int randomIndex = RandomIndex(imaginiDeGhicit.size());
    auto imagineAleasa = imaginiDeGhicit[randomIndex];

    std::string caleImagine = imagineAleasa.first;
    Tara taraCorecta = imagineAleasa.second;
    taraCorecta=tari[93];

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



    sf::Image extendedImage=introTexture.copyToImage();
    extendedImage.resize({originalWidth + 2 * windowWidth, height});
    extendedImage.copy(originalImage, {0, 0}, sf::IntRect({originalWidth - windowWidth, 0}, { windowWidth, height}));
    extendedImage.copy(originalImage, {windowWidth, 0}, sf::IntRect({0, 0}, {originalWidth, height}));
    extendedImage.copy(originalImage, {windowWidth + originalWidth, 0}, sf::IntRect({0, 0}, {windowWidth, height}));

    sf::Texture extendedTexture;
    extendedTexture.loadFromImage(extendedImage);
    sf::Sprite panoramaSprite(extendedTexture);

    int viewX = windowWidth; // De unde începe privirea pe orizontală
    const int scrollSpeed = 10; // cât de repede ne „rotim”

    sf::Vector2i position(viewX, 0);
    sf::Vector2i size(windowWidth, windowHeight);

    sf::IntRect viewRect(position, size);

    panoramaSprite.setTextureRect(viewRect);



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
    scaleSpriteY(extendedTexture.getSize().y,windowHeight,panoramaSprite);
    spriteCenter(window.getSize(),panoramaSprite);

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

    sf::SoundBuffer bufClick;
    if (!bufClick.loadFromFile("sounds/clickSound.wav"))
        return -1;

    sf::Sound clickSound(bufClick);


    sf::Color ocean(182,220,243);

    bool dragging=false, notPanorama=false;
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
                    clickSound.play();
                    gameState=1;
                    startButton.setClickedFalse();
                }
            }

            else if (gameState==1)
            {
                if (guessButton.Clicked())
                {
                    clickSound.play();
                    gameState=2;
                    guessButton.setClickedFalse();
                }
                else if (seeAgainButton.Clicked())
                {
                    clickSound.play();
                    gameState=1;
                    seeAgainButton.setClickedFalse();
                }
                if (event)
                {
                    MouseInteractions(*event,window,view,dragging,lastMousePos);
                    if (event->is<sf::Event::MouseMoved>())
                    {
                        if (dragging)
                        {
                            int currentMouseX = sf::Mouse::getPosition(window).x;
                            int delta = currentMouseX - lastMousePos.x;

                            viewX -= delta; // scroll invers față de mișcarea mouse-ului (efect de „tragere”)

                            // Actualizezi poziția mouse-ului pentru următorul frame
                            lastMousePos.x = currentMouseX;

                            // Wrap logic, la fel ca pentru taste:
                            if (viewX > originalWidth + windowWidth)
                        viewX = windowWidth;
                            else if (viewX < windowWidth)
                        viewX = originalWidth + windowWidth;
                        }
                    }
                }





            }
            else if (gameState==2)
            {
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
                {

                    if (mouseButton->button == sf::Mouse::Button::Left)
                    {

                        auto mousePosition=sf::Mouse::getPosition(window);

                        if(ButtonPressed(confirmButton.getSprite(),(sf::Vector2f)mousePosition))
                        {
                            clickSound.play();
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
                            clickSound.play();
                            window.setView(window.getDefaultView());
                            gameState=1;
                        }
                        else
                        {
                            sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);

                            sf::Color color = image.getPixel({worldPos.x,worldPos.y});

                            if (color!=ocean)
                            {
                                taraSelectata = cautaTaraDupaCuloare(color, tari);
                                if (taraSelectata!=nullptr)
                                    clickSound.play();
                            }


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
                if(event)
                {
                    MouseInteractions(*event,window,view,dragging,lastMousePos);
                    if (event->is<sf::Event::MouseMoved>())
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

            }
            else if (gameState==3)
            {
                correctAnswer.setString("Raspunsul corect a fost \n"+taraCorecta.getNume());
                if(playAgainButton.Clicked())
                {
                    notPanorama=true;
                    clickSound.play();
                    vieti=3;
                    //changeImage(imaginiDeGhicit,taraCorecta,extendedTexture,panoramaSprite,windowWidth,height);
                    changeImage(imaginiDeGhicit,taraCorecta,extendedTexture,panoramaSprite);
                    viewX = windowWidth;
                    harta_alba.loadFromImage(hartaAlbaGoala);
                    selectedCountryText.setString("Selecteaza o tara!");
                    scaleSpriteRatio(extendedTexture.getSize(),window.getSize(),panoramaSprite);
                    spriteCenter(window.getSize(),panoramaSprite);
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
        if(!notPanorama)
            {viewRect.position.x = viewX;
            panoramaSprite.setTextureRect(viewRect);}

            window.draw(backImg);
            window.draw(panoramaSprite);
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
        window.display();
    }
}
