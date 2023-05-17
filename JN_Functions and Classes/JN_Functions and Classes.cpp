#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//defines class of "Triangle"
class Triangle
{
private:
	float base, height;//sets up variables of "base" and "height"
public:
	void setBase(float b)//sets up "base" to just one letter for equation
	{
		base = b;
	}

	void setHeight(float h)//sets up "base" to just one letter for equation
	{
		height = h;
	}

	float area()//sets up area variable
	{
		float a;
		a = base * height / 2;//equation for triangle
		return a;
	}		
};
//define class of "Rectangle"
class Rectangle
{
private:
	float base, height;//sets up variables of "base" and "height"
public:
	void setBase(float b)//sets up "base" to just one letter for equation
	{
		base = b;
	}

	void setHeight(float h)//sets up "base" to just one letter for equation
	{
		height = h;
	}

	float area()//sets up "area" variable
	{
		float a;
		a = base * height;// eqaution for rectangle
		return a;
	}
};

int main()
{
	string shape;//used to set sequences of words
	string answer;//used to set sequences of words

	cout << "Would you rather find the area of a Triangle or an Rectangle: ";//used to ask first question in the code
	cin >> shape;
	
	if (shape == "Triangle")//if user types in "Triangle" uses Triangle class to use equation of a "Triangle"
	{
		Triangle triangle1;
		float b, h;
		
		cout << "Enter height of Triangle : ";//allows user to input their own numbers
		cin >> h;

		cout << "Enter base of Triangle : ";//allows user to input their own numbers
		cin >> b;

		triangle1.setHeight(h);//confirms numbers
		triangle1.setBase(b);//confirms numbers
		cout << "Area of Triangle= " << triangle1.area() <<endl;//shows answer to equation
	}

	if (shape == "Rectangle")//if user types in "Rectangle" uses Rectangle class to use equation of a "Rectangle"
	{
		Rectangle rectangle1;
		float b, h;

		cout << "Enter height of Rectangle : ";//allows user to input their own numbers
		cin >> h;

		cout << "Enter base of Rectangle : ";//allows user to input their own numbers
		cin >> b;

		rectangle1.setHeight(h);//confirms numbers
		rectangle1.setBase(b);//confirms numbers
		cout << "Area of Rectangle= " << rectangle1.area() << endl;//shows answer to equation
	}

	while (shape == "Rectangle", "Triangle")//allows for loop to begin
	{
		cout << "Would you like to keep going? ";//asks question if user would like to end loop or not
		cin >> answer;

		if (answer == "yes")//if user types "yes" countinues loop
		{
			cout << "Would you rather find the area of a Triangle or an Rectangle: ";
			cin >> shape;

			if (shape == "Triangle")//if user types in "Triangle" uses Triangle class to use equation of a "Triangle"
			{
				Triangle triangle1;
				float b, h;

				cout << "Enter height of Triangle : ";//allows user to input their own numbers
				cin >> h;

				cout << "Enter base of Triangle : ";//allows user to input their own numbers
				cin >> b;

				triangle1.setHeight(h);//confirms numbers
				triangle1.setBase(b);//confirms numbers
				cout << "Area of Triangle= " << triangle1.area() << endl;//shows answer to equation
			}

			if (shape == "Rectangle")//if user types in "Rectangle" uses Rectangle class to use equation of a "Rectangle"
			{
				Rectangle rectangle1;
				float b, h;

				cout << "Enter height of Rectangle : ";//allows user to input their own numbers
				cin >> h;

				cout << "Enter base of Rectangle : ";//allows user to input their own numbers
				cin >> b;

				rectangle1.setHeight(h);//confirms numbers
				rectangle1.setBase(b);//confirms numbers
				cout << "Area of Rectangle= " << rectangle1.area() << endl;//shows answer to equation
			}
		}

			if (answer == "no")//if user types "no" ends program
			{
				return 0;
			}
	}
}