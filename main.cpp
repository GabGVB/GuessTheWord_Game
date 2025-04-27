#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "tara.cpp"
#include "button.cpp"
int main()
{
    //sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    // sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

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


    std::vector<std::pair<std::string, Tara>> imaginiDeGhicit =
    {
        {"romania.png", tari[0]},
        {"brazilia.png", tari[1]},
        {"australia.png", tari[2]},
        {"grecia.png", tari[3]}
    };

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // inițializează random
    int randomIndex = std::rand() % imaginiDeGhicit.size();

    auto imagineAleasa = imaginiDeGhicit[randomIndex];
    std::string caleImagine = imagineAleasa.first;
    Tara taraCorecta = imagineAleasa.second;

    sf::RenderWindow introWindow(sf::VideoMode({1280,720}), "Ghiceste Locatia!");
    introWindow.setFramerateLimit(60);

    sf::Texture normalTexture,hoverTexture,clickedTexture;

    if (!normalTexture.loadFromFile("normal.png") ||
            !hoverTexture.loadFromFile("hover.png") ||
            !clickedTexture.loadFromFile("clicked.png"))
    {
        std::cerr << "Nu am putut încărca texturile!\n";
        throw std::runtime_error("Eroare texturi buton!");
    }


    sf::Texture introTexture;
    if (!introTexture.loadFromFile(caleImagine)) // aici pui imaginea de ghicit
    {
        std::cout << "Nu am putut încărca imaginea intro!" << std::endl;
        return -1;
    }
    sf::Sprite introSprite(introTexture);

    // Redimensionăm imaginea să încapă în fereastră
    sf::Vector2u textureSize = introTexture.getSize();
    sf::Vector2u windowSize = introWindow.getSize();
    introSprite.setScale(
    {
        (float)windowSize.x / textureSize.x,
        (float)windowSize.y / textureSize.y}

    );

    sf::Font font;
    if (!font.openFromFile("Dosis-Light.ttf")) // ai nevoie de un font, pune "arial.ttf" lângă .exe
    {
        std::cout << "Nu am putut încărca fontul!" << std::endl;
        return -1;
    }
    /*
        sf::Text guessButtonText( font,"Ghiceste", 30);
        guessButtonText.setFillColor(sf::Color::White);
        guessButtonText.setStyle(sf::Text::Bold);
        guessButtonText.setPosition({300, 500}); // poziționează-l frumos în fereastră

        sf::RectangleShape guessButton(sf::Vector2f({200, 50}));
        guessButton.setFillColor(sf::Color::Blue);
        guessButton.setPosition({290, 490}); // puțin mai sus față de text, ca să-l încadreze
    */

    Button guessButton(normalTexture, hoverTexture, clickedTexture, font, "Guess",60,0.4);
    guessButton.setPosition(1000, 600); // unde vrei să fie butonul
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
        //guessButton.update(introWindow);

        introWindow.clear();
        guessButton.update(introWindow);
        introWindow.draw(introSprite);
        guessButton.draw(introWindow);
        //  introWindow.draw(guessButton);
        // introWindow.draw(guessButtonText);
        introWindow.display();
    }

    if (readyToGuess==false)
        return 0; // Dacă utilizatorul închide fereastra, ieșim din joc.



    sf::Texture texture;
    sf::Texture harta_alba;
    if (!texture.loadFromFile("worldmap_colorat.png"))
    {
        std::cout << "Nu am putut încărca harta colorata!" << std::endl;
        return -1;
    }
    if (!harta_alba.loadFromFile("worldmap.png"))
    {
        std::cout << "Nu am putut încărca harta alba!" << std::endl;
        return -1;
    }
    sf::Sprite sprite(texture);
    sf::Sprite harta(harta_alba);
    sf::Vector2u size = texture.getSize();

    sf::RenderWindow window(sf::VideoMode({size.x, size.y}), "Poza cu culori");
    window.setFramerateLimit(60);

    //// Creează o copie a imaginii pentru acces la pixeli
    sf::Image image = texture.copyToImage();
     sf::Image hartaImageGoala = harta_alba.copyToImage();


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            else if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButton->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    //  std::cout << pos.x << ' ' << pos.y << std::endl;

                    sf::Color color = image.getPixel({pos.x, pos.y});
                    /*
                    std::cout << "Ai apasat pe pixelul (" << pos.x << ", " << pos.y << ") cu culoarea ("
                              << (int)color.r << ", "
                              << (int)color.g << ", "
                              << (int)color.b << ")\n";
                    */


                    bool gasit=0;
                    for ( auto& tara : tari)
                    {
                        if (color == tara.getCuloare())
                        {
                            std::cout << "Ai apasat pe tara: " << tara.getNume() << '\n';
                            gasit = true;

                            if (taraCorecta.getNume()==tara.getNume())
                                std::cout << "Raspunsul e corect!" << '\n';
                            else
                                std::cout << "Raspunsul e gresit!" << '\n';

                            harta_alba.loadFromImage(hartaImageGoala);
                            sf::Image hartaImage = harta_alba.copyToImage(); // copie imagine din sprite-ul alb

                            for (unsigned int x = 0; x < size.x; ++x)
                            {
                                for (unsigned int y = 0; y < size.y; ++y)
                                {
                                    sf::Color pixelColor = image.getPixel({x, y}); // pixel din harta colorata
                                    if (pixelColor == tara.getCuloare()) // daca e culoarea tarii selectate
                                    {
                                        hartaImage.setPixel({x, y}, sf::Color::Blue); // coloreaza-l albastru pe harta alba
                                    }
                                }
                            }

                            harta_alba.loadFromImage(hartaImage); // reincarca textura hartii albe din imagine modificata
                            harta.setTexture(harta_alba);

                            break;
                        }



                    }
                    if (!gasit)
                    {
                        std::cout << "Nu exista tara pentru aceasta culoare!\n";
                    }
                }
            }


        }

        window.clear();
        window.draw(harta);
        // window.draw(sprite);
        window.display();
    }

}
