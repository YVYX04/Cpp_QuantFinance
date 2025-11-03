/*
T_Pair.cpp
In this code, we illustrate the concept of templates
with a templated class (classes/Pair.hpp).
*/

#include "classes/Pair.hpp"
#include "classes/Fraction.hpp"
#include <iostream>

int main()
{
    // TEMPLATED CLASS USAGE
    yvan::Pair<int> p1(3, 7);
    std::cout << "Max of p1: " << p1.max() << '\n';
    yvan::Pair<Fraction> p2(Fraction(1, 3), Fraction(2, 5));
    std::cout << "Max of p2: " << p2.max() << '\n';
    return 0;
}

/*
+––––––––+
| OUTPUT |
+––––––––+
Max of p1: 7
Max of p2: (2/5)
*/

/*
+–––––––––+
| WARNING |
+–––––––––+
When compiling T_Pair.cpp, make sure to compile
classes/Fraction.cpp as well, since the Fraction
class is used in this file. However, do NOT compile
classes/Pair.cpp separately, since it is included
in classes/Pair.hpp. This is a classic way
to handle templated classes in C++.

PS: my .vscode/tasks.json file has been set up
accordingly.
*/
