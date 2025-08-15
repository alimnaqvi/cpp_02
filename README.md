# C++ Module 02: Ad-hoc Polymorphism, Operator Overloading & Orthodox Canonical Form

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This project is part of the C++ modules at 42 School. It focuses on fundamental Object-Oriented Programming concepts in C++, specifically **Ad-hoc Polymorphism** (Function and Operator Overloading) and the **Orthodox Canonical Class Form (OCF)**. Through a series of exercises, we build a fixed-point number class and apply it to a simple geometrical problem.

## Core Concepts Covered

*   Understand and implement the **Orthodox Canonical Form (OCF)** for C++ classes, ensuring proper resource management (though not strictly needed for this simple class, it's good practice).
*   Grasp the concept of **Ad-hoc Polymorphism** and apply it through function overloading and, more extensively, **operator overloading**.
*   Learn how to represent and manipulate **fixed-point numbers**, including conversions to/from integers and floating-point numbers.
*   Implement various operator overloads for a custom class:
    *   Comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`)
    *   Arithmetic operators (`+`, `-`, `*`, `/`)
    *   Increment/Decrement operators (`++` pre/post, `--` pre/post)
    *   Stream insertion operator (`<<`)
*   Understand the difference in implementation and behavior between **pre-increment/decrement** and **post-increment/decrement** operators.
*   Apply the developed fixed-point class to a practical problem: **Binary Space Partitioning (BSP)** to determine if a point lies within a triangle.
*   Reinforce the importance of **`const` correctness** in class design and function signatures.

## Learning Resources

* [Introduction to the copy constructor](https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/)
* [Object relationships](https://www.learncpp.com/cpp-tutorial/object-relationships/)
* [Simple Fixed-Point Math](https://spin.atomicobject.com/simple-fixed-point-math/)
* [Overloading the I/O operators](https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/)
* [Overloading operators using member functions](https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/)
* [Overloading the comparison operators](https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/)
* [Overloading the increment and decrement operators](https://www.learncpp.com/cpp-tutorial/overloading-the-increment-and-decrement-operators/)
* [Overloading the assignment operator](https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/)

## Project Structure

<p>
   The project is divided into four exercises, each building upon the previous one:
  <img src="https://page-views-counter-534232554413.europe-west1.run.app/view?src=github.com&src_uri=/alimnaqvi/cpp_02" style="display: none;" />
</p>

*   `ex00/`: Introduction to OCF and the basic `Fixed` class structure.
*   `ex01/`: Adding constructors for `int` and `float`, conversion functions (`toInt`, `toFloat`), and overloading the stream insertion (`<<`) operator.
*   `ex02/`: Overloading comparison, arithmetic, and increment/decrement operators for the `Fixed` class. Adding static `min` and `max` functions.
*   `ex03/`: Creating a `Point` class using `Fixed` numbers and implementing a `bsp` (Binary Space Partitioning) function.

Each directory contains:
*   `Makefile`: To compile the exercise.
*   `main.cpp`: The main program to test the exercise's features.
*   `Fixed.h`/`Fixed.cpp`: Header and implementation for the fixed-point number class (evolves through exercises).
*   `Point.h`/`Point.cpp` (ex03 only): Header and implementation for the 2D Point class.
*   `bsp.cpp` (ex03 only): Implementation of the BSP function.

## Implementation Details

### Exercise 00: My First Class in Orthodox Canonical Form

*   **Task:** Create a basic `Fixed` class that adheres to the Orthodox Canonical Form (OCF).
*   **Implementation:**
    *   Defined the `Fixed` class with a private integer member (`mFixedPointValue`) to store the raw fixed-point value and a private static constant integer (`mNbFractBits`) for the number of fractional bits (hardcoded to 8).
    *   Implemented the required OCF members:
        *   Default Constructor: Initializes the fixed-point value to 0.
        *   Copy Constructor: Copies the raw value from another `Fixed` object.
        *   Copy Assignment Operator: Assigns the raw value from another `Fixed` object, returning `*this`. Includes a self-assignment check (though added in ex01).
        *   Destructor: Handles cleanup (trivial in this case, but part of OCF).
    *   Added `getRawBits()` and `setRawBits()` public member functions to access/modify the raw value.
    *   Constructors and operators print messages to the console to demonstrate when they are called (a common practice in 42 evaluation).
*   **Key Concepts:** Orthodox Canonical Form (OCF), class definition, constructors, destructor, copy assignment, member functions, `static const` members.

### Exercise 01: Towards a More Useful Fixed-Point Number Class

*   **Task:** Enhance the `Fixed` class with constructors for integers and floats, conversion functions, and stream output.
*   **Implementation:**
    *   Added two public constructors: `Fixed(const int)` and `Fixed(const float)`.
        *   The `int` constructor converts the integer to fixed-point by left-shifting it by `mNbFractBits`.
        *   The `float` constructor converts the float by multiplying it by 2<sup>`mNbFractBits`</sup> (`1 << mNbFractBits`), rounding the result (`roundf`), and casting to `int`.
    *   Added `toFloat()` and `toInt()` public const member functions for converting the fixed-point value back to floating-point or integer representation.
    *   Overloaded the stream insertion operator (`operator<<`) as a **non-member function** (essential for `std::cout << fixed_object` syntax). It uses the `toFloat()` method to print a human-readable representation.
*   **Key Concepts:** Fixed-point number representation, type conversion algorithms (int/float to fixed-point and vice-versa), operator overloading (`<<`), non-member functions, `cmath` (`roundf`), bitwise shift operators (`<<`, `>>`).

### Exercise 02: Now We’re Talking

*   **Task:** Overload comparison, arithmetic, and increment/decrement operators for the `Fixed` class. Add static helper functions.
*   **Implementation:**
    *   **Comparison Operators:** Overloaded `>`, `<`, `>=`, `<=`, `==`, `!=` as const member functions. They directly compare the raw `mFixedPointValue` of two `Fixed` objects.
    *   **Arithmetic Operators:** Overloaded `+`, `-`, `*`, `/` as const member functions returning a new `Fixed` object.
        *   `+` and `-`: Simply add/subtract the raw values.
        *   `*` and `/`: Require careful handling of the fixed-point scaling. Multiplication involves multiplying the raw values and then scaling *down* (dividing by 2<sup>`mNbFractBits`</sup>). Division involves scaling *up* the numerator before dividing the raw values. `long long` is used during intermediate calculations to prevent overflow.
    *   **Increment/Decrement Operators:** Overloaded `++` (pre/post) and `--` (pre/post).
        *   Pre-increment/decrement (`++a`, `--a`): Modify the object's raw value by 1 (representing the smallest possible change, epsilon) and return a reference to the modified object (`*this`).
        *   Post-increment/decrement (`a++`, `a--`): Create a copy of the object *before* modification, modify the original object (typically by calling the pre-increment/decrement version), and return the *copy*. The `int` parameter distinguishes post-increment/decrement from pre-increment/decrement overload.
    *   **Static Functions:** Added static member functions `min` and `max`, each overloaded to accept both `Fixed&` (non-const) and `const Fixed&` parameters, returning the smaller or larger of the two `Fixed` objects.
*   **Key Concepts:** Operator overloading (comparison, arithmetic, increment/decrement), fixed-point arithmetic, pre- vs. post-increment/decrement semantics and implementation, `static` member functions, function overloading based on `const`.

### Exercise 03: BSP (Binary Space Partitioning)

*   **Task:** Create a `Point` class using `Fixed` coordinates and implement a `bsp` function to check if a point lies within a given triangle.
*   **Implementation:**
    *   **`Point` Class:**
        *   Defined with two `const Fixed` data members (`x`, `y`). Making them `const` ensures points are immutable after creation, which is suitable for this exercise.
        *   Provided constructors: default, `(float, float)`, and copy constructor.
        *   The copy assignment operator is implemented but essentially non-functional because the `x` and `y` members are `const` and cannot be reassigned after initialization. A warning message could be added here.
        *   Included `getXObj()` and `getYObj()` getter methods returning `const Fixed&`.
        *   Overloaded `operator<<` for easy printing of Point coordinates.
    *   **`bsp` Function:**
        *   Takes four arguments: three `Point` objects representing the triangle vertices (`a`, `b`, `c`) and one `Point` representing the point to check (`point`).
        *   Uses the concept of **cross products** (or signed area) to determine the orientation of the point relative to each edge of the triangle (AB, BC, CA).
        *   A helper function `crossProductSign(Point P1, Point P2, Point P_test)` calculates `(P2.x - P1.x)*(P_test.y - P1.y) - (P2.y - P1.y)*(P_test.x - P1.x)` using `Fixed` arithmetic.
        *   The point is inside the triangle if and only if all three cross products have the **same sign** (either all positive or all negative) and are **non-zero**. Points on the edges or vertices are considered outside according to the subject requirements.
*   **Key Concepts:** Using custom classes as members, `const` correctness and its implications (immutability, non-assignable members), geometric algorithms (BSP), vector cross product application in 2D for orientation testing, composing functionality from previously built classes (`Fixed`).

## How to Compile and Run

Each exercise can be compiled and run independently using the provided `Makefile`.

1.  Navigate to the specific exercise directory (e.g., `ex00`, `ex01`, etc.).
    ```bash
    cd exXX
    ```
2.  Use `make` to compile the project.
    ```bash
    make
    ```
3.  This will create an executable file named after the exercise (e.g., `ex00`, `ex01`).
4.  Run the executable:
    ```bash
    ./exXX
    ```

**Other Make Commands:**

*   `make clean`: Removes the object files (`*.o`).
*   `make fclean`: Removes object files and the executable.
*   `make re`: Performs `fclean` followed by `make`.

**Example (Compiling and running Exercise 02):**

```bash
cd ex02
make
./ex02
```
