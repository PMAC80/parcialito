#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int max_clientes = 100;
int centinela = -1;

struct struc_cliente {
    int codigo;
    string nombre;
    string apellido;
    string domicilio;
};

struct struc_lista_clientes {                 
    struc_cliente lista_clientes[max_clientes];
    int indice;        
};

void cargarLista(struc_lista_clientes& LISTA);
void agregarCliente(struc_lista_clientes& LISTA);              
void eliminarCliente(struc_lista_clientes& LISTA);
void modificarCliente(struc_lista_clientes& LISTA);
void mostrarLista(struc_lista_clientes& LISTA);
void buscarCliente(struc_lista_clientes& LISTA);
void guardarLista(struc_lista_clientes& LISTA);
void clearConsole();
void pauseConsole();

int main()
{
    struc_lista_clientes LISTA;
    LISTA.indice = 0;

    cargarLista(LISTA);

    clearConsole();
    int opcion;

    do
    {
        cout << "----=- Menu Principal -=----" << endl;
        cout << endl;
        cout << "   1. Agregar cliente" << endl;
        cout << "   2. Eliminar cliente" << endl;
        cout << "   3. Modificar cliente" << endl;
        cout << "   4. Mostrar clientes" << endl;
        cout << "   5. Buscar cliente" << endl;
        cout << "   6. Salir del programa" << endl;
        cout << endl;
        cout << "   Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)                                  
        {
            case 1: 
            { 
                agregarCliente(LISTA);              
                break;
            }
            case 2: 
            {   eliminarCliente(LISTA);         
                break;
            }
            case 3: 
            {   modificarCliente(LISTA);         
                break;
            }
            case 4: 
            {   mostrarLista(LISTA);           
                break;
            }
            case 5: 
            {   buscarCliente(LISTA);            
                break;
            }
            case 6: 
            {   guardarLista(LISTA);              
                cout << "Saliendo..." << endl;          
                break;
            }
            default:                                    
            {   cout << "Opción invalida..." << endl;      
                pauseConsole();
                break;
            }
        }

    } while (opcion != 6);

return 0;
}

void cargarLista(struc_lista_clientes& LISTA)
{
    ifstream archivo("listado.txt");

    if (archivo.is_open()) 
        {
            archivo >> LISTA.lista_clientes[LISTA.indice].codigo;
            while ((LISTA.lista_clientes[LISTA.indice].codigo) != centinela) 
            {
                archivo >> LISTA.lista_clientes[LISTA.indice].nombre;
                archivo >> LISTA.lista_clientes[LISTA.indice].apellido;
                archivo >> LISTA.lista_clientes[LISTA.indice].domicilio;
                LISTA.indice++;

                archivo >> LISTA.lista_clientes[LISTA.indice].codigo;
            }
            archivo.close();
        }
    else
        {
            cout << "No se pudo abrir el archivo." << endl;
        }
}

void agregarCliente(struc_lista_clientes& LISTA)
{
    clearConsole();
    if (LISTA.indice <= max_clientes)
        {
            struc_cliente nuevoCliente;

            cout << "Usted va a ingresar un nuevo cliente...." << endl;
            cout << "Ingrese su nombre: "<< endl;
            getline(cin, nuevoCliente.nombre);
            cout << "Ingrese su apellido: "<< endl;
            getline(cin, nuevoCliente.apellido);
            cout << "Ingrese su domicilio: "<< endl;
            getline(cin, nuevoCliente.domicilio);

            //nuevoCliente.codigo = 100 + LISTA.indice;
            if (LISTA.indice == 0)
                nuevoCliente.codigo = 100;
            else
                {
                nuevoCliente.codigo = LISTA.lista_clientes[LISTA.indice - 1].codigo + 1;
                }
            LISTA.lista_clientes[LISTA.indice] = nuevoCliente;
            LISTA.indice++;
            cout << "CUsted a agregado un nuevo cliente con código: " << nuevoCliente.codigo << endl;
            return;
        }
    else
        {
            cout << "No es posible agregar mas clientes." << endl;
        }
}

void eliminarCliente(struc_lista_clientes& LISTA)
{
    int codigo;                                                  
    cout << "Ingrese el código del cliente a eliminar: " << endl;    
    cin >> codigo; 
    cin.ignore();   
    clearConsole();

    for (int i = 0; i < LISTA.indice; i++)       
    {
        if (LISTA.lista_clientes[i].codigo == codigo)            
        {
            for (int j = i; j < LISTA.indice - 1; j++)  
            {
                LISTA.lista_clientes[j] = LISTA.lista_clientes[j + 1];  
            }
            LISTA.indice--;           
            cout << "Cliente eliminado" << endl;
            pauseConsole();
            clearConsole();
            return;
        }
    }
    cout << "Cliente no encontrado." << endl;
    pauseConsole();
    clearConsole();

}

void modificarCliente(struc_lista_clientes& LISTA)
{
        int codigo;                                       
    cout << "Ingrese el código del cliente a modificar: ";
    cin >> codigo;
    clearConsole();
    for (int i = 0; i < LISTA.indice; i++)     
    {
        if (LISTA.lista_clientes[i].codigo == codigo)    
        {
            cout << "El cliente a modificar es: " << endl;
            cout << endl;
            cout << "Código: " << LISTA.lista_clientes[i].codigo << endl;
            cout << "Nombre: " << LISTA.lista_clientes[i].nombre << endl;
            cout << "Apellido: " << LISTA.lista_clientes[i].apellido << endl;
            cout << "Domicilio: " << LISTA.lista_clientes[i].domicilio << endl;
            cout << endl;

            cout << "Ingrese el nuevo nombre del cliente: ";
            cin >> LISTA.lista_clientes[i].nombre;
            cout << "Ingrese el nuevo apellido del cliente: ";
            cin >> LISTA.lista_clientes[i].apellido;
            cout << "Ingrese la nueva ciudad del cliente: ";
            cin >> LISTA.lista_clientes[i].domicilio;
            cout << "Cliente modificado correctamente." << endl;
            pauseConsole();
            clearConsole();
            return;                             
        }
    }
    cout << "Cliente no encontrado." << endl;
    pauseConsole();
    clearConsole();

}

void mostrarLista(struc_lista_clientes& LISTA)
{
        if (LISTA.indice == 0) {
        cout << "No hay clientes registrados." << endl;
    } else {
        for (int i = 0; i < LISTA.indice; i++) 
        {
            cout << "Código   : " << LISTA.lista_clientes[i].codigo << endl;
            cout << "Nombre   : " << LISTA.lista_clientes[i].nombre << endl;
            cout << "Apellido : " << LISTA.lista_clientes[i].apellido << endl;
            cout << "Domicilio: " << LISTA.lista_clientes[i].domicilio << endl;
            cout << "--------------------------" << endl;
        }
    }
}

void buscarCliente(struc_lista_clientes& LISTA)
{
    int codigo;                                                    
    cout << endl << "Ingrese el código del cliente a buscar: ";
    cin >> codigo;
    clearConsole();
    for (int i = 0; i < LISTA.indice; i++)         
    {                                                            
        if (LISTA.lista_clientes[i].codigo == codigo) 
            {
                cout << endl << "Cliente encontrado: " << endl;
                cout << "Código  : " << LISTA.lista_clientes[i].codigo << endl;
                cout << "Nombre  : " << LISTA.lista_clientes[i].nombre << endl;
                cout << "Apellido: " << LISTA.lista_clientes[i].apellido << endl;
                cout << "Ciudad  : " << LISTA.lista_clientes[i].domicilio << endl << endl;
                return;                                               
            }                                                        
    }
    cout << endl << "Cliente no fue encontrado." << endl;
    pauseConsole();
    clearConsole();

}

void guardarLista(struc_lista_clientes& LISTA)
{
        ofstream archivo("listado.txt");
    for (int i = 0; i < LISTA.indice; i++) {
        archivo << LISTA.lista_clientes[i].codigo << " "
                << LISTA.lista_clientes[i].nombre << " "
                << LISTA.lista_clientes[i].apellido << " "
                << LISTA.lista_clientes[i].domicilio << endl;
    }
    archivo << centinela;
    archivo.close();

}


void clearConsole() 
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN64)
        system("cls");
    #endif
}

void pauseConsole()                                        
{
cout << "Presione Enter para continuar..." << endl;
cin.ignore();                                              
cin.get();                                                 
}  