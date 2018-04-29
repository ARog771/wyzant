
#include <iostream>

char getAlphaDigit(unsigned v)
{
    if (v > 36 )
    {
	std::cerr << "Failed to convert value: " << v << " into a alpha equivelant" << std::endl;
	return 0;
    }

    if ( v < 10 )
	return (char)v + '0';

    return (char)v-10 + 'A'; 
}


int main(void)
{
    unsigned int value;
    unsigned int base;
    std::cout << "Enter value: ";
    std::cin >> value;
    std::cout << "Enter base: ";
    std::cin >> base;
    
    std::string result;

    while (value)
    {
	unsigned remainder = value % base;
	value = value / base;

	char digit = getAlphaDigit(remainder);
	if (!digit)
	    break;

	result.insert(0, 1, digit);
    }

    std::cout << "Converting Value: " << value << " to base: " << base << std::endl;
    std::cout << "Converted Value: " << result << std::endl;

    return 0;
}

