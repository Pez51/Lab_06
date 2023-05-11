#include <iostream>
#include <cmath>

using namespace std;
// Declaración adelantada de la clase Circle
class Circle;


// Declaración de la clase amiga
class CircleOperations {
public:
    static double getArea(const Circle& c);
    static double getCircumference(const Circle& c);
};


class Circle {
private:
    double radio;
    double diametro;


    // Hacer la clase CircleOperations una clase amiga de Circle
    friend class CircleOperations;
public:
    Circle(double r) {
        radio = r;
        diametro = 2 * r;
    }


    double getRadio() const {
        return radio;
    }


    void setRadio(double r) {
        radio = r;
        diametro = 2 * r;
    }


    double getDiametro() const {
        return diametro;
    }


    void setDiametro(double d) {
        diametro = d;
        radio = d / 2;
    }
};


double CircleOperations::getArea(const Circle& c) {
    return M_PI * pow(c.radio, 2);
}


double CircleOperations::getCircumference(const Circle& c) {
    return 2 * M_PI * c.radio;
}


int main() {
    Circle miCirculo(5);
    cout << "Radio: " << miCirculo.getRadio() << endl;
    cout << "Diametro: " << miCirculo.getDiametro() << endl;
    cout << "Area: " << CircleOperations::getArea(miCirculo) << endl;
    cout << "Circunferencia: " << CircleOperations::getCircumference(miCirculo) << endl;


    miCirculo.setRadio(7);
    cout << "Radio: " << miCirculo.getRadio() << endl;
    cout << "Diametro: " << miCirculo.getDiametro() << endl;
    cout << "Area: " << CircleOperations::getArea(miCirculo) << endl;
    cout << "Circunferencia: " << CircleOperations::getCircumference(miCirculo) << endl;


    miCirculo.setDiametro(14);
    cout << "Radio: " << miCirculo.getRadio() << endl;
    cout << "Diametro: " << miCirculo.getDiametro() << endl;
    cout << "Area: " << CircleOperations::getArea(miCirculo) << endl;
    cout << "Circunferencia: " << CircleOperations::getCircumference(miCirculo) << endl;


    return 0;
}
