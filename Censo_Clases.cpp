//Zuleinis K. Ramos López

#include <iostream>
#include <string>
#define MAX 2
using namespace std;

struct fecha {
    int dia;
    int mes;
    int anio;
};

class censo {
public:
    censo();
    ~censo();
    void setNombre(istream & stream);
    void setEdad(istream & stream);
    void setFechaNacimiento(istream & stream);
    void setNumTelefono(istream & stream);
    void setNumPersonas(istream & stream);
    void setPropiedad(istream & stream);
    string getNombre();
    int getEdad();
    void getFechaNacimiento();
    long getNumTelefono();
    int getNumPersonas();
    char getPropiedad();
    void agregarCenso();
    void escribirCensos();
private:
    string nombre;
    int edad;
    fecha fechaNacimiento;
    long numTelefono;
    int numPersonas;
    char propiedad;
};

censo::censo(){}
censo::~censo(){}

void censo::setNombre(istream & stream)
{
    stream >> nombre;
}

void censo::setEdad(istream & stream)
{
    stream >> edad;
}

void censo::setFechaNacimiento(istream & stream)
{
    cout << " día: ";
    cin >> fechaNacimiento.dia;
    cout << " mes: ";
    cin >>fechaNacimiento.mes;
    cout << " año: ";
    cin >>fechaNacimiento.anio;
}

void censo::setNumTelefono(istream & stream)
{
    cin >> numTelefono;
}

void censo::setNumPersonas(istream & stream)
{
    cin >> numPersonas;
}

void censo::setPropiedad(istream & stream)
{
    cin >> propiedad;
}

string censo::getNombre()
{
    return nombre;
}

int censo::getEdad()
{
    return edad;
}

void censo::getFechaNacimiento()
{
    cout << fechaNacimiento.dia << "/" << fechaNacimiento.mes << "/" << fechaNacimiento.anio;
}

long censo::getNumTelefono()
{
    return numTelefono;
}

int censo::getNumPersonas()
{
    return numPersonas;
}

char censo::getPropiedad()
{
    return propiedad;
}

void censo::agregarCenso()
{
    {
        cout << "\nNombre: ";
        setNombre(cin);
        do
        {
            cout << "Edad: ";
            setEdad(cin);
            if (edad <= 0)
            {
                cout << "\nLa edad ingresada es invalida, intente de nuevo.\n";
            }
        } while (edad <= 0);
        cout << "Fecha de Nacimiento\n";
        setFechaNacimiento(cin);
        cout << "Número de Teléfono: ";
        setNumTelefono(cin);
        do
        {
            cout << "Número de personas que viven en el hogar: ";
            setNumPersonas(cin);
            if (numPersonas <= 0)
            {
                cout << "\nLa cantidad de personas ingresada es invalida, intente de nuevo.\n";
            }
        } while (numPersonas <= 0);
        cout << "Propiedad (p/a): ";
        setPropiedad(cin);
        cout << endl;
    }
}
void censo::escribirCensos()
{
    cout << "\nPerfil de " << getNombre() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Fecha de Nacimiento: ";
    getFechaNacimiento();
    cout << "\nNúmero de Teléfono: " << getNumTelefono() << endl;
    cout << "Número de Personas en el Hogar: " << getNumPersonas() << endl;
    cout << "Propiedad: ";
    if (getPropiedad() == 'p')
        cout << "Propietarix" << endl;
    else
        cout << "Alquiler" << endl;
}

int main ()
{
    censo censo[MAX];
    int i = 0;
    char seleccion;
    bool repetir;
    do
    {
        cout << "\nCENSO 2020 MENÚ" << endl;
        cout << "\n(a) Añadir censo";
        cout << "\n(b) Ver todos los censos";
        cout << "\n(c) Terminar" << endl;
        cout << "\nSelección: ";
        cin >> seleccion;
        switch (seleccion)
        {
        case 'a':
            if (i<MAX)
            {
                censo[i].agregarCenso();
                i++;
                repetir = true;
            }
            else 
            {
                cout << "\nUsted ha ingresado la cantidad máxima de censos.\n";
            }
            break;
        case 'b':
            for (int j=0; j<i ; j++)
            {
                censo[j].escribirCensos();
            }
            repetir = true;
            break;
        case 'c':
            cout << "\nGracias por usar este programa.\n";
            repetir = false;
            break;
        default:
            cout << "\nSu selección es iválida, intente de nuevo.\n";
            repetir = true;
            break;
        }
    } while (repetir == true);
return 0;
}
