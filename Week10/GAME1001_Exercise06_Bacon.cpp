/*----------------------------------- GAME1001_Exercise06_Bacon --------------------------------------
					    GAME1001 Practical Exercise 06, project by Kiera Bacon

Program specificiations are as follows:
1) Create a simple class called Rectangle
1.1) It has two private doubles as member variables, called length and width
2) Create a public member function called setLength that takes in a double as a parameter
2.1) and sets length to the value of that double.
2.2) Do not allow length to be set to a negative value!
3) Create a public member function called setWidth that takes in a double as a parameter
3.1) and sets width to the value of that double.
3.2) Do not allow width to be set to a negative value!
4) Create four getter methods for this class that do the following:
4.1) A method called getLength that simply returns the length property of the class
4.2) A method called getWidth that simple returns the length property of the class
4.3) A method called getArea that calculates and returns the area of the Rectangle
4.4) A method called getPerimeter that calculates and returns the perimeter of the Rectangle
5) In your main function, create at least two rectangle objects
5.1) and call all of the methods of the class.
5.2) You can print out the area and perimeter of at least one rectangle to the user
6) Optional: create a default constructor for Rectangle that sets both length and width to 1.0
6.1) Optional: create a non-default constructor for Rectangle that takes in two doubles as parameters
6.2) as sets length and width based on the double values
//----------------------------------------------------------------------------------------------------*/

#include <iostream>

class Rectangle															// Criterion 1.0
{
private:
	double length, width;												// Criterion 1.1
public:
	Rectangle()															// Criterion 6.0
	{
		length = 1.0;
		width = 1.0;
	}
	Rectangle(double newL, double newW)									// Criterion 6.1/6.2
	{
		setLength(newL);	// If provided with values, set the length and width
		setWidth(newW);		// on object creation, using the same criteria as normal
	}
	void setLength(double newL) { if (newL > 0) { length = newL; } }	// Criterion 2.1/2.2/2.3
	void setWidth (double newW) { if (newW > 0) { width  = newW; } }	// Criterion 3.1/3.2/3.3
	double getLength() { return length; }								// Criterion 4.1
	double getWidth()  { return width; }								// Criterion 4.2
	double getArea();		// Initialized in global body
	double getPerimeter();	// Initialized in global body
};

double Rectangle::getArea()												// Criterion 4.3
{
	double area;			// The area of a polygon is the space enclosed within its sides
	area = length * width;	// A rectangle's area is its length * its width
	return area;
}

double Rectangle::getPerimeter()										// Criterion 4.4
{
	double perimeter;		// The perimeter of a polygon is the length of all sides added together
	perimeter = (length * 2) + (width * 2);	// A rectangle has four sides, two == length, two == width
	return perimeter;
}

int main()
{
	Rectangle rect1, rect2, rect3(18.1, 7.9);							// Criterion 5.0
	rect1.setLength(2.2);												// Criterion 5.1
	rect1.setWidth(3.7);
	rect1.getLength();
	rect1.getWidth();
	std::cout << "First rectangle's area: " << rect1.getArea() << std::endl;	// Criterion 5.2
	std::cout << "First rectangle's perimeter: " << rect1.getPerimeter() << std::endl;
	std::cout << "Second rectangle's area: " << rect2.getArea() << std::endl;
	std::cout << "Second rectangle's perimeter: " << rect2.getPerimeter() << std::endl;
	std::cout << "Third rectangle's area: " << rect3.getArea() << std::endl;
	std::cout << "Third rectangle's perimeter: " << rect3.getPerimeter() << std::endl;
	return 0;
}