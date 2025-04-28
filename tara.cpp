#ifndef TARA_CPP
#define TARA_CPP

#include <SFML/Graphics.hpp>
#include <string>

class Tara
{


    std::string nume;
    sf::Color culoare;
    public:
    Tara(const std::string& nume, const sf::Color& culoare)
        : nume(nume), culoare(culoare)
    {}
    Tara()=default;
    Tara(const Tara &t)
    {
        nume=t.nume;
        culoare=t.culoare;
    }

    const std::string& getNume() const { return nume; }
    const sf::Color& getCuloare() const { return culoare; }



};


#endif // TARA_HPP

