#include <iostream>

    class Rectangle {
        int width, height;

      public:
        Rectangle() {
            width = 0;
            height = 0;
        }
        Rectangle(int x, int y) :
            width(x),
            height(y) {
        }

        int getArea();
    };

    int Rectangle::getArea() {
        return width * height;
    }

    int main() {

        // instantiate a Rectangle rect
        Rectangle rect(3, 4);

        // define 3 Rectangle pointers
        Rectangle *foo, *bar, *baz;

        // point the foo pointer to the address of rect
        foo = &rect;

        // dynamically allocate memory for a new Rectangle object and
        // assign to the bar pointer
        bar = new Rectangle{5, 6};

        // dynamically allocate space for two Rectangle objects in
        // an array and assign to the baz pointer.  Since we are
        // defining the new array, we can pass the constructor
        // parameters into each cell in the new array
        baz = new Rectangle[2]{{2, 5}, {3, 6}};

        // More on the above syntax of defining a new Rectangle array
        // Since an array is a contiguous sequence of elements, if we
        // were to instantiate another rectangle outside of the statement
        // where we create the baz array pointer, and then try to
        // insert it into the array: baz[0] = rect2;  This would be
        // valid.  However, it would not 'move' the rect2 object into
        // the baz[0] block.  It would actually copy it, which is
        // not ideal.  Doing the above would look like this:

        // you NEED a default constructor for this commented out example,
        // otherwise the array can't be default initialized with
        // valid Rectangle objects
        // baz = new Rectangle[2];
        // Rectangle rect2(2, 5);
        // Rectangle rect3(3, 6);
        // baz[0] = rect2;
        // baz[1] = rect3;

        std::cout << "rect's area: " << rect.getArea() << '\n';
        std::cout << "*foo's area: " << foo->getArea() << '\n';
        std::cout << "*bar's area: " << bar->getArea() << '\n';
        std::cout << "baz[0]'s area: " << baz[0].getArea() << '\n';
        std::cout << "baz[1]'s area: " << baz[1].getArea() << '\n';

        // deallocate (free) the memory blocks that bar and baz point to
        delete bar;
        delete[] baz;

        return 0;
    }
