
#include <cmath>
#include <iostream>
#include <vector>

// Newton Gravitational Constant.
// The G constant is in seconds per meter per kilogram.
const double GRAVITY = 0.000000000066742;

//
// Earth was used as a unit test, the results are
// below. 
//
const char *EARTH_NAME = "earth";
// Kilograms.
const double EARTH_MASS = 5.972 * pow(10,24); 
// meters
const double EARTH_RADIUS = 6371000;
// Planet Details
// name: earth
// radius: 6.371e+06
// mass: 5.972e+24
// surface area: 5.10064e+14
// volume: 1.08321e+21
// acceleration: 9.81983

bool validateInput()
{
    bool valid = true;
    if (!std::cin)
    {
	std::cout << "[INVALID INPUT]" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	valid = false;
    }
    return valid;
}

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

    std::string getName(void) {
	return m_name;
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
	std::cout << "Planet Name: " << m_name << std::endl;
	std::cout << "radius: " << m_radius << std::endl;
	std::cout << "mass: " << m_mass << std::endl;
	std::cout << "surface area: " << SurfaceArea() << std::endl;
	std::cout << "volume: " << Volume() << std::endl;
	std::cout << "acceleration: " << Acceleration() << std::endl << std::endl;

    }
};

std::vector<Planet> vPlanets;

void AddPlanet(void)
{
    std::string planetName;
    double planetMass;
    double planetRadius;
    
    do {
	std::cout << "enter planet name: ";
	std::cin >> planetName ;
    } while (!validateInput());

    do {
	std::cout << "enter planet mass: ";
	std::cin >> planetMass ;
    } while (!validateInput());

    do {
	std::cout << "enter planet radius: ";
	std::cin >> planetRadius ;
    } while (!validateInput());
    std::cout << std::endl;

    Planet planet;
    
    planet.setName(planetName);
    planet.setRadius(planetRadius);
    planet.setMass(planetMass);
	
    vPlanets.push_back(planet);
}

void DeletePlanet(void)
{
    std::string name;
    bool bRemoved = false;

    do {
	std::cout << "Delete Planet Name: ";
	std::cin >> name;
    } while(!validateInput());
    
    for(std::vector<Planet>::iterator iter = vPlanets.begin(); iter != vPlanets.end(); ++iter)
    {
	if (iter->getName() == name)
	{
	    vPlanets.erase(iter);
	    bRemoved = true;
	    break;
	}
    }

    if (bRemoved)
	std::cout << "planet: " << name << " removed" << std::endl;
    else
	std::cout << "planet: " << name << " [NOT FOUND]" << std::endl;
}

void FindPlanet(void)
{
    std::string name;
    bool bFound = false;

    do {
	std::cout << "Find Planet Name: ";
	std::cin >> name;
    } while(!validateInput());
	
    for(std::vector<Planet>::iterator iter = vPlanets.begin(); iter != vPlanets.end(); ++iter)
    {
	if (iter->getName() == name)
	{
	    iter->Display();
	    bFound = true;
	    break;
	}
    }

    if (!bFound)
	std::cout << "planet: " << name << " [NOT FOUND]" << std::endl;
}

void ListPlanets(void)
{
    if (!vPlanets.size())
    {
	std::cout << "No planets in list" << std::endl;
	return;
    }

    for(std::vector<Planet>::iterator iter = vPlanets.begin(); iter != vPlanets.end(); ++iter)
    {
	iter->Display();
    }
}

//
// Bubble Sort, iterate the last swapping adjacent elements when
// they are out of order until there is no swap required.
//
void SortPlanets(void)
{
    bool sorted = false;

    if (!vPlanets.size())
    {
	std::cout << "No planets in list" << std::endl;
	return;
    }
    else if (vPlanets.size() < 2)
	return;
    
    while (!sorted)
    {
	sorted = true;
	for (int i = 0; i < vPlanets.size() - 1; i++)
	{
	    if (0<vPlanets[i].getName().compare(vPlanets[i+1].getName()))
	    {
		Planet temp = vPlanets[i];
		vPlanets[i] = vPlanets[i+1];
		vPlanets[i+1] = temp;
		sorted = false;
	    }
	}
    }
}

void menu(void)
{
    std::cout << std::endl;
    std::cout << "1. Add Planet" << std::endl;
    std::cout << "2. Delete Planet" << std::endl;
    std::cout << "3. Find Planet" << std::endl;
    std::cout << "4. List all Planets" << std::endl;
    std::cout << "5. Sort all Planets" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main(void)
{
    int choice;
    do 
    {
	menu();
	do {
	    std::cout << "enter choice: ";
	    std::cin >> choice;
	} while(!validateInput());

	std::cout << std::endl;
	
	switch(choice)
	{
	    // Add Planet
	case 1:
	    AddPlanet();
	    break;
	    // Delete Planet 
	case 2:
	    DeletePlanet();
	    break;
	    // Find Planet
	case 3:
	    FindPlanet();
	    // List all Planets
	    break;
	case 4:
	    ListPlanets();
	    break;
	    // Sort Planets
	case 5:
	    SortPlanets();
	    // Exit Program.
	case 6:
	    break;
	default:
	    std::cout << choice << " is not a valid choice" << std::endl;
	}
	    
    } while (choice != 6);

    return 0;
}
