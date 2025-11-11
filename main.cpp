#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Semilla no deterministica.
    random_device rd;

    // Motor de Mersenne Twister que genera numeros pseudo-random de 32 bits.
    mt19937 gen(rd());

    constexpr int min = 1, max = 100;
    std::uniform_int_distribution<> distrib(min, max); // rango [1, 100]

    int random_num = distrib(gen);

    int totalClientes{};
    double totalVentasNetas{};

    // Estadisticas Sorteo
    int clientesParticipantes{};
    int conteoAmbicioso{}, conteoPoderoso{}, conteoFeliz{};
    int conteoCurioso = {}, conteoInfeliz = {};

    system("clear || cls");
    cout << string(50, '=') << endl;
    cout << "           TecnoGlobal S.A.S." << endl;
    cout << "Conectamos tu mundo con la tecnologia del futuro." << endl;
    cout << string(50, '=') << endl;

    cout << "A. Registro de Compra" << endl;
    cout << "B. Resumen Estadistico de Ventas." << endl;
    cout << "C. Salir." << endl;

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        char opcionMenu;
        bool opcionMenuValida{};

        while (!opcionMenuValida) {
            cout << "Seleccione una opcion: ";
            cin >> opcionMenu;
            opcionMenu = tolower(opcionMenu);

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Ingrese un caracter valido. \n";
            } else if (opcionMenu >= 'a' && opcionMenu <= 'c') {
                opcionMenuValida = true;
            } else {
                cout << "Error: Ingrese una opcion valida [A/B/C]. \n" << endl;
            }
        }

        if (opcionMenu == 'a') {
            long cedulaCliente{};
            bool cedulaValida{};

            string nombreCliente;

            cout << "Nombre del Cliente: ";
            cin.ignore();
            getline(cin, nombreCliente);

            // Validamos que la cedula tenga entre 7 y 10 digitos.
            // Algunas tienen menos digitos, pero son muy antiguas o casos excepcionales.
            while (!cedulaValida) {
                cout << "Documento de Identidad (C.C): ";
                cin >> cedulaCliente;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: Por favor, ingrese un numero de identificacion valido. \n" << endl;
                } else if (to_string(cedulaCliente).length() >= 7 && to_string(cedulaCliente).length() <= 10) {
                    cedulaValida = true;
                } else {
                    cout << "Error: Por favor, ingrese una cedula valida (7-10 digitos.) \n" << endl;
                }
            }

            totalClientes++;

            char continuarComprando = 's';

            while (continuarComprando == 's' || continuarComprando == 'S') {
                system("clear || cls");

                cout << left << setw(8) << "Codigo"
                        << setw(25) << "Producto"
                        << setw(20) << "Precio Unitario"
                        << setw(5) << "IVA" << endl;

                cout << string(58, '-') << endl;

                cout << left << setw(8) << 1
                        << setw(25) << "Laptop"
                        << setw(20) << "2,200,000"
                        << setw(5) << "19%" << endl;

                cout << left << setw(8) << 2
                        << setw(25) << "Smartphone"
                        << setw(20) << "1,200,000"
                        << setw(5) << "19%" << endl;

                cout << left << setw(8) << 3
                        << setw(25) << "Tablet"
                        << setw(20) << "900,000"
                        << setw(5) << "19%" << endl;

                cout << left << setw(8) << 4
                        << setw(25) << "Monitor"
                        << setw(20) << "700,000"
                        << setw(5) << "16%" << endl;

                cout << left << setw(8) << 5
                        << setw(25) << "Teclado y Mouse (Combo)"
                        << setw(20) << "120,000"
                        << setw(5) << "12%" << endl;

                cout << left << setw(8) << 6
                        << setw(25) << "Disco SSD 1TB"
                        << setw(20) << "350,000"
                        << setw(5) << "12%" << endl;

                cout << left << setw(8) << 7
                        << setw(25) << "Licencia de Software"
                        << setw(20) << "300,000"
                        << setw(5) << "0%" << endl;

                int codigoProducto{}, cantidad{};
                bool codigoValido{}, cantidadValida{};

                while (!codigoValido) {
                    cout << "Ingrese el codigo del producto (1-7): ";
                    cin >> codigoProducto;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: Ingrese un entero valido y dentro del rango.\n" << endl;
                    } else if (codigoProducto >= 1 && codigoProducto <= 7) {
                        codigoValido = true;
                    } else {
                        cout << "Error: Ingrese una opcion entre 1 y 7.\n" << endl;
                    }
                }
            }


        }


        if (opcionMenu == 'b') {
        }

        if (opcionMenu == 'c') continuar = 'n';
    }

    system("clear || cls");
    cout << string(50, '=') << endl;
    cout << "      Gracias por usar TecnoGlobal S.A.S." << endl;
    cout << " Conectamos tu mundo con la tecnologia del futuro." << endl;
    cout << string(50, '=') << endl;


    return 0;
}
