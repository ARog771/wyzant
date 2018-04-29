#include<iostream>
#include<cmath>

class shape
{
public:
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
};

class sphere : public shape
{

private:
    double m_radius;
public:
    sphere(double radius)
	:m_radius(radius)
    {
    }

    double getSurfaceArea() {
	return 4*M_PI*pow(m_radius,2);
    }

    double getVolume() {
	return 4/3*M_PI*pow(m_radius,3);
    }
};

class cone : public shape
{
private:
    double m_radius;
    double m_height;

public:
    cone(double radius, double height)
	:m_radius(radius),m_height(height)
    {
    }

    double getSurfaceArea() {
	return (M_PI)*(pow(m_radius,2.0)+m_radius*(sqrt(pow(m_radius,2.0)+pow(m_height,2.0))));
    }

    double getVolume() {
	return (1.0/3.0)*m_height*pow(m_radius,2.0)*(M_PI);
    }
};

class cube : public shape
{
private:
    double m_edge;

public:
    cube(double edge)
	:m_edge(edge)
    {
	std::cout << "Creating a cube" << std::endl;
    }

    double getSurfaceArea()
    {
	return 6.0*pow(m_edge,2.0);
    }

    double getVolume()
    {
	return pow(m_edge,3.0);
    }
};

class cylinder : public shape
{
private:
    double m_radius;
    double m_height;

public:
    cylinder(double radius, double height)
	:m_radius(radius),m_height(height)

    {
    }

    double getSurfaceArea()
    {
	return 2.0*(M_PI)*m_radius*m_height;
    }

    double getVolume()
    {
	return m_height*(M_PI)*pow(m_radius,2.0);
    }

};

class rprism : public shape
{
private:
    double m_length;
    double m_width;
    double m_height;

public:

    rprism(double length, double width, double height)
	:m_length(length),m_width(width),m_height(height)
    {
    }

    double getSurfaceArea() {
	return 2.0*(m_width*m_length+m_width*m_height+m_height*m_length);
    }

    double getVolume() {
	return (m_length*m_width*m_height);
    }
};


void menu()
{
    std::cout << "1. Sphere" << std::endl;
    std::cout << "2. Cone" << std::endl;    
    std::cout << "3. Cube" << std::endl;
    std::cout << "4. Cylinder" << std::endl;
    std::cout << "5. Rectangular Prism" << std::endl;
    std::cout << "6. Quit" << std::endl;
    std::cout << "? " ;
}

int readInt()
{
    int retval;
    std::cin >> retval;
    return retval;
}

double readDouble()
{
    double retval;
    do
    {
	std::cin >> retval;
	if (retval < 0.0)
	    std::cout << "Please input a positive value" << std::endl;
    } while (retval < 0.0);

    return retval;
}

int main(void)
{ 
    double r,h,l,w,e;

    int choice = 0;
    do {
	menu();
	choice = readInt();

	switch(choice)
	{
	    case 1:
	    {
		std::cout << "enter radius: ";
		r = readDouble();
		sphere s(r);
		std::cout << "Surface Area: " << s.getSurfaceArea() << " Volume: " << s.getVolume() << std::endl; 

		break;
	    }  

	    case 2:
	    {
		std::cout << "enter radius: ";
		r = readDouble();
		std::cout << "enter height: ";
		h = readDouble();
		cone s(r,h);
		std::cout << "Surface Area: " << s.getSurfaceArea() << " Volume: " << s.getVolume() << std::endl; 

		break;
	    }
	    case 3:
	    {
		std::cout << "enter edge: ";
		e = readDouble();
		cube s(e);
		std::cout << "Surface Area: " << s.getSurfaceArea() << " Volume: " << s.getVolume() << std::endl; 

		break;
	    }
	    case 4:
	    {
		std::cout << "enter radius: ";
		r = readDouble();
		std::cout << "enter height: ";
		h = readDouble();
		cylinder s(r,h);
		std::cout << "Surface Area: " << s.getSurfaceArea() << " Volume: " << s.getVolume() << std::endl; 
		break;
	    }
	    case 5:
	    {
		std::cout << "enter length: ";
		l = readDouble();
		std::cout << "enter width: ";
		w = readDouble();
		std::cout << "enter height: ";
		h = readDouble();
		rprism s(l,w,h);
		std::cout << "Surface Area: " << s.getSurfaceArea() << " Volume: " << s.getVolume() << std::endl; 
		break;
	    }

	    // Exit the program. 
	    case 6:
	    break;

	    default:
	    std::cout << "User Error invalid entry" << std::endl;
	    break;
	}

    } while (choice != 6);

    return 0;
}

