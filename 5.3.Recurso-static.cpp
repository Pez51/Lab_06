#include <iostream>

using namespace std;
class Banco {
private:
    static double tasaInteres;
public:
    static void setTasaInteres(double tasa) {
        tasaInteres = tasa;
    }
    static double getTasaInteres() {
        return tasaInteres;
    }
};
double Banco::tasaInteres = 0.0;

class CuentaBancaria {
private:
    double saldo;
public:
    CuentaBancaria(double saldoInicial) : saldo(saldoInicial) {}
    void depositar(double monto) {
        saldo += monto;
        cout<<"Se deposito: "<<monto<<" soles en la cuenta."<<endl;
    }
    void retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
            cout<<"Va a retirar: "<<monto<<" soles de la cuenta."<<endl;
        } else {
            cout<<"Credito insuficiente en la cuenta."<<endl;
        }
    }
    double calcularInteresGanado() {
        double interes = saldo * Banco::getTasaInteres();
        return interes;
    }
    double getSaldo() {
        return saldo;
    }
};

int main() {
    double tasa = Banco::getTasaInteres();
    cout << "La tasa de interés actual del banco es: " << tasa <<endl;
    Banco::setTasaInteres(0.18);
    cout << "La tasa de interés se ha actualizado." <<endl;
    tasa = Banco::getTasaInteres();
    cout << "La nueva tasa de interés del banco es: " << tasa <<endl;
    Banco::setTasaInteres(0.05);
    CuentaBancaria cuenta(1000.0);
    cuenta.depositar(500.0);
    cuenta.retirar(200.0);
    double interes = cuenta.calcularInteresGanado();
    cout<<"El interés ganado por la cuenta es de: " <<interes<<endl;
    double saldo = cuenta.getSaldo();
    cout<<"El saldo actualizado de la cuenta es: " <<saldo<<endl;

    return 0;
}