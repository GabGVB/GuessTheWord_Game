#ifndef TARA_CPP
#define TARA_CPP

#include <SFML/Graphics.hpp>
#include <string>

class Tara
{
public:
    Tara(const std::string& nume, const sf::Color& culoare)
        : nume(nume), culoare(culoare)
    {
    }

    const std::string& getNume() const { return nume; }
    const sf::Color& getCuloare() const { return culoare; }

private:
    std::string nume;
    sf::Color culoare;
};

#endif // TARA_HPP

