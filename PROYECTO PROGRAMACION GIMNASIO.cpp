#include<iostream>
#include<windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include<fstream>
#include<ctype.h>

#define ENTER 13 
#define BACKSPACE 8
using namespace std;

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void guardar(), buscar(), modificar(), eliminar(), mostrar();

int main(){
	
		vector<string> usuarios;
    vector<string> claves;
    
    // Añadir Usuarios al vector
    usuarios.push_back("carlos");
    usuarios.push_back("christian");
    usuarios.push_back("denis");
    usuarios.push_back("jorge");
    
    // Añadir claves al vector
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("101");   
    
    
    string usuario, password;
    
    int contador = 0;
    bool ingresa = false;
    
    do {
        system("cls");
        
		gotoxy(40,5);  cout << "__________CCDW_COMPANY__________" << endl;
		gotoxy(40,6);  cout << "|                              |" << endl;
		gotoxy(40,7);  cout << "|  -----LOGIN DE USUARIO-----  |" << endl;
        gotoxy(40,8);  cout << "|  --------------------------  |" << endl;
        gotoxy(40,9);  cout << "|                              |" << endl;
		gotoxy(40,10); cout << "|                              |" << endl;
		gotoxy(40,11); cout << "|                              |" << endl;
		gotoxy(40,12); cout << "|                              |" << endl;
		gotoxy(40,13); cout << "|                              |" << endl;
		gotoxy(40,14); cout << "|                              |" << endl;
		gotoxy(40,15); cout << "|______________________________|" << endl;
		
		gotoxy(45,10); cout << "Usuario: ";
        
		getline(cin, usuario);
        
        char caracter;
        
        gotoxy(45,12); cout << "Password: ";
        
        caracter = getch();
        
        password = "";
        
        while (caracter != ENTER) { 
        
            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
                
            } else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            
            caracter = getch();
        }
        
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingresa = true;
                break;
            }
        }
        
        if (!ingresa) {
           gotoxy(40,18); cout << "El Usuario y/o Password Son Incorrectos" << endl;
            cin.get();
            contador++;
        }
        
    } while (ingresa == false && contador < 3);
    
    if (ingresa == false) {
        gotoxy(35,19);cout << "Limite De Solicitudes De Ingreso, Intente Mas Tarde." << endl;
        return 0;
        
    } else {
//-------------------------------------BARRA DE CARGA-------------------------------------------//  
system("cls");  	
int x,y,i,z,a;
 gotoxy(35,10);
 printf("**ACCEDIENDO**");
   
 
 for(i=1; i<90; i++)
 {
  gotoxy(i,13);
  printf("|GYM|%",177);
  
  for(x=50;x<70;x++){
   for(y=1;y<70;y++){
    gotoxy(y,24);
   }
  }
 }
 
//----------------------------------------FIN BARRA DE CARGA-----------------------------------//		
		
		system("cls");
        Sleep(300);
        
        gotoxy(35,3);cout << "      %%                                    ##" << endl;
        gotoxy(35,4);cout << "    %%%%       GGGG   Y    Y  MM   MM       ####" << endl;
        gotoxy(35,5);cout << "  %%%%%%       G       Y  Y   M M M M       ######" << endl;
        gotoxy(35,6);cout << "%%%%%%%%       G  GG    YY    M  M  M       ########" << endl;
		gotoxy(35,7);cout << "  %%%%%%       G   G    YY    M     M       ######" << endl;
        gotoxy(35,8);cout << "    %%%%       GGGGG    YY    M     M       ####" << endl;
        gotoxy(35,9);cout << "      %%                                    ##" << endl;
        
		gotoxy(35,12);cout << "         ----- Bienvenido Al Sistema -----" << endl;
    	gotoxy(35,13);cout<<"\n";
		gotoxy(42,16);system("pause");
	}

    
    
    system("cls");

	
//--------------------------------------MENU PRINCIPAL-------------------------------------------//	
	
	int opc; 
	char opcion[20];
	do{
	system("cls");
	
	gotoxy(32,1);cout << "      %%                                    ##" << endl;
    gotoxy(32,2);cout << "    %%%%       GGGG   Y    Y  MM   MM       ####" << endl;
    gotoxy(32,3);cout << "  %%%%%%       G       Y  Y   M M M M       ######" << endl;
    gotoxy(32,4);cout << "%%%%%%%%       G  GG    YY    M  M  M       ########" << endl;
	gotoxy(32,5);cout << "  %%%%%%       G   G    YY    M     M       ######" << endl;
    gotoxy(32,6);cout << "    %%%%       GGGGG    YY    M     M       ####" << endl;
    gotoxy(32,7);cout << "      %%                                    ##" << endl;

	gotoxy(45,9);cout<<"________CCDW_COMPANY______\n";
	gotoxy(45,10);cout<<"|                         |\n";
	gotoxy(45,11);cout<<"|  1. Guardar Clientes    |\n";
	gotoxy(45,12);cout<<"|  2. Buscar Clientes     |\n";
	gotoxy(45,13);cout<<"|  3. Modificar Clientes  |\n";
	gotoxy(45,14);cout<<"|  4. Anular Clientes     |\n";
	gotoxy(45,15);cout<<"|  5. Mostrar Clientes    |\n";
	gotoxy(45,16);cout<<"|  6. Salir               |\n";
	gotoxy(45,17);cout<<"|_________________________|\n";
	do{
	gotoxy(45,18);cout<<"| Escriba su Opcion:      |\n";
	gotoxy(45,19);cout<<" -------------------------";
		
	gotoxy(67,18);cin>>opcion;
		opc=atoi(opcion);
	}while(opc==0);
	
	
	switch (opc){
		case 1:{
		guardar();
			break;
		}
		case 2:{
		buscar();
			break;
		}
		case 3:{
		modificar();
			break;
		}
		case 4:{
			eliminar();
			break;
		}
		case 5:{
			mostrar();
			break;
		}
		case 6:{
			Sleep(300);
			system("cls");
			gotoxy(20,9); cout << "-----              SOFTWARE UMG REALIZADO POR              -----" << endl;
			gotoxy(20,10);cout << "-----    Carlos Junior Lopez Alvarado      | 0904-20-4091  -----" << endl;
    		gotoxy(20,11);cout << "----- Christian Jimmy Leonel Palacios Cruz | 0904-20-6232  -----" << endl;
    		gotoxy(20,12);cout << "-----    Denis Gerardi Mendoza Cobon       | 0904-20-4097  -----" << endl;
    		gotoxy(20,13);cout << "-----   Jorge William Villatoro Avila      | 0904-20-1700  -----" << endl;    		
			gotoxy(20,14);cout << "                                           |  CCDW.Company -----" << endl;
			
			gotoxy(20,15);system("pause");
			break;
		}
		default:{
			gotoxy(15,12);cout<<"Opcion no encontrada\n";
			break;
		}
	}
}while(opc!=6);
}

//---------------------------------------------------GUARDAR--------------------------------------//
void guardar()
{
	string meses[12]={"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
	int codigo;
	string nombre;
	string apellido;
	int dia;
	int mes;
	bool estado;
	int vector_dias_mes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool valido=true;
	ofstream archivo;
		system("cls");
		archivo.open("gym.txt",ios::app);
		cout<<"Ingrese el codigo: ";
		cin>>codigo;
		cin.ignore();
		cout<<"Ingrese Nombre Del Nuevo Cliente: ";
		getline(cin, nombre);
		cout<<"Ingrese Apellido del Nuevo Cliente: ";
		getline(cin, apellido);
		
		do
	{
		cout<<"Ingrese el Mes en numero: ";
		cin>>mes;
		cin.ignore();
		if((mes>12)||(mes<1))
		{
			valido=false;
			cout<<"El mes ingresado no es valido"<<endl;
		}
		else
		{
			valido=true;
			cout<<"Ingrese el Dia: ";
			cin>>dia;
			cin.ignore();
			if((dia<1)||(dia>vector_dias_mes[mes-1]))
			{
				valido=false;
				cout<<"El dia ingresado no es valido"<<endl;
			}
			else
			{
				valido=true;
			}
		}
	}while(valido==false);
	
		estado=true;
		
		archivo<<codigo<<","<<nombre<<","<<apellido<<","<<dia<<","<<meses[mes-1]<<","<<estado<<endl;
		archivo.close();
		system("pause");
}
//---------------------------------------BUSCAR-----------------------------------------------//
void buscar()
{
	int codigo, dia, cod;
	char linea[120], nombre[20], apellido[20], mes[15];
	bool estado;
	bool registro=false;
	system("cls");
	cout<<"Ingrese codigo a buscar: ";
	cin>>cod;
	cin.ignore();
	
	ifstream Leer;
	system("cls");
	Leer.open("gym.txt");
	Leer.getline(linea,sizeof(linea));
		while(!Leer.eof())
		{
		for(int i=0;i<6;i++)
		{
			char *puntero;
			if(i==0)
			{
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}
			else if(i==1)
			{
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}
			else if(i==2)
			{
				puntero=strtok(NULL,",");
				strcpy(apellido,puntero);
			}
			else if(i==3)
			{
				puntero=strtok(NULL,",");
				dia=atoi(puntero);
			}
			else if(i==4)
			{
				puntero=strtok(NULL,",");
				strcpy(mes,puntero);
			}
			else if(i==5)
			{
				puntero=strtok(NULL,",");
				estado=atoi(puntero);
			}
		}
	if(cod==codigo){
	if(estado==false){
		cout<<"Codigo de Cliente Inactivo"<<endl;
		//registro=true;
	}else{
		
		
		gotoxy(5,3); cout<<" _________________________________________________________________________________________";
		gotoxy(5,4); cout<<" |                                  CCDW_COMPANY                                         |";
		gotoxy(5,5); cout<<" |---------------------------------------------------------------------------------------|";
		gotoxy(5,6); cout<<" | CODIGO | NOMBRE DEL CLIENTE | APELLIDO DEL CLIENTE | DIA DE PAGO | MES DE INSCRIPCION |";
		gotoxy(5,7); cout<<" |---------------------------------------------------------------------------------------|";
		gotoxy(5,8); cout<<" |        |                    |                      |             |                    |";
		gotoxy(5,9); cout<<" |        |                    |                      |             |                    |";
		gotoxy(5,10);cout<<" |________|____________________|______________________|_____________|____________________|";	
		
		gotoxy(10,9);cout<<codigo;
		gotoxy(17,9);cout<<nombre;
		gotoxy(38,9);cout<<apellido;
		gotoxy(65,9);cout<<dia;
		gotoxy(80,9);cout<<mes<<endl<<endl<<endl;
	

	registro=true;		
	}	
	
	}
	
	Leer.getline(linea,sizeof(linea));
	}
	if(registro==false){
		cout<<"No se encontro el registro "<<endl;
	}
	Leer.close();
	system("pause");
}


//-----------------------------MODIFICAR---------------------------------//
void modificar(){
	int codigo, dia;
	int cod, diaDos, mesDos;
	int vector_dias_mes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool valido;
	char linea[120], nombre[20], apellido[20], mes[15];
	bool estado;
	bool estadoDos=true;
	string nombreDos, apellidoDos, meses[12]={"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	system("cls");
	Leer.open("gym.txt");
	Temp.open("gymDos.txt");
	cout<<"Ingrese un codigo a Modificar: ";
	cin>>cod;
	cin.ignore();
	cout<<"Ingrese Nuevo Nombre del Cliente: ";
	getline(cin, nombreDos);
	cout<<"Ingrese Nuevo Apellido del Cliente: ";
	getline(cin, apellidoDos);
	do
	{
		cout<<"Ingrese el Mes en numero: ";
		cin>>mesDos;
		cin.ignore();
		if((mesDos>12)||(mesDos<1))
		{
			valido=false;
			cout<<"**El mes ingresado no es valido**"<<endl;
		}
		else
		{
			valido=true;
			cout<<"Ingrese el Dia: ";
			cin>>diaDos;
			cin.ignore();
			if((diaDos<1)||(diaDos>vector_dias_mes[mesDos-1]))
			{
				valido=false;
				cout<<"**El dia ingresado no es valido**"<<endl;
			}
			else
			{
				valido=true;
			}
		}
	}while(valido==false);

	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof())
		{
		for(int i=0;i<6;i++)
		{
			char *puntero;
			if(i==0)
			{
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}
			else if(i==1)
			{
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}
			else if(i==2)
			{
				puntero=strtok(NULL,",");
				strcpy(apellido,puntero);
			}
			else if(i==3)
			{
				puntero=strtok(NULL,",");
				dia=atoi(puntero);
			}
			else if(i==4)
			{
				puntero=strtok(NULL,",");
				strcpy(mes,puntero);
			}
			else if(i==5)
			{
				puntero=strtok(NULL,",");
				estado=atoi(puntero);
			}
		}
		if(cod==codigo)
		{
			bandera=true;
			
		gotoxy(5,7);  cout<<" _________________________________________________________________________________________";
		gotoxy(5,8);  cout<<" |                                  CCDW_COMPANY                                         |";
		gotoxy(5,9);  cout<<" |---------------------------------------------------------------------------------------|";
		gotoxy(5,10); cout<<" | CODIGO | NOMBRE DEL CLIENTE | APELLIDO DEL CLIENTE | DIA DE PAGO | MES DE INSCRIPCION |";
		gotoxy(5,11); cout<<" |---------------------------------------------------------------------------------------|";
		gotoxy(5,12); cout<<" |        |                    |                      |             |                    |";
		gotoxy(5,13); cout<<" |        |                    |                      |             |                    |";
		gotoxy(5,14); cout<<" |________|____________________|______________________|_____________|____________________|";	
		
		gotoxy(10,13);cout<<codigo;
		gotoxy(17,13);cout<<nombreDos;
		gotoxy(38,13);cout<<apellidoDos;
		gotoxy(65,13);cout<<diaDos;
		gotoxy(80,13);cout<<meses[mesDos-1]<<endl<<endl<<endl;
			

			Leer.getline(linea,sizeof(linea));
			Temp<<codigo<<","<<nombreDos<<","<<apellidoDos<<","<<diaDos<<","<<meses[mesDos-1]<<","<<estadoDos<<endl;
			}
		else
		{
			Leer.getline(linea,sizeof(linea));
			Temp<<codigo<<","<<nombre<<","<<apellido<<","<<dia<<","<<mes<<","<<estado<<endl;
		}
	}
	if(bandera==false)
	{
		cout<<"El registro no existe"<<endl;
	}
	Leer.close();
	Temp.close();
	remove("gym.txt");
	rename("gymDos.txt","gym.txt");
	system("pause");		
}

//-----------------------------ELIMINAR---------------------------------//
void eliminar(){
	int codigo, dia;
	int cod;
	char linea[120], nombre[20], apellido[20], mes[15];
	bool estado;
	bool estadoDos=false;
	string nombreDos, apellidoDos;
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	system("cls");
	Leer.open("gym.txt");
	Temp.open("gymDos.txt");
	cout<<"Ingrese un codigo a eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof())
		{
		for(int i=0;i<6;i++)
		{
			char *puntero;
			if(i==0)
			{
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}
			else if(i==1)
			{
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}
			else if(i==2)
			{
				puntero=strtok(NULL,",");
				strcpy(apellido,puntero);
			}
			else if(i==3)
			{
				puntero=strtok(NULL,",");
				dia=atoi(puntero);
			}
			else if(i==4)
			{
				puntero=strtok(NULL,",");
				strcpy(mes,puntero);
			}
			else if(i==5)
			{
				puntero=strtok(NULL,",");
				estado=atoi(puntero);
			}
		}
		if(cod==codigo)
		{
			bandera=true;
			
			gotoxy(5,7);  cout<<" _________________________________________________________________________________________";
			gotoxy(5,8);  cout<<" |                                  CCDW_COMPANY                                         |";
			gotoxy(5,9);  cout<<" |---------------------------------------------------------------------------------------|";
			gotoxy(5,10); cout<<" | CODIGO | NOMBRE DEL CLIENTE | APELLIDO DEL CLIENTE | DIA DE PAGO | MES DE INSCRIPCION |";
			gotoxy(5,11); cout<<" |---------------------------------------------------------------------------------------|";
			gotoxy(5,12); cout<<" |        |                    |                      |             |                    |";
			gotoxy(5,13); cout<<" |        |                    |                      |             |                    |";
			gotoxy(5,14); cout<<" |________|____________________|______________________|_____________|____________________|";	
		
			gotoxy(10,13);cout<<codigo;
			gotoxy(17,13);cout<<nombre;
			gotoxy(38,13);cout<<apellido;
			gotoxy(65,13);cout<<dia;
			gotoxy(80,13);cout<<mes<<endl<<endl<<endl;
			
			
			Leer.getline(linea,sizeof(linea));
			Temp<<codigo<<","<<nombre<<","<<apellido<<","<<dia<<","<<mes<<","<<estadoDos<<endl;
			}
		else
		{
			Leer.getline(linea,sizeof(linea));
			Temp<<codigo<<","<<nombre<<","<<apellido<<","<<dia<<","<<mes<<","<<estado<<endl;
		}
	}
	if(bandera==false)
	{
		cout<<"El registro no existe"<<endl;
	}
	Leer.close();
	Temp.close();
	remove("gym.txt");
	rename("gymDos.txt","gym.txt");
	system("pause");		
}


//------------------------------------MOSTRAR TODOS-------------------------------------------//
void mostrar()
{
	int codigo, dia;
	char linea[120], nombre[20], apellido[20], mes[15];
	bool estado;
	bool eleccion;
	system("cls");
	cout<<"Desea ver los registros Activos o Inactivos? "<<endl;
	cout<<"1.) Para Activos Escriba 1"<<endl;
	cout<<"2.) Para Inactivos Escriba 0"<<endl;
	cout<<"Escriba su Eleccion: ";
	cin>>eleccion;
	ifstream Leer;
	system("cls");
	Leer.open("gym.txt");
	Leer.getline(linea,sizeof(linea));
		while(!Leer.eof())
		{
		for(int i=0;i<6;i++)
		{
			char *puntero;
			if(i==0)
			{
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}
			else if(i==1)
			{
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}
			else if(i==2)
			{
				puntero=strtok(NULL,",");
				strcpy(apellido,puntero);
			}
			else if(i==3)
			{
				puntero=strtok(NULL,",");
				dia=atoi(puntero);
			}
			else if(i==4)
			{
				puntero=strtok(NULL,",");
				strcpy(mes,puntero);
			}
			else if(i==5)
			{
				puntero=strtok(NULL,",");
				estado=atoi(puntero);
			}
		}
		
	if((eleccion==true)&&(estado==true)){
		
		cout<<" ________________________________________________"<<endl;
		cout<<" |          CCDW_COMPANY CLIENTE ACTIVO         |"<<endl;
		cout<<" |----------------------------------------------|"<<endl;
		cout<<" | CODIGO               | "<<codigo<<endl;
		cout<<" | NOMBRE DEL CLIENTE   | "<<nombre<<endl;
		cout<<" | APELLIDO DEL CLIENTE | "<<apellido<<endl;
		cout<<" | DIA DE PAGO          | "<<dia<<endl;
		cout<<" | MES DE INSCRIPCION   | "<<mes<<endl;	
		cout<<" |______________________________________________|"<<endl<<endl;
	
	}else if((eleccion==false)&&(estado==false)){
		
		cout<<" ________________________________________________"<<endl;
		cout<<" |        CCDW_COMPANY CLIENTE INACTIVO         |"<<endl;
		cout<<" |----------------------------------------------|"<<endl;
		cout<<" | CODIGO               | "<<codigo<<endl;
		cout<<" | NOMBRE DEL CLIENTE   | "<<nombre<<endl;
		cout<<" | APELLIDO DEL CLIENTE | "<<apellido<<endl;
		cout<<" | DIA DE PAGO          | "<<dia<<endl;
		cout<<" | MES DE INSCRIPCION   | "<<mes<<endl;	
		cout<<" |______________________________________________|"<<endl<<endl;
	}	
	
	Leer.getline(linea,sizeof(linea));
	}
	Leer.close();
	system("pause");
}



