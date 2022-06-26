//Trabajo Final -HITO 2 - GRUPO 5 (UPC)
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;


#define ANCHO_TABLERO 7
#define ALTO_TABLERO 7
#define PUNTO 'P'
#define LIBRE 'L'

#define JUGADOR1 'X'
#define JUGADOR2 'O'


struct Ficha {
    int posF;
    int posC;
    char color;
    char direccion;
    char tipo;
};

struct Jugador {
    bool turno;
    Ficha* AregloFichas;
    int fichas = 0;
    int movimiento = 1;
};

struct Dato_Pártida {
    char **posiciones;
    string banner;
};



int Menu()
{
    short opcion;
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::White;
  
    cout << endl;

    cout << "\t\tM       M                                 sss\t\t\n"
            "\t\tMM     MM   ooooo   rr  rr  rr  rr  iii  s\t\t\n"
            "\t\tMMM   MMM  oo   oo  rrr     rrr     iii   sss\t\t\n"
            "\t\tMM  M  MM  oo   oo  rr      rr      iii      s\t\t\n"
            "\t\tMM     MM   ooooo   rr      rr      iii   sss\t\t\n" << endl;


    cout << "------------------DESARROLLADORES------------------\n"
        "Brenda Leveau Valdivia , Bryan Leveau Valdivia,\n"
        "Gabriel Mariano Arce Ayala  y Piero Alejandro Huayta Valencia\n"
        "--------------------------------------------------\n" << endl;

    cout << "1) Partida" << endl;
    cout << "2) Instrucciones y reglas" << endl;
    cout << "Seleccione una opción: "; cin >> opcion;

    return opcion;
}

//void jugadores();
//turnos
//estado de jugador

/*
void PosicionarFichas(char** posicion, int nColumnas, int nFilas)//automatico (falta parte de puntos libres)
{
    short turno = 0;
    short cont1 = 0;
    short cont2 = 0;

    int fila = -1;
    int columna = -1;

    srand(time(NULL));
    do {
        turno = rand() % 2; //DEL JUGADOR 1 AL 2
        fila = rand() % 7; //limites de 0 a 6
        columna = rand() % 7;//limites de 0 a 6

        if (posicion[fila][columna] == PUNTO)
        {
            if (turno == 0 && cont1 < 9)
            {
                posicion[fila][columna] = JUGADOR2;
                ++cont1;
            }
            else if (turno == 1 && cont2 < 9)
            {
                posicion[fila][columna] = JUGADOR1;
                    ++cont2;
            }
        }
        if (cont1 >= 9 && cont2 >= 9) break;
    } while (true);

}
*/

void Fichas(char Nombre_Jugador1, char Nombre_Jugador2, char Color_Fichas_Jugador2, char Color_Fichas_Jugador1)
{
    int fichas1, fichas2;
    cin >> Nombre_Jugador1 && Color_Fichas_Jugador1 >> fichas1;
    cin >> Nombre_Jugador2 && Color_Fichas_Jugador2 >> fichas2;

    //cantidad de fichas 
    fichas1 = 9; 
    fichas2 = 9;

    //3_en_raya
    fichas1, fichas2 = 3;
    //Diagonal
    //Horizontal
    //Vertical

    //capturar cuando se tiene 3 en raya

    //registro de movimiento de fichas

    //conteo de fichas

}


//puntos libres que dejan las fichas
//solo aceptar 1 ficha en un punto,no dos

void 
void DibujarTablero(char ** posicion) { //tablero con puntos
    cout << "  0   1   2    3    4   5   6" <<endl;
    cout << "0 " << posicion[0][0] << "------------" << posicion[0][3] << "------------" << posicion[0][6] << endl;
    cout << "  |            |            |" << endl;
    cout << "1 |   " << posicion[1][1] << "--------" << posicion[1][3] << "--------" << posicion[1][5] << "   |" << endl;
    cout << "  |   " << "|" << "        " << "|" << "        " << "|" << "   |" << endl;
    cout << "2 |   " << "|" << "   " << posicion[2][2] << "----" << posicion[2][3] << "----" << posicion[2][4]  << "   " << "|"<< " "<< "  |"<<endl;
    cout << "  |   " << "|" << "   " << "|         |   |   |"<<endl;
    cout << "3 " << posicion[3][0] << "---" << posicion[3][1] << "---" << posicion[3][2] << "         " << posicion[3][4] << "---" << posicion[3][5] << "---" << posicion[3][6] <<endl;
    cout << "  |   " << "|" << "   " << "|         |   |   |" << endl;
    cout << "4 |   " << "|" << "   " << posicion[4][2] << "----" << posicion[4][3] << "----" << posicion[4][4] << "   " << "|" << " " << "  |" << endl;
    cout << "  |   " << "|" << "        " << "|" << "        " << "|" << "   |" << endl;
    cout << "5 |   " << posicion[5][1] << "--------" << posicion[5][3] << "--------" << posicion[5][5] << "   |" << endl;
    cout << "  |            |            |" << endl;
    cout << "6 " << posicion[6][0] << "------------" << posicion[6][3] << "------------" << posicion[6][6] << endl;

}

void InicializarTablero(char** posicion, int nColumnas, int nFilas) //puntos con valor inicial
{
    for (int f = 0; f < nFilas; f++)
        for (int c = 0; c < nColumnas; c++)
        {
            posicion[f][c] = LIBRE;
        }
}


void AsignarMemoriaTablero(char** posicion, int nColumnas, int nFilas) //ubicacion de los puntos en el tablero
{
    for (int f = 0; f < nFilas; f++)
    {
        posicion[f] = new char[nColumnas];
    }
}

void Procesando_Datos_Jugadores(string& nom1, string& nom2, int& color1, int& color2)
{
    Console::Clear();
    //PEDIMOS DATOS AL JUGADOR
    cout << "\t\t/////////////////////////////////////////////\t\t" << endl;
    cout << "\t\t        PROCESANDO DATOS DE JUGADORES\t\t\n";
    cout << "\t\t////////////////////////////////////////////\t\t\n" << endl;
    cout << "+ DATOS DEL JUGADOR 1" << endl;
    cout << "¿Cual es tu nombre Jugador 1?: "; cin >> nom1;
    cout << "¿Que color quieres que se te represente?: "; cin >> color1; cout << endl;
    cout << "+ DATOS DEL JUGADOR 2" << endl;
    cout << "Cual es tu nombre Jugador 2?: "; cin >> nom2;
    cout << "¿Que color quieres que se te represente?: "; cin >> color2; cout << endl;
    _getch();
}

void Partida() {
    string nom1;
    string nom2;
    int color1 = 0;
    int color2 = 0;

    //CODIGO DEL TABLERO

    //char** position;
    //position=new char*[3];
    
   /* for (int i = 0; i < 3; i++)
    {
        position[i] = new int[3];
    }
    */
    Console::Clear();
    //PEDIMOS DATOS AL JUGADOR
    Procesando_Datos_Jugadores(nom1, nom2, color1, color2);


    //DIBUJAR TABLERO
}



void Instrucciones_y_reglas()
{
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::White;
    cout << "Hola! te presentamos los pasos para jugar MORRIS\n"
        "1° PASO: Debes de colocar tus 9 fichas en cualquiera de los puntos disponibles del tablero\n"
        "2° PASO: Una vez las 18 fichas esten colocadas en el tablero, deberás de mover cada una tus fichas hacia otro punto disponible, de manera que tu objetivo sea formar un 3 en raya\n"
        "3 ¿QUÉ ES UN 3 EN RAYA? , pues consiste en formar una línea (horizontal, vetical o diagonal) de 3 fichas y con ello podrás capturar cualquier ficha de tu oponente\n"
        "PIERDE aquel que se no se pueda mover o se quede solo con 2 fichas\n"
        "Buena suerte :)" << endl;

    cout << "\n\nPresione una tecla para continuar..." << endl;
    _getch();
}


void ProcesarOpcion(short opc)
{
    switch (opc)
    {
    case 1: Partida();
        break;
    case 2: Instrucciones_y_reglas();
        break;
    default:
        cout << "Error: ¡¡¡Ingrese una opción valida!!!" << endl;
    }
}


int main()
{
    Console::SetWindowSize(120, 30);
    Console::BackgroundColor = ConsoleColor::DarkBlue;

    locale::global(locale("spanish"));
    short opc;
    //CODIGO DEL TABLERO
    int nFilas = ALTO_TABLERO;
    int nColumnas = ANCHO_TABLERO;

    char** posicion;
    posicion = new char* [nFilas];

    /*
    //CONFIGURACIÓN MENU
    do {

        opc = Menu();
        ProcesarOpcion(opc);

    } while (opc != 2);



    //MemoriadelTablero(Tablero, nColumnas, nFilas);

    //puntos_tablero(Tablero, nFilas, nColumnas);
  */

    Ficha ficha;
    ficha.posF = 0;
    ficha.posC = 0;
    //ficha.direccion = DIR_DER;
    
    string comentario = "Jugando. . .!!!";

    AsignarMemoriaTablero(posicion, nFilas, nColumnas);

    InicializarTablero(posicion, nFilas, nColumnas);
    //PosicionarFichas(posicion, nFilas, nColumnas);
    
   // RegistroPartida(ficha, comentario);

    DibujarTablero(posicion);
    char car = _getch();
    return 0;
}
