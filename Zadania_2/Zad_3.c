#include <stdio.h>

// Structure storing point coordinates
typedef struct {
    float x;
    float y;
} Point;

// Function modifying point coordinates via pointer
void modifyPoint(Point *ptr, float newX, float newY) {
    ptr->x = newX; // Modifies the x-coordinate of the point pointed to by the pointer ptr
    ptr->y = newY; // Modifies the y-coordinate of the point pointed to by the pointer ptr
}

// Structure storing rectangle coordinates
typedef struct {
    Point topleft;       // top-left corner
    Point bottomright;   // bottom-right corner
} Rectangle;

// Function calculating rectangle area
float calculateArea(Rectangle rect) {
    float width = rect.bottomright.x - rect.topleft.x;  // Calculates the width of the rectangle
    float height = rect.topleft.y - rect.bottomright.y; // Calculates the height of the rectangle
    return width * height; // Calculates the area of the rectangle and returns the result
}

// Function calculating rectangle perimeter
float calculatePerimeter(Rectangle rect) {
    float width = rect.bottomright.x - rect.topleft.x;  // Calculates the width of the rectangle
    float height = rect.topleft.y - rect.bottomright.y; // Calculates the height of the rectangle
    return 2 * (width + height); // Calculates the perimeter of the rectangle and returns the result
}

int main() {
    // Create a point instance and modify its coordinates
    Point point = {3.5, 4.2}; // Declares and initializes a point instance
    modifyPoint(&point, 1.0, 2.0); // Calls the modifyPoint function, changing the point's coordinates
    printf("Point coordinates after modification: (%.2f, %.2f)\n", point.x, point.y); // Displays the modified point coordinates
    
    // Create a rectangle instance and calculate its area and perimeter
    Rectangle rectangle = {{1.0, 3.0}, {5.0, 1.0}}; // Declares and initializes a rectangle instance
    float area = calculateArea(rectangle); // Calls the calculateArea function, calculating the rectangle's area
    float perimeter = calculatePerimeter(rectangle); // Calls the calculatePerimeter function, calculating the rectangle's perimeter
    
    // Displays the calculated area and perimeter of the rectangle
    printf("Rectangle area: %.2f\n", area);
    printf("Rectangle perimeter: %.2f\n", perimeter);
    
    return 0;
}
