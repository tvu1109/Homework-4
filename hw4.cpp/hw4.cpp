/** Name:  Trang Vu
    UCLA ID:  304-145-069
    October 23, 2015
    @File: hw4.cpp
    @Brief: This program codes for the classes Point2D, ColorPoint2D, and WeightedPoint2D.  Class Point2D is the base class and Class ColorPoint2D and Class WeightedPoint2D are the derived class - they inherit Class Point2D.  Polymorphism is incorporated and uses the keyword Virtual.  Member functions are also created to be used in int main.  Implementation are provided after int main.
*/

#include <iostream>
#include <string>
#include <vector>

/** @class Point2D
 @brief: stores a point in the form of (x,y)
 */
class Point2D {
public:
    
    // Default Constructor
    Point2D();
    // Constructor
    Point2D(double, double);
    
    // Print function
    virtual void print();
    
    // Destructor
    virtual ~Point2D();
    
private:
    
    double x;
    double y;
};

/** @class ColorPoint2D
 @brief: gives user the option to add a color for the point
 */
class ColorPoint2D:public Point2D {
public:
    
    //Default Constructor
    ColorPoint2D();
    // Constructor
    ColorPoint2D(const std::string&, double, double);
    
    // Print Function
    void print();
    
private:
    
    std::string color;
};

/** @class WeightedPoint2D
 @brief: gives user the option to add weight for the points inputed
 */
class WeightedPoint2D:public Point2D {
public:
    
    // Default Constructor
    WeightedPoint2D();
    // Constructor
    WeightedPoint2D(double, double, double);

    // Print Function
    void print();
    
private:
    
    double weight;
};

// Prompts the welcome message
void welcome_message();

int main(){
    
welcome_message();

// Creates a vector to store the created points.  This vector is of type Point2D pointer because the points have different parameters
std::vector<Point2D*> input_points;

// Allows user to choose which type of point they want to create
std::string input;
std::cout << "Selection: ";
std::cin >> input;

// Allows user to put in more than one points until they want to stop
while (input != "0"){
    
    // If the user selects 1 then a point (x,y) will be created
    if (input == "1"){
        
        double x = 0.;
        double y = 0.;
        
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        std::cout << "Selection: ";
        std::cin >> input;
        
        // Adds the point to the vector
        // Creates memory in the heap
        input_points.push_back(new Point2D(x,y));
    }
    
    // If the user selects 2 then user can add a color to the point
    else if (input == "2"){
        
        double x = 0.;
        double y = 0.;
        std::string color;
        
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        std::cout << "color = ";
        // Allow user to put more than one word
        std::cin.ignore();
        getline (std::cin, color);
        std::cout << "Selection: ";
        std::cin >> input;
        
        input_points.push_back(new ColorPoint2D(color,x,y));
    }
    
    // If the user selects 3 then user can add a weight to the point
    else if (input == "3"){
        
        double x = 0.;
        double y = 0.;
        double weight = 0.;
        
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        std::cout << "weight = ";
        std::cin >> weight;
        std::cout << "Selection: ";
        std::cin >> input;
        
        input_points.push_back(new WeightedPoint2D(weight,x,y));
    }
}
    
    std::cout << std::endl << "Your points are " << std::endl << std::endl;

// This for loops prints all the elements that was added to the vector
for (size_t i = 0, n = input_points.size(); i < n; ++i){
    std::cout << i+1 << ": ";
    (*input_points[i]).print();
    std::cout << std::endl;
}

// This for loop deletes every element that was created in the heap to prevent memory leak
for (size_t i = 0, n = input_points.size(); i < n; ++i){
    delete input_points[i];
}

std::cout << std::endl;
    
return 0;
}
    
/** Initializes points to (0.,0.,) */
Point2D::Point2D(){
    x = 0.;
    y = 0.;
}
                                   
/** Creates the inputed point in the form of (x,y)
    @param input_x is the input x value
    @param input_y is the input y value
*/
Point2D::Point2D(double input_x, double input_y){
    x = input_x;
    y = input_y;
}

/** Virtual Destructor deletes everything in the heap */
Point2D::~Point2D(){
}

/** Prints the points in the format of (x,y) */
void Point2D::print() {
std::cout << "(" << x << "," << y << ")";
}

/** Initizalizes the string color */
ColorPoint2D::ColorPoint2D(){
    color = "unknown";
}

/** Creates the input point and color in the form of (color, x, y)
    @param input_color is the input color
    @param input_x is the input x value
    @param input_y is the input y value
 */
ColorPoint2D::ColorPoint2D(const std::string& input_color, double input_x, double input_y): Point2D(input_x, input_y){
    color = input_color;
}

/** Prints the points in the format of color(x,y) */
void ColorPoint2D::print(){
    std::cout << color;
    Point2D::print();
}

/** Initializes weight */
WeightedPoint2D::WeightedPoint2D(){
    weight = 0.;
}

/** Creates the input point and weight in the form of (weight, x, y)
    @param input_weight is the input weight
    @param input_x is the input x value
    @param input_y is the input y value
 */
WeightedPoint2D::WeightedPoint2D(double input_weight, double input_x, double input_y): Point2D(input_x, input_y){
    weight = input_weight;
}

/** Prints the points in the format of weight(x,y) */
void WeightedPoint2D::print(){
    std::cout << weight;
    Point2D::print();
}

/** Prints the welcome message, shows the different format of the points, and provides instructions to end adding points */
void welcome_message (){
    std::cout << "Welcome to Point Printer!  You can create three different kinds of points: " << std::endl << std::endl;
    std::cout << "1.  Point2D, e.g., (2,6.5)" << std::endl;
    std::cout << "2.  ColorPoint2D, e.g., blue(-4.5,3.5)" << std::endl;
    std::cout << "3.  WeightedPoint2D, e.g., .12(3.6,8.7)" << std::endl;
    std::cout << std::endl << "Enter 0 when you are finished." << std::endl << std::endl;
}
