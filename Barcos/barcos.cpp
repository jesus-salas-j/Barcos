#include "stdio.h"
//#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#include "conio.h"

#define TAM_TABLERO 8
#define NUM_BARCOS 5
#define COORD_BARCO 4
#define HORIZONTAL 0
#define VERTICAL 1
#define LETRAS 0
#define NUMEROS 1

#define AGUA 0
#define YA_DISPARADO 1
#define TOCADO 2
#define HUNDIDO 3

#define ROJO 4
#define AMARILLO 6
#define VERDE_C 10
#define AZUL_C 11
#define ROJO_C 12
#define AMARILLO_C 14
#define BLANCO 15
#define AMARILLO_VERDE 62

#define TECLA_INTRO 13

/* Establece el color del texto de la consola */
/* @param color : color del texto             */
void setColor( int color )                 
{                   

    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);

}

/* Posiciona el cursor en una posicion determinada de la consola */
/* @param x : posicion cursor eje x                              */
/* @param y : posicion cursor eje y                              */
void gotoxy( int x, int y )
{

    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);

}

/* Hace visible o invisible el cursor                       */
/* @param estado : true ---> el cursor se ve en la pantalla */
/*                 false --> el cursor no se ve en pantalla */
void cursorVisible( bool estado ) {

	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 20;
	cursor.bVisible = estado;;
	SetConsoleCursorInfo(consola, &cursor);

}

/* Visualiza la pantalla principal de presentacion del juego */
/* y permite elegir entre 1 y 2 jugadores                    */
/* return (int) : devuelve el numero de jugadores (1 o 2)    */
int pantallaInicio( void ) {

	char tecla;
	int opcion;
		
	setColor(BLANCO);
	system("cls");

	printf("????????????????????????????????????????\n");
	printf("???????????????? ~~+????????????????????\n");
	printf("????????????????? ??????????????????????\n");
	printf("???????????????~~~:=????????????????????\n");
	printf("?????????????? ~+~~+????????????????????\n");
	printf("??????????????~+~~:=????????????????????\n");
	printf("?????????????? :~~:~~,??????????????????\n");
	printf("????????:??+??:::::~~~==???????????~????\n");
	printf("???????????:,+=:,,:,:~:=:???????????????\n");
	printf("++++++++?+:~~..:=:~:=.,::,:,+=:,,,,,????\n");
	printf("+++++++++:~~~.,,~~.,..,,:,,,,,,,..,.????\n");
	printf("+++++++,:::~,,~,~,,,,,,,,,,,,,,.,,:+++?+\n");
	printf("==?~+=~~~~~~~::,,,,,,,,,....,,,,,:+=+==+\n");
	printf("======~~~:::::,:,,,,,,........,,,+++++++\n");
	printf("+++=+=~~::,,,,,,.,:,..,,..,.,,,,=+++++++\n");
	printf("===========~~~~::::,,,,,,,,,,,,,===+=+++\n");
	printf("==============~~~~:~~~=~~=~~:~:::~~==+=+\n");

	setColor(AMARILLO_VERDE);
	gotoxy(22, 0);
	printf("                 ");
	gotoxy(22, 1);
	printf(" HUNDIR LA FLOTA ");
	setColor(AMARILLO_VERDE);
	gotoxy(22, 2);
	printf("                 ");
	gotoxy(8, 15);
	printf("     1 JUGADOR     ");
	setColor(BLANCO);
	gotoxy(8, 16);
	printf("     2 JUGADORES   ");

	cursorVisible(false);
	opcion = 1;
	tecla = getch();
	while( tecla != (char)13 ) {
		switch( tecla ) {
			case (char)72:
				if( opcion == 1 ) {
					setColor(BLANCO);
					gotoxy(8, 15);
					printf("     1 JUGADOR     ");
					setColor(AMARILLO_VERDE);
					gotoxy(8, 16);
					printf("     2 JUGADORES   ");
					opcion = 2;
				}
				else {	
					setColor(AMARILLO_VERDE);
					gotoxy(8, 15);
					printf("     1 JUGADOR     ");
					setColor(BLANCO);
					gotoxy(8, 16);
					printf("     2 JUGADORES   ");
					opcion = 1;
				}
				break;
			case (char)80:
				if( opcion == 1 ) {
					setColor(BLANCO);
					gotoxy(8, 15);
					printf("     1 JUGADOR     ");
					setColor(AMARILLO_VERDE);
					gotoxy(8, 16);
					printf("     2 JUGADORES   ");
					opcion = 2;
				}
				else {	
					setColor(AMARILLO_VERDE);
					gotoxy(8, 15);
					printf("     1 JUGADOR     ");
					setColor(BLANCO);
					gotoxy(8, 16);
					printf("     2 JUGADORES   ");
					opcion = 1;
				}
				break; 
		}
		tecla = getch();
		
	}
	cursorVisible(true);
	return opcion;             

}

/* Dibuja la pantalla de juego (sin los tableros) */
void dibujaPantallaPrincipal( int num_jug ) {

	int i;

	setColor(BLANCO);
	system("cls");
	gotoxy(0, 0);
	printf("%c", (char)201);
	for( i=0; i<70; i++ ) {
		printf("%c", (char)205);
	}
	printf("%c\n", (char)187);
	for( i=1; i<28; i++ ) {
		printf("%c", (char)186);
		gotoxy(71, i);
		printf("%c\n", (char)186);
	}
	printf("%c", (char)204);
	for( i=0; i<70; i++ ) {
		printf("%c", (char)205);
	}
	printf("%c\n", (char)185);
	printf("%c", (char)186);
	gotoxy(71, 29);
	printf("%c\n", (char)186);
	printf("%c", (char)186);
	gotoxy(71, 30);
	printf("%c\n", (char)186);
	printf("%c", (char)186);
	gotoxy(71, 31);
	printf("%c\n", (char)186);
	printf("%c", (char)200);
	for( i=0; i<70; i++ ) {
		printf("%c", (char)205);
	}
	printf("%c", (char)188);	

	setColor(AMARILLO_C);
	gotoxy(6, 2); printf("JUGADOR 1");
	setColor(ROJO_C);
	gotoxy(40, 2);
	if( num_jug == 1 ) printf("ORDENADOR");
	else printf("JUGADOR 2");

}

/* Dibuja un tablero del tamaño y en la posicion especificados */
/* @param posx : Posicion eje x del tablero en pantalla        */
/* @param posy : Posicion eje y del tablero en pantalla        */
/* @param tam : Tamaño del tablero, tendra tam x tam casillas  */
void dibujaTablero( int posx, int posy, int tam ) {

	int i, j;
	char letra;

	setColor(BLANCO);
	letra = '1';
	gotoxy(posx, posy);
	for( i=1; i<=tam; i++ ) {
		printf("  %c", letra);
		letra = (char)((int)letra + (int)1);
	}

	gotoxy(posx, posy + 1);
	printf(" %c", (char)218);
	for( i=0; i<(tam - 1); i++ ) {
		printf("%c%c%c", (char)196, (char)196, (char)194);
	}
	printf("%c%c%c", (char)196, (char)196, (char)191);

	letra = 'A';
	for( j=0; j<(tam - 1); j++ ) {		
		gotoxy(posx, posy + 2 + 2*j);
		printf("%c", letra);
		letra = (char)((int)letra + (int)1);
		for( i=0; i<(tam + 1); i++ ) {
			printf("%c  ", (char)179);
		}
		gotoxy(posx, posy + 3 + 2*j);
		printf(" %c", (char)195);
		for( i=0; i<(tam - 1); i++ ) {
			printf("%c%c%c", (char)196, (char)196, (char)197);
		}
		printf("%c%c%c", (char)196, (char)196, (char)180);
	}

	gotoxy(posx, posy + 2 + 2*j);
	printf("%c", letra);
	for( i=0; i<(tam + 1); i++ ) {
			printf("%c  ", (char)179);
	}
	gotoxy(posx, posy + 3 + 2*j);
	printf(" %c", (char)192);
	for( i=0; i<(tam - 1); i++ ) {
		printf("%c%c%c", (char)196, (char)196, (char)193);
	}
	printf("%c%c%c", (char)196, (char)196, (char)217);

}

/* Visualiza un mensaje en el cuadro de mensajes           */
/* @param mensj[] : texto del mensaje a visualizar         */
/* @param color : color del texto del mensaje a visualizar */
void mensaje( char mensj[], int color ) {

	setColor(color);
	gotoxy(4, 30);
	printf("                                                            ");
	gotoxy(4, 30);
	printf("%s", mensj);
	setColor(BLANCO);

}

/* Borra la zona de texto donde se piden las coordenadas de los barcos */
/* y las posiciones de estos al colocarlos, zona bajo los tableros     */
void limpiaZonaTexto( void ) {

	gotoxy(7, 23);
	printf("                                                            ");
	gotoxy(7, 24);
	printf("                                                            ");
	gotoxy(7, 25);
	printf("                                                            ");
	gotoxy(7, 26);
	printf("                                                            ");
	gotoxy(40, 23);
	printf("                              ");
	gotoxy(40, 24);
	printf("                              ");

}

/* Posiciona un barco en una posicion aleatoria, se usa cuando juega   */
/* la CPU en el modo 1 jugador (no visualiza el barco en pantalla)     */
/* @param tablero[][] : contenido de las casillas del tablero          */
/* @param barcos[][] : posicion y tamaño de todos los barcos de la CPU */
/* @param tam_barco : tamaño del barco a colocar                       */
/* @cod_barco : codigo unico para este barco                           */
void colocaBarcoAleatorio( int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO], int tam_barco, int cod_barco ) {

	int posx, posy, i, cont;
	int orientacion;            

	srand(time(NULL));

	cont = 0;
	while( cont < tam_barco ) {
		posx = rand()%TAM_TABLERO;
		posy = rand()%TAM_TABLERO;
		orientacion = rand()%2;
		if( orientacion == VERTICAL ) {
			while( posy > (TAM_TABLERO - tam_barco) ) {
				posy = rand()%TAM_TABLERO;
			}
		}
		else {
			while( posx > (TAM_TABLERO - tam_barco) ) {
				posx = rand()%TAM_TABLERO;
			}
		}

		cont = 0;
		if( orientacion == VERTICAL ) {
			while( (tablero[posx][posy + cont] == 0) && (cont < tam_barco) ) {        /* agua */
				cont++;
			}
			if( cont == tam_barco ) {
				for( i=0; i<tam_barco; i++ ) {
					tablero[posx][posy + i] = cod_barco;
				}
			}
		}
		else {
			while( (tablero[posx + cont][posy] == 0) && (cont < tam_barco) ) {        /* agua */
				cont++;
			}
			if( cont == tam_barco ) {
				for( i=0; i<tam_barco; i++ ) {
					tablero[posx + i][posy] = cod_barco;
				}
			}
		}

		if( cont == tam_barco ) {
			barcos[cod_barco - 1][0] = posx;
			barcos[cod_barco - 1][1] = posy;
			if( orientacion == VERTICAL ) {
				barcos[cod_barco - 1][2] = posx;
				barcos[cod_barco - 1][3] = posy + i - 1;
			}
			else {
				barcos[cod_barco - 1][2] = posx + i - 1;
				barcos[cod_barco - 1][3] = posy;
			}

		}

	}
	
}

/* Coloca un barco en el tablero en una posicion determinada si es posible */
/* @param tablero[][] : contenido de las casilllas del tablero             */
/* @param barcos[][] : posicion y tamaño de todos los barcos del jugador   */
/* @param posx_barco : posicion eje x donde se colocara el barco           */
/* @param posy_barco : posicion eje y donde se colocara el barco           */
/* @param tam_barco : tamaño que tendra el barco                           */
/* @param cod_barco : codigo unico del barco                               */
/* @param orientacion : posicionamiento del barco, vertical o horizontal   */
bool colocaBarco( int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO], 
	int posx_barco, int posy_barco, int tam_barco, int cod_barco, int orientacion ) {

	bool colocado;
	int cont, i;
	char msj[] = "Posicion no valida!!";
	char msj_vacio[] = "                         ";

	colocado = false;
	cont = 0;
	if( orientacion == VERTICAL ) {
		if( (TAM_TABLERO - posy_barco) >= tam_barco ) {
			while( (tablero[posx_barco][posy_barco + cont] == 0) && (cont < tam_barco) ) {        /* agua */
				cont++;
			}
			if( cont == tam_barco ) {
				for( i=0; i<tam_barco; i++ ) {
					tablero[posx_barco][posy_barco + i] = cod_barco;
				}
			}
		}
	}
	else {
		if( (TAM_TABLERO - posx_barco) >= tam_barco ) {
			while( (tablero[posx_barco + cont][posy_barco] == 0) && (cont < tam_barco) ) {        /* agua */
				cont++;
			}
			if( cont == tam_barco ) {
				for( i=0; i<tam_barco; i++ ) {
					tablero[posx_barco + i][posy_barco] = cod_barco;
				}
			}
		}
	}

	if( cont == tam_barco ) {
		colocado = true;
		mensaje(msj_vacio, 15);
		barcos[cod_barco - 1][0] = posx_barco;
		barcos[cod_barco - 1][1] = posy_barco;
		if( orientacion == VERTICAL ) {
			barcos[cod_barco - 1][2] = posx_barco;
			barcos[cod_barco - 1][3] = posy_barco + i - 1;
		}
		else {
			barcos[cod_barco - 1][2] = posx_barco + i - 1;
			barcos[cod_barco - 1][3] = posy_barco;
		}
	}
	else mensaje(msj, ROJO_C);

	return colocado;

}


/* Coloca todos los barcos de la CPU mediante llamadas a la funcion colocaBarcoAleatorio */
/* @param tablero[][] : contenido de las casillas del tablero                            */
/* @param barcos[][] : tamaño y posicion de todos los barcos de un jugador               */
void posicionarBarcosCPU( int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO] ) {

	colocaBarcoAleatorio(tablero, barcos, 5, 1);     /* Barco de 5 casillas de longitud, codigo de barco 1 */
	colocaBarcoAleatorio(tablero, barcos, 4, 2);
	colocaBarcoAleatorio(tablero, barcos, 3, 3);
	colocaBarcoAleatorio(tablero, barcos, 3, 4);
	colocaBarcoAleatorio(tablero, barcos, 2, 5);

}

/* Inicializa todas las casillas del tablero a AGUA           */
/* @param tablero[][] : contenido de las casillas del tablero */
void inicializarTablero( int tablero[][TAM_TABLERO] ) {

	int x, y;

	for( y=0; y<TAM_TABLERO; y++ ) {
		for( x=0; x<TAM_TABLERO; x++ ) {
			tablero[y][x] = 0;
		}
	}
}

/* Determina si una tecla es valida o no                                         */
/* @param tecla : tecla pulsada por el usuario                                   */
/* @param tipo : puede ser una letra o un numero                                 */
/* return (bool) : devuelve true si la tecla es valida y false en caso contrario */
bool teclaValida( char tecla, int tipo ) {

	bool es_valida;

	if( tipo == LETRAS ) {
		if( ((int)tecla >= 'A') && ((int)tecla <= 'H') ) {
			es_valida = true;
		}
		else if( ((int)tecla >= 'a') && ((int)tecla <= 'h') ) {
			es_valida = true;
		}
		else {
			es_valida = false;
		}
	}
	else {
		if( ((int)tecla >= '1') && ((int)tecla <= '8') ) {
			es_valida = true;
		}
		else {
			es_valida = false;
		}
	}

	if( !es_valida ) printf("\a");

	return es_valida;

}

/* Pide una nueva jugada (disparo) de un jugador        */
/* @param *jugx : coordenada eje x del disparo          */
/* @param *jugy : coordenada eje y del disparo          */
/* @param posx : posicion eje x del tablero en pantalla */
/* @param posy : posicion eje y del tablero en pantalla */
void pideJugada( int *jugx, int *jugy, int posx, int posy ) {

	bool tecla_valida;
	char tecla;

	limpiaZonaTexto();
	gotoxy(posx + 3, posy + 19);
	setColor(BLANCO);
	printf("Coordenada X (1-8):    ");
	gotoxy(posx + 23, posy + 20);  /* Limpia coordenada y */
	printf("   ");
	gotoxy(posx + 23, posy + 19);
	tecla = getch();	
	while( !teclaValida(tecla, NUMEROS) ) {
		tecla = getch();
	}
	printf("%c", tecla);
	*jugx = (int)tecla - (int)'1';

	gotoxy(posx + 3, posy + 20);
	printf("Coordenada Y (A-H):    ");
	gotoxy(posx + 23, posy + 20);
	tecla = getch();
	while( !teclaValida(tecla, LETRAS) ) {
		tecla = getch();
	}
	printf("%c", tecla);
	if( (int)tecla < (int)'a' ) *jugy = (int)tecla - (int)'A';   /* Mayuscula */
	else *jugy = (int)tecla - (int)'a';                          /* Minuscula */

}

/* Visualiza en el tablero un barco recien colocado por un jugador */
void visualizarBarco( int posx_tablero, int posy_tablero, int barcos[][COORD_BARCO], 
	int cod_barco ) {

	int tam_barco, posx_barco, posy_barco, i;

	posx_barco = barcos[cod_barco - 1][0] + 1;
	posy_barco = barcos[cod_barco - 1][1] + 1;
	setColor(AMARILLO_C);	
	if( barcos[cod_barco - 1][0] == barcos[cod_barco - 1][2] ) {   /* Barco en vertical */
		tam_barco =  barcos[cod_barco - 1][3] -  barcos[cod_barco - 1][1] + 1;
		for( i=0; i<tam_barco; i++ ) {
			gotoxy(posx_tablero + 3*posx_barco - 1, posy_tablero + 2*posy_barco + 2*i);
			printf("%c%c", (char)219, (char)219);
		}
	}
	else {     /* Barco en horizontal */
		tam_barco =  barcos[cod_barco - 1][2] -  barcos[cod_barco - 1][0] + 1;
		for( i=0; i<tam_barco; i++ ) {
			gotoxy(posx_tablero + 3*posx_barco - 1 + 3*i, posy_tablero + 2*posy_barco);
			printf("%c%c", (char)219, (char)219);
		}
	}

}

void ocultarBarcos( int posx_tablero, int posy_tablero ) {

	int x, y;

	setColor(BLANCO);
	for( y=1; y<=TAM_TABLERO; y++ ) {
		for( x=1; x<=TAM_TABLERO; x++ ) {
			gotoxy(posx_tablero + 3*x - 1, posy_tablero + 2*y);
			printf("  ");
		}
	}

}

/* Pide las posiciones de sus barcos a un jugador antes de iniciar la partida */
void pidePosicBarcos( int num_jug, int posx_tablero, int posy_tablero, 
	int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO] ) {

	char tecla;
	int tam_barcos[NUM_BARCOS];
	int i, posx_barco, posy_barco, orientacion;
	bool barco_colocado;
	char msj[] = "Barcos colocados! Pulsa una tecla para continuar";

	tam_barcos[0] = 5;
	tam_barcos[1] = 4;
	tam_barcos[2] = 3;
	tam_barcos[3] = 3;
	tam_barcos[4] = 2;

	if( num_jug == 1 ) setColor(AMARILLO_C);
	else setColor(ROJO_C);
	gotoxy(7, 23);
	printf("Posiciona tus barcos jugador %i:", num_jug);
	for( i=0; i<NUM_BARCOS; i++ ) {

		barco_colocado = false;
		while( !barco_colocado ) {

			/* Se piden las coordenadas del barco y su orientacion (vertical/horizontal) */
			setColor(BLANCO);
			gotoxy(9, 24);
			printf("Coordenada X (1-8):    ");	
			gotoxy(29, 24);
			tecla = getch();	
			while( !teclaValida(tecla, NUMEROS) ) {
				tecla = getch();
			}
			setColor(AZUL_C); printf("%c", tecla); setColor(BLANCO);
			posx_barco = (int)tecla - (int)'1' + 1;

			gotoxy(9, 25);
			printf("Coordenada Y (A-H):    ");	
			gotoxy(29, 25);
			tecla = getch();	
			while( !teclaValida(tecla, LETRAS) ) {
				tecla = getch();
			}
			setColor(AZUL_C); printf("%c", tecla); setColor(BLANCO);
			if( (int)tecla < (int)'a' ) posy_barco = (int)tecla - (int)'A' + 1;   /* Mayuscula */
			else posy_barco = (int)tecla - (int)'a' + 1;                          /* Minuscula */

			gotoxy(9, 26);
			printf("Orientacion vertical (V) - horizontal (H):    ");
			gotoxy(52, 26);
			tecla = getch();	
			while( (tecla != 'V') && (tecla != 'v') && (tecla != 'H') && (tecla != 'h') ) {
				tecla = getch();
			}
			setColor(AZUL_C); printf("%c", tecla); setColor(BLANCO);
			if( (tecla == 'V') || (tecla == 'v') ) orientacion = VERTICAL;
			else orientacion = HORIZONTAL;

			/* Se comprueba que se pueda colocar el barco en esa posicion */
			if( colocaBarco(tablero, barcos, posx_barco - 1, posy_barco - 1, tam_barcos[i], 
				i + 1, orientacion) ) {
					barco_colocado = true;
					visualizarBarco(posx_tablero, posy_tablero, barcos, i + 1);	
			} 

			/* Se limpian los valores, para introducir otro barco */
			gotoxy(posx_tablero + 23, posy_tablero + 20);
			printf("   ");
			gotoxy(posx_tablero + 23, posy_tablero + 21);
			printf("   ");
			gotoxy(posx_tablero + 46, posy_tablero + 22);
			printf("   ");

		}

	}
	mensaje(msj, BLANCO);
	gotoxy(52, 30);
	tecla = getch();

}

int disparar( int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO], int jugx, int jugy ) {

	int disparo, cod_barco, tam_barco, i;
	int barco_posx, barco_posy;

	if( tablero[jugx][jugy] == 0 ) {
		disparo = AGUA;
		tablero[jugx][jugy] = -1;
	}
	else {
		cod_barco = tablero[jugx][jugy];
		if( (cod_barco >= 10) || (cod_barco == -1) ) {
			disparo = YA_DISPARADO;
		}
		else {
			cod_barco--;
			tablero[jugx][jugy] = (cod_barco + 1) * 10;
			/* Se comprueba si con el disparo se llega a hundir ya el barco */
			barco_posx = barcos[cod_barco][0];
			barco_posy = barcos[cod_barco][1];
			i = 0;
			if( barcos[cod_barco][0] == barcos[cod_barco][2]) {      /* Barco en posicion vertical */
				tam_barco = barcos[cod_barco][3] - barcos[cod_barco][1] + 1;
				while( (i < tam_barco) && (tablero[barco_posx][barco_posy + i] >= 10) ) {
					i++;
				}
			}
			else {        /* Barco en posición horizontal */
				tam_barco = barcos[cod_barco][2] - barcos[cod_barco][0] + 1;
				while( (i < tam_barco) && (tablero[barco_posx + i][barco_posy] >= 10) ) {
					i++;
				}
			}
			if( i == tam_barco ) {
				disparo = HUNDIDO;
			}
			else {
				disparo = TOCADO;
			}
		}
	}

	return disparo;

}

void dibujarDisparo( int posx, int posy, int jugx, int jugy, int disparo,
	int tablero[][TAM_TABLERO], int barcos[][COORD_BARCO] ) {

	char msj1[] = "Ya has atacado esta posicion!!";
	char msj2[] = "Tocado y hundido!!";
	char msj3[] = "Tocado!!";
	char msj4[] = "Agua!!";

	int cod_barco, barco_posx, barco_posy, tam_barco, i;

	jugx++; jugy++;
	switch( disparo ) {
		case AGUA:
			gotoxy(posx + 3*jugx - 1, posy + 2*jugy); 
			setColor(AZUL_C); 
			printf("OO");
			mensaje(msj4, AZUL_C);
			break;
		case YA_DISPARADO:
			mensaje(msj1, AMARILLO_C);
			break;
		case HUNDIDO:
			cod_barco = tablero[jugx - 1][jugy - 1] / 10 - 1;
			barco_posx = barcos[cod_barco][0] + 1;
			barco_posy = barcos[cod_barco][1] + 1;
			if( barcos[cod_barco][0] == barcos[cod_barco][2] ) {   /* Barco en vertical */
				tam_barco = barcos[cod_barco][3] - barcos[cod_barco][1] + 1;
				for( i=0; i<tam_barco; i++ ) {
					gotoxy(posx + 3*barco_posx - 1, posy + 2*barco_posy + 2*i);
					setColor(VERDE_C);
					printf("XX");
				}
			}
			else {  /* Barco en horizontal */
				tam_barco = barcos[cod_barco][2] - barcos[cod_barco][0] + 1;
				for( i=0; i<tam_barco; i++ ) {
					gotoxy(posx + 3*barco_posx - 1 + 3*i, posy + 2*barco_posy);
					setColor(VERDE_C);
					printf("XX");
				}
			}
			mensaje(msj2, VERDE_C);
			break;
		case TOCADO:
			gotoxy(posx + 3*jugx - 1, posy + 2*jugy);
			setColor(ROJO_C);
			printf("XX");
			mensaje(msj3, ROJO_C);
			break;

	}

}

void turnoCPU( void ) {

	char tecla;

	gotoxy(40, 23);
	setColor(BLANCO);
	printf("Turno CPU, pulse cualquier");
	gotoxy(40, 24);
	printf("tecla para continuar");
	tecla = getch();

}


int main( void ) {

	int tablero_j1[TAM_TABLERO][TAM_TABLERO];
	int tablero_j2[TAM_TABLERO][TAM_TABLERO];
	int barcos_j1[NUM_BARCOS][COORD_BARCO];
	int barcos_j2[NUM_BARCOS][COORD_BARCO];	
	int jugx, jugy;
	int disparo, num_jugadores;
	int barcos_no_hundidos_j1, barcos_no_hundidos_j2;
	int posx_t1, posy_t1, posx_t2, posy_t2;
	char msj1[] = "Has ganado jugador 1 !!!";
	char msj2[] = "Has ganado jugador 2 !!!";

	num_jugadores = pantallaInicio();	

	barcos_no_hundidos_j1 = NUM_BARCOS;
	barcos_no_hundidos_j2 = NUM_BARCOS;
	posx_t1 = 6; posy_t1 = 4;
	posx_t2 = 40; posy_t2 = 4;


	dibujaPantallaPrincipal(num_jugadores);
	dibujaTablero(posx_t1, posy_t1, TAM_TABLERO);
	dibujaTablero(posx_t2, posy_t2, TAM_TABLERO);
	
	inicializarTablero(tablero_j1);
	inicializarTablero(tablero_j2);

	pidePosicBarcos(1, posx_t1, posy_t1, tablero_j1, barcos_j1);
	ocultarBarcos(posx_t1, posy_t1);
	limpiaZonaTexto();
	if( num_jugadores == 1 ) posicionarBarcosCPU(tablero_j2, barcos_j2);
	else {
		pidePosicBarcos(2, posx_t2, posy_t2, tablero_j2, barcos_j2);
		ocultarBarcos(posx_t2, posy_t2);
	}

	disparo = AGUA;
	while( (barcos_no_hundidos_j1 > 0) && (barcos_no_hundidos_j2 > 0) ) {
		disparo = YA_DISPARADO;
		while( disparo == YA_DISPARADO ) {		
			pideJugada(&jugx ,&jugy, posx_t1, posy_t1);
			disparo = disparar(tablero_j2, barcos_j2, jugx, jugy);
			dibujarDisparo(posx_t2, posy_t2, jugx, jugy, disparo, tablero_j2, barcos_j2);
			if( disparo == HUNDIDO ) barcos_no_hundidos_j2--;
		}
		if( barcos_no_hundidos_j2 > 0 ) {
			disparo = YA_DISPARADO;
			limpiaZonaTexto();
			if( num_jugadores == 1 ) turnoCPU();
			while( disparo == YA_DISPARADO ) {
				if( num_jugadores == 1 ) {
					jugx = rand()%TAM_TABLERO;
					jugy = rand()%TAM_TABLERO;				
				}
				else pideJugada(&jugx ,&jugy, posx_t2, posy_t2);
				disparo = disparar(tablero_j1, barcos_j1, jugx, jugy);
				dibujarDisparo(posx_t1, posy_t1, jugx, jugy, disparo, tablero_j1, barcos_j1);
				if( disparo == HUNDIDO ) barcos_no_hundidos_j1--;
			}
		}
	}

	if( barcos_no_hundidos_j1 == 0 ) {   /* Gana jugador 1 */
		mensaje(msj1, AMARILLO_C);
	}
	else {                               /* Gana jugador 2 */
		mensaje(msj2, ROJO_C);
	}
	
	return(0);

}
