
#include <cmath>
#include <iostream>

const double GRAVITY = 0.000000000066742;

const char *EARTH_NAME = "earth";
// Kilograms.
const double EARTH_MASS = 5.972 * pow(10,24); 
// meters
const double EARTH_RADIUS = 6371000;


class Planet
{
private:
    std::string m_name;
    double m_mass;
    double m_radius;

public:
    Planet(void) {
    }

    Planet(const std::string& name, double mass, double radius)
	:m_name(name), m_mass(mass), m_radius(radius) {
    }

    void setMass(double mass) {
	m_mass = mass;
    }

    void setRadius(double radius) {
	m_radius = radius;
    }

    void setName(const std::string& name) {
	m_name = name;
    }

    double SurfaceArea() {
	return 4*M_PI*pow(m_radius,2);
    }

    double Volume() {
	return 
	    4.0/3.0*M_PI*pow(m_radius,3);
    }

    double Density() {
	return m_mass/Volume();
    }

    double Acceleration() {
	return GRAVITY * m_mass /  pow(m_radius,2);
    }


    void Display(void) {
	std::cout << "Planet Details" << std::endl;
	std::cout << "name: " << m_name << std::endl;
	std::cout << "radius: " << m_radius << std::endl;
	std::cout << "mass: " << m_mass << std::endl;
	std::cout << "surface area: " << SurfaceArea() << std::endl;
	std::cout << "volume: " << Volume() << std::endl;
	std::cout << "acceleration: " << Acceleration() << std::endl;
    }
};

int main(void)
{
    Planet earth(EARTH_NAME, EARTH_MASS, EARTH_RADIUS);
    earth.Display();


    return 0;
}
