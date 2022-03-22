#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	int INTENTOS,ENTER,BACKSPACE  ;
	INTENTOS =3;
	ENTER =13;
	BACKSPACE = 8;
    vector<string> usuarios;
    vector<string> claves;
    char Opciones;
    string Claves, Nombre, Apellido, Id, Gmail, Carrera, Ticket;
    time_t DateTime = time(NULL);

    // Se añaden usuarios al vector
    usuarios.push_back("luis");
    usuarios.push_back("jorge");
    usuarios.push_back("james");
    usuarios.push_back("johan");
    usuarios.push_back("kevin");

    // Se añaden claves al vector
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");
    claves.push_back("efg");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tINICIO DE SESION" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
    	cout << "\n\n\tBienvenido al sistema" << endl << endl;
	    printf(" Usted ingreso a nuestro sistema a esta hora y a está fecha: %s", ctime(&DateTime));
		cout << endl; 
			
		cout << " Cambie su contraseña por seguridad: "; 
		cin >> Claves;
		cout << endl << endl << endl;
		cout << " Su contraseña se ha actualizado éxitosamente " << endl << endl << endl;
    	do
		{
			int NumTicket = 0;
			
			cout << " Nuestro menú de opcines a realizar es la siguiente: " << endl << endl;
			
			cout << " 1) Subir Ticket: " << endl;
			cout << " 2) Ver tickets: " << endl;
			cout << " 3) Salir: " << endl;
			cout << endl << endl;
			
			cout << " Escoga el número correspondiente a la opción, por favor: "; 
			cin >> Opciones;
			
			if (Opciones == '1'){
				cout << " Nombre: ";
				cin >> Nombre;
				cout << " Apellido: ";
				cin >> Apellido;
				cout << " Id: ";
				cin >> Id;
				cout << " Gmail: ";
				cin >> Gmail;
				cout << " Ticket: ";
				cin >> Ticket;
				
				cout << endl << endl << endl << endl;
				cout << " Datos guardados éxitosamente, gracias!" << endl;
			}
			else if (Opciones == '2'){
				NumTicket = NumTicket + 1;
				
				cout << " No. Ticket: " << NumTicket << endl;
				cout << " Nombre: " << Nombre << endl;
				cout << " Apellido: " << Apellido << endl;
				cout << " Id: " << Id << endl;
				cout << " Gmail: " << Gmail << endl;
				cout << " Ticket: " << Ticket << endl;
			}
			else if (Opciones == '3'){
				cout << " Gracias por utilizar nuestro sistema!" << endl << endl;
				printf(" Usted salió  de nuestro sistema a esta hora y a está fecha: %s", ctime(&DateTime));
			}
			else {
				cout << " El número ingresado no existe, intente de nuevo..." << endl;
			}	
		} while (Opciones == '1' || Opciones == '2');   
    }
    cin.get();
    return 0;
}
