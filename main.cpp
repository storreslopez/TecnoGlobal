#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

// Usaremos codigos ANSI para mostrar la información, si bien puede llegar a ser
// Un poco verboso y dificil de entender, mejora la experiencia del usuario
// Convirtiendo nuestra interfaz de texto en una interfaz más clara y facil de usar.
// Codigos extraidos de https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

int main() {
    // Forzamos el encoding UTF-8 para poder mostrar acentos, eñes y emojis.
    // Este codigo no es portable y solo funciona en windows.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    constexpr int MAX_AMOUNT_OF_PRODUCTS = 100;

    constexpr double IVA_LAPTOP = 0.19, IVA_SMARTPHONE = 0.19, IVA_TABLET = 0.19, IVA_MONITOR = 0.16, IVA_COMBO = 0.12,
            IVA_DISCO = 0.12, IVA_LICENCIA = 0.0;

    constexpr double PRECIO_LAPTOP = 2200000, PRECIO_SMARTPHONE = 1200000, PRECIO_TABLET = 900000, PRECIO_MONITOR =
            700000, PRECIO_COMBO = 120000, PRECIO_DISCO = 350000, PRECIO_LICENCIA = 300000;

    constexpr double DESCUENTO_CURIOSO = 0.1, DESCUENTO_FELIZ = 0.25, DESCUENTO_PODEROSO = 0.5, DESCUENTO_AMBICIOSO = 1;

    // Colores ANSI
    string cyan = "\033[36m";
    string bold = "\033[1m";
    string green = "\033[32m";
    string italic = "\033[3m";
    string reset = "\033[0m";
    string blink = "\033[5m";
    string yellow = "\033[33m";
    string red = "\033[31m";
    string blue = "\033[34m";
    string magenta = "\033[35m";

    int totalClientes{};
    double totalVentasNetas{};

    // Estadisticas Sorteo
    int clientesParticipantes{};
    int conteoAmbicioso{}, conteoPoderoso{}, conteoFeliz{};
    int conteoCurioso = {}, conteoInfeliz = {};

    system("clear || cls");

    while (true) {
        char opcionMenu;
        bool opcionMenuValida{};

        cout << yellow << string(55, '=') << reset << endl;
        cout << bold << cyan << "                ⚙️  TecnoGlobal S.A.S." << reset << endl;
        cout << italic << "     Conectamos tu mundo con la " << green << "tecnología del futuro." << reset << endl;
        cout << yellow << string(55, '=') << reset << endl;
        cout << endl;

        cout << cyan << bold << "[A]" << reset << " " << italic << "Registro de Compra" << reset << endl;
        cout << cyan << bold << "[B]" << reset << " " << italic << "Resumen Estadístico de Ventas" << reset << endl;
        cout << cyan << bold << "[C]" << reset << " " << italic << "Salir" << reset << endl;
        cout << endl;


        while (!opcionMenuValida) {
            cout << cyan << bold << "► " << reset
                    << "Seleccione " << italic << "una opcion: " << reset;
            cin >> opcionMenu;
            opcionMenu = tolower(opcionMenu);

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << red << bold << "❌ Error: " << reset << italic << "Ingrese un caracter valido." << reset << "\n";
            } else if (opcionMenu >= 'a' && opcionMenu <= 'c') {
                opcionMenuValida = true;
            } else {
                cout << red << bold << "❌ Error: " << reset << italic << "Ingrese una opcion valida " << yellow <<
                        "[A/B/C]." << reset << "\n" << endl;
            }
        }

        char seguirRegistrando = 's';

        if (opcionMenu == 'a') {
            while (seguirRegistrando == 's' || seguirRegistrando == 'S') {
            long cedulaCliente{};
            bool cedulaValida{};

            string nombreCliente;

            cout << cyan << bold << "► " << reset << "Nombre del Cliente: " << green;
            cin.ignore();
            getline(cin, nombreCliente);
            cout << reset;

            // Validamos que la cedula tenga entre 7 y 10 digitos.
            // Algunas tienen menos digitos, pero son muy antiguas o casos excepcionales.
            while (!cedulaValida) {
                cout << cyan << bold << "► " << reset << "Documento de Identidad (C.C): " << green;
                cin >> cedulaCliente;
                cout << reset;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << red << bold << "❌ Error: " << reset << italic <<
                            "Por favor, ingrese un numero de identificacion valido." << reset << "\n" << endl;
                } else if (to_string(cedulaCliente).length() >= 7 && to_string(cedulaCliente).length() <= 10) {
                    cedulaValida = true;
                } else {
                    cout << red << bold << "❌ Error: " << reset << italic << "Por favor, ingrese una cedula valida " <<
                            yellow << "(7-10 digitos)." << reset << "\n" << endl;
                }
            }

            totalClientes++;

            double subtotal{};
            double porcentajeIva{};
            double iva{};

            char continuarComprando = 's';

            while (continuarComprando == 's' || continuarComprando == 'S') {
                system("clear || cls");

                cout << bold << cyan << left << setw(8) << "Codigo" << reset
                        << bold << cyan << setw(25) << "Producto" << reset
                        << bold << cyan << setw(20) << "Precio Unitario" << reset
                        << bold << cyan << setw(5) << "IVA" << reset << endl;

                cout << yellow << string(58, '-') << reset << endl;

                cout << yellow << bold << left << setw(8) << 1 << reset
                        << setw(25) << "Laptop"
                        << green << setw(20) << "2,200,000" << reset
                        << magenta << setw(5) << "19%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 2 << reset
                        << setw(25) << "Smartphone"
                        << green << setw(20) << "1,200,000" << reset
                        << magenta << setw(5) << "19%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 3 << reset
                        << setw(25) << "Tablet"
                        << green << setw(20) << "900,000" << reset
                        << magenta << setw(5) << "19%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 4 << reset
                        << setw(25) << "Monitor"
                        << green << setw(20) << "700,000" << reset
                        << magenta << setw(5) << "16%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 5 << reset
                        << setw(25) << "Teclado y Mouse (Combo)"
                        << green << setw(20) << "120,000" << reset
                        << magenta << setw(5) << "12%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 6 << reset
                        << setw(25) << "Disco SSD 1TB"
                        << green << setw(20) << "350,000" << reset
                        << magenta << setw(5) << "12%" << reset << endl;

                cout << yellow << bold << left << setw(8) << 7 << reset
                        << setw(25) << "Licencia de Software"
                        << green << setw(20) << "300,000" << reset
                        << magenta << setw(5) << "0%" << reset << endl;

                int codigoProducto{}, cantidad{};
                bool codigoValido{}, cantidadValida{};

                while (!codigoValido) {
                    cout << cyan << bold << "► " << reset << "Ingrese el codigo del producto " << yellow << "(1-7): " <<
                            reset;
                    cin >> codigoProducto;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << red << bold << "❌ Error: " << reset << italic <<
                                "Ingrese un entero valido y dentro del rango." << reset << "\n" << endl;
                    } else if (codigoProducto >= 1 && codigoProducto <= 7) {
                        codigoValido = true;
                    } else {
                        cout << red << bold << "❌ Error: " << reset << italic << "Ingrese una opcion entre " << yellow
                                << "1 y 7." << reset << "\n" << endl;
                    }
                }

                while (!cantidadValida) {
                    cout << cyan << bold << "► " << reset << "Ingrese la cantidad: " << green;
                    cin >> cantidad;
                    cout << reset;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << red << bold << "❌ Error: " << reset << italic << "Ingrese un entero valido." << reset <<
                                "\n" << endl;
                    } else if (codigoProducto >= 1 && codigoProducto <= MAX_AMOUNT_OF_PRODUCTS) {
                        cantidadValida = true;
                    } else {
                        cout << red << bold << "❌ Error: " << reset << italic << "Ingrese una cantidad entre " << yellow
                                << "1 y 100." << reset << "\n" << endl;
                    }
                }

                string descripcion;
                double valorParcialProducto{};
                double precioUnitario{};

                switch (codigoProducto) {
                    case 1: descripcion = "Laptop";
                        precioUnitario = PRECIO_LAPTOP;
                        porcentajeIva = IVA_LAPTOP;
                        break;
                    case 2: descripcion = "Smartphone";
                        precioUnitario = PRECIO_SMARTPHONE;
                        porcentajeIva = IVA_SMARTPHONE;
                        break;
                    case 3: descripcion = "Tablet";
                        precioUnitario = PRECIO_TABLET;
                        porcentajeIva = IVA_TABLET;
                        break;
                    case 4: descripcion = "Monitor";
                        precioUnitario = PRECIO_MONITOR;
                        porcentajeIva = IVA_MONITOR;
                        break;
                    case 5: descripcion = "Teclado y Mouse (Combo)";
                        precioUnitario = PRECIO_COMBO;
                        porcentajeIva = IVA_COMBO;
                        break;
                    case 6: descripcion = "Disco SSD 1TB";
                        precioUnitario = PRECIO_DISCO;
                        porcentajeIva = IVA_DISCO;
                        break;
                    case 7: descripcion = "Licencia de Software";
                        precioUnitario = PRECIO_LICENCIA;
                        porcentajeIva = IVA_LICENCIA;
                        break;
                }

                valorParcialProducto = precioUnitario * cantidad;
                iva = valorParcialProducto * porcentajeIva;
                subtotal += valorParcialProducto;

                system("clear || cls");

                cout << green << bold << "✅ Producto agregado exitosamente." << reset;

                cout << "\n\n";
                cout << bold << cyan << left << setw(12) << "Codigo" << reset
                        << bold << cyan << setw(30) << "Descripcion" << reset
                        << bold << cyan << setw(12) << "Cantidad" << reset
                        << bold << cyan << setw(18) << "Precio Unitario" << reset
                        << bold << cyan << setw(18) << "Valor Parcial" << reset
                        << bold << cyan << setw(18) << "Subtotal Compra" << reset << endl;

                cout << yellow << string(110, '-') << reset << endl;

                cout << yellow << bold << left << setw(12) << codigoProducto << reset
                        << setw(30) << descripcion
                        << blue << setw(12) << cantidad << reset
                        << green << "$" << right << setw(12) << fixed << setprecision(0) << precioUnitario << reset
                        << "  " << green << "$" << right << setw(12) << fixed << setprecision(0) << valorParcialProducto
                        << reset
                        << "  " << green << bold << "$" << right << setw(12) << fixed << setprecision(0) << subtotal <<
                        reset
                        << endl;

                cout << "\n" << cyan << bold << "► " << reset << "Desea agregar otro producto? " << italic << "(s/n): "
                        << reset;
                cin >> continuarComprando;
            }

            char deseaParticipar{};

            cout << cyan << bold << "► " << reset << "Desea participar en un sorteo especial de descuentos? " << italic
                    << yellow << "(s/n): " << reset;
            cin >> deseaParticipar;

            double porcentajeDescuento{};

            if (deseaParticipar == 's' || deseaParticipar == 'S') {
                // Semilla no deterministica.
                random_device rd;

                // Motor de Mersenne Twister que genera numeros pseudo-random de 32 bits.
                mt19937 gen(rd());

                constexpr int min = 1, max = 100;
                uniform_int_distribution<> distrib(min, max); // rango [1, 100]

                const int random_num = distrib(gen);

                system("clear || cls");

                cout << bold << cyan << "╔══════════════════════════════════════════════════╗" << reset << "\n";
                cout << bold << cyan << "║" << reset << "        " << bold << yellow <<
                        "Sistema de Descuentos Innovador" << reset << "        " << bold << cyan << "║" << reset <<
                        "\n";
                cout << bold << cyan << "╚══════════════════════════════════════════════════╝" << reset << "\n\n";

                cout << italic << "Como somos una empresa de tecnología, nuestro sistema de descuentos\n";
                cout << "se basa en un sorteo curioso e innovador: se genera un número aleatorio\n";
                cout << "y, según las propiedades matemáticas de ese número, el cliente obtiene\n";
                cout << "un porcentaje de descuento así:" << reset << "\n\n";

                // Encabezado de tabla
                cout << bold << cyan << left << setw(20) << "Tipo de número" << reset
                        << bold << cyan << setw(20) << "Descuento aplicado" << reset << endl;
                cout << yellow << string(38, '-') << reset << endl;

                // Filas
                cout << magenta << bold << left << setw(20) << "Ambicioso" << reset
                        << green << bold << setw(20) << "100%" << reset << endl;

                cout << blue << bold << left << setw(20) << "Poderoso" << reset
                        << green << setw(20) << "50%" << reset << endl;

                cout << yellow << bold << left << setw(20) << "Feliz" << reset
                        << green << setw(20) << "25%" << reset << endl;

                cout << cyan << bold << left << setw(20) << "Curioso" << reset
                        << green << setw(20) << "10%" << reset << endl;

                cout << red << italic << left << setw(20) << "Infeliz" << reset
                        << red << setw(20) << "0%" << reset << endl;

                cout << yellow << string(38, '-') << reset << endl;

                cout << "\n" << italic << "El número define tu destino... y tu descuento. ✨" << reset << "\n";

                int console_width = 80;
                string title = "Su numero aleatorio es";
                string number_str = to_string(random_num);

                int padding_title = (console_width - title.size()) / 2;
                int padding_number = (console_width - number_str.size()) / 2;

                cout << string(padding_title, ' ') << bold << cyan << title << reset << "\n\n";

                // Jingle Bells usando frecuencias específicas (Hz) y duraciones (ms).
                // Beep(659, 400); // E5
                // Beep(659, 400); // E5
                // Beep(659, 800); // E5
                // Beep(659, 400); // E5
                // Beep(659, 400); // E5
                // Beep(659, 800); // E5
                //
                // Beep(659, 400); // E5
                // Beep(784, 400); // G5
                // Beep(523, 400); // C5
                // Beep(587, 400); // D5

                cout << string(padding_number, ' ') << bold << yellow << blink
                        << number_str << reset << "\n\n";

                bool esAmbicioso = false, esPoderoso = true, esFeliz = false, esCurioso = false;

                int digits = to_string(random_num).length();

                // Curioso
                cout << cyan << bold << "🔍 Verificando si es CURIOSO..." << reset << "\n";

                int cuadrado = random_num * random_num;
                int divisor = pow(10, digits);
                int ultimasCifras = cuadrado % divisor;

                cout << italic << yellow << bold
                        << random_num << "^2 = " << cuadrado << reset << endl;
                cout << italic << "Ultimo(s) " << yellow << bold << digits << reset << " digito(s) de "
                        << yellow << cuadrado << reset << " = " << green << bold << ultimasCifras << reset << endl;

                if (ultimasCifras == random_num) {
                    esCurioso = true;
                    cout << green << bold
                            << "[10%] ✅ ES CURIOSO: (" << random_num
                            << "^2 termina en " << random_num << ")"
                            << reset << "\n" << endl;
                } else {
                    cout << red << bold << "❌ NO es CURIOSO" << reset
                            << italic << " (n² NO termina en n)" << reset << "\n" << endl;
                }


                // Ambicioso
                cout << cyan << bold << "🔍 Verificando si es AMBICIOSO..." << reset << "\n";

                if (random_num > 1) {
                    bool esPerfecto{};
                    int sumaDivisores = 1;

                    cout << italic << "Divisores propios de " << yellow << bold << random_num << reset << ": "
                            << yellow << "1 " << reset;

                    for (int i = 2; i * i <= random_num; ++i) {
                        if (!(random_num % i)) {
                            cout << yellow << i << " " << reset;
                            int otro = random_num / i;
                            sumaDivisores += i;
                            if (otro != i) {
                                sumaDivisores += otro;
                                cout << yellow << otro << " " << reset;
                            };
                        }
                    }

                    cout << reset << "\n" << bold
                            << "➕ Suma de divisores propios = " << green << sumaDivisores << reset << endl;

                    int m = sumaDivisores;

                    cout << italic << "\nVerificando si " << yellow << bold << m << reset
                            << " (la suma) es un número perfecto..." << reset << endl;

                    if (m > 1) {
                        int sumaM = 1;
                        for (int i = 2; i * i <= m; ++i) {
                            if (!(m % i)) {
                                int otro = m / i;
                                sumaM += i;
                                if (otro != i) sumaM += otro;
                            }
                        }
                        if (sumaM == m) esPerfecto = true;
                        cout << italic << "Suma de los divisores de " << yellow << m << reset
                                << " = " << green << bold << sumaM << reset << endl;
                    }

                    if (esPerfecto) {
                        esAmbicioso = true;
                        cout << green << bold << "[100%] 💎 ES AMBICIOSO!" << reset << "\n" << endl;
                    } else {
                        cout << red << bold << "❌ NO es AMBICIOSO" << reset << "\n" << endl;
                    }
                }


                // Poderoso
                cout << cyan << bold << "⚡ Verificando si es PODEROSO..." << reset << "\n";

                int temp = random_num;
                for (int p = 2; p * p <= temp; ++p) {
                    if (!(temp % p)) {
                        int exp{};
                        cout << italic << "Factor primo encontrado: " << yellow << p << reset;

                        while (!(temp % p)) {
                            temp /= p;
                            exp++;
                        }

                        cout << " → exponente = " << green << bold << exp << reset << endl;

                        if (exp < 2) {
                            esPoderoso = false;
                            cout << red << bold << "❌ No cumple: el exponente de " << yellow << p << reset
                                    << red << " es menor que 2." << reset << endl;
                            break;
                        }
                    }
                }

                if (temp > 1) {
                    esPoderoso = false;
                    cout << red << bold << "❌ Quedó un factor primo sin cuadrado completo: "
                            << yellow << temp << reset << endl;
                }

                if (esPoderoso) {
                    cout << green << bold << "[50%] 💪 ES un número PODEROSO!"
                            << reset << "\n" << endl;
                } else {
                    cout << red << bold << "❌ NO es un número PODEROSO." << reset << "\n" << endl;
                }


                // Feliz
                // Usaremos el Algoritmo de Floyd para deteccion de ciclos.
                // Tiene dos punteros: lento avanza de uno en uno, rapido avanza de dos en dos.
                // Si en algún momento lento == rapido, hay un ciclo infinito.
                // https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare
                cout << cyan << bold << "😊 Verificando si es un número FELIZ..." << reset << "\n";

                int lento = random_num, rapido = random_num;
                int paso = 1;

                while (true) {
                    cout << "\n" << bold << cyan << "🌀 Paso " << yellow << paso++ << reset << ":" << reset << endl;

                    // suma de cuadrados (una vez, lento)
                    int sum{}, temp = lento;
                    while (temp > 0) {
                        int d = temp % 10;
                        sum += d * d;
                        temp /= 10;
                    }
                    cout << "  " << italic << "Lento → suma de cuadrados = " << yellow << bold << sum << reset << endl;
                    lento = sum;

                    // suma de cuadrados (dos veces, rapido)
                    for (int k = 0; k < 2; ++k) {
                        int s2 = 0, t2 = rapido;
                        while (t2 > 0) {
                            int d = t2 % 10;
                            s2 += d * d;
                            t2 /= 10;
                        }
                        rapido = s2;
                    }
                    cout << "  " << italic << "Rápido → posición después de dos pasos = " << yellow << bold << rapido <<
                            reset << endl;

                    if (lento == 1 || rapido == 1) {
                        esFeliz = true;
                        cout << green << bold << "[25%] 🎉 ES un número FELIZ!"
                                << reset << "\n" << endl;
                        break;
                    }
                    if (lento == rapido) {
                        // si se repite el ciclo, es infeliz.
                        cout << red << bold << "💀 Es un número INFELIZ (entra en un ciclo infinito)"
                                << reset << "\n" << endl;
                        break;
                    }
                }


                if (esCurioso) porcentajeDescuento = DESCUENTO_CURIOSO;
                if (esFeliz) porcentajeDescuento = DESCUENTO_FELIZ;
                if (esPoderoso) porcentajeDescuento = DESCUENTO_PODEROSO;
                if (esAmbicioso) porcentajeDescuento = DESCUENTO_AMBICIOSO;
            }

            double descuento = subtotal * porcentajeDescuento;
            double ivaDescuento = iva * porcentajeDescuento;

            double total = subtotal + (iva - ivaDescuento) - descuento;

            cout << cyan << bold << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║" << reset << "            " << bold << yellow << "GRACIAS POR SU COMPRA 🛒" << reset <<
                    "               " << cyan << bold << "║\n";
            cout << "╚══════════════════════════════════════════════════╝" << reset << "\n\n";

            cout << bold << cyan << left << setw(18) << "Cliente:" << reset << green << nombreCliente << reset << endl;
            cout << bold << cyan << left << setw(18) << "C.C:" << reset << green << cedulaCliente << reset << endl;
            cout << yellow << string(50, '-') << reset << endl;

            cout << fixed << setprecision(0);
            cout << bold << left << setw(25) << "Valor Bruto:" << reset
                    << green << right << setw(17) << "$" << setw(10) << subtotal << reset << endl;

            cout << bold << left << setw(25) << "Descuento:" << reset
                    << yellow << right << setw(5) << "[" << setw(2) << porcentajeDescuento * 100
                    << "%]" << reset << green << setw(8) << "$" << setw(10) << descuento << reset << endl;

            cout << bold << left << setw(25) << "IVA:" << reset
                    << yellow << right << setw(5) << "[" << setw(2) << porcentajeIva * 100
                    << "%]" << reset << green << setw(8) << "$" << setw(10) << iva - ivaDescuento << reset << endl;

            cout << yellow << string(50, '-') << reset << endl;

            cout << bold << green
                    << left << setw(25) << "VALOR TOTAL A PAGAR:"
                    << right << "$" << setw(10) << total
                    << reset << "\n\n";

            cout << "\n" << cyan << bold << "► " << reset << "Desea registrar otro cliente? " << italic << "(s/n): " <<
                    reset;
            cin >> seguirRegistrando;
        }
    }

        if (opcionMenu == 'b') {
        }

        if (opcionMenu == 'c') break;
    }


    system("clear || cls");
    cout << yellow << string(55, '=') << reset << endl;
    cout << bold << cyan << "         💻 Gracias por usar TecnoGlobal S.A.S." << reset << endl;
    cout << italic << "   Conectamos tu mundo con la " << green << "tecnología del futuro." << reset << endl;
    cout << yellow << string(55, '=') << reset << endl;
    cout << endl;


    return 0;
}
