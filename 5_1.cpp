#include <iostream>
#include <string>
using namespace std;

class Estudiante {
  private:
    string nombre;
    string apellido;
    float nota_fase_1;
    float nota_fase_2;
    float nota_fase_3;


  public:
    // Constructor que recibe los datos del estudiante
    Estudiante(string nombre, string apellido, float nota_fase_1, float nota_fase_2, float nota_fase_3) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->nota_fase_1 = nota_fase_1;
        this->nota_fase_2 = nota_fase_2;
        this->nota_fase_3 = nota_fase_3;
    }


    // Función para calcular el promedio de las notas del estudiante
    float promedio_notas() {
        return (nota_fase_1 + nota_fase_2 + nota_fase_3) / 3.0;
    }


    // Función para imprimir los datos del estudiante
    void imprimir_datos() {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Nota fase 1: " << nota_fase_1 << endl;
        cout << "Nota fase 2: " << nota_fase_2 << endl;
        cout << "Nota fase 3: " << nota_fase_3 << endl;
        cout << "Promedio de notas: " << promedio_notas() << endl;
    }
};


int main() {
    // Crear un objeto Estudiante con los datos y notas correspondientes
    Estudiante estudiante("Oscar", "Flores", 16, 14, 18);


    // Imprimir los datos y el promedio de notas del estudiante
    estudiante.imprimir_datos();


    return 0;
}
