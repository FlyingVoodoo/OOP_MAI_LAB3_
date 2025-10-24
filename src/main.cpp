#include <iostream>
#include <figure.h>
#include <ostream>
#include <rectangle.h>
#include <rhombus.h>
#include <trapezoid.h>
#include <vector-figure.h>

int main() {
    VectorFigure v;
    std::cout << "INPUT VECTOR SIZE: ";
    int n;
    std::cin >> n;
    std::cout << "1 - Rectangle\n2 - Rhombus\n3 - Trapezoid\n";
    
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        Figure* f = nullptr;
        
        if (c == '1') {
            f = new Rectangle();
        } else if (c == '2') {
            f = new Rhombus();
        } else if (c == '3') {
            f = new Trapezoid();
        } else {
            std::cout << std::endl;
        }
        
        std::cin >> *f;
        v.push(f);
    }

    std::cout << "\nINPUT ERASE INDEX: ";
    size_t ind;
    std::cin >> ind;
    
    if (ind < v.len()) {
        v.erase(ind);
        std::cout << "Erased successfully\n";
    } else {
        std::cout << "Invalid index\n";
    }
    
    std::cout << v.len() << std::endl;
    for (size_t i = 0; i < v.len(); ++i) {
        std::cout << v.get(i)->Area() << std::endl;
    }
    return 0;
}