#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
// Estructura para representar una carta
typedef struct {
    int valor;
} Carta;

// Estructura para representar la mano de un jugador
typedef struct {
    Carta cartas[10];
    int cantidad_cartas;
    int puntaje;
} Mano;

//VARIABLE GLOBAL PARA EL SALDO
float saldoJugador=0;

int contadorTrabajo=0;
time_t ultimoJuegoTrabajar = 0; // Variable para almacenar la hora del ultimo Trabajar
time_t ultimoJuegoPesca= 0;
time_t ultimoJuegoM=0;

float bonus = 1.0; // Multiplicador para juegos de casino
float cooldownReduction = 1.0; // Reducción del tiempo de espera para los minijuegos
char nombreJugador[50] = "Jugador"; // Nombre del jugador
int juegosJugados = 0; // Número total de juegos jugados
float gananciasTotales = 0.0; // Ganancias totales
float porcentajeVictorias = 0.0; // Porcentaje de victorias
float victorias= 0.0; //Victorias totales
int vip = 0;

//PROTOTIPOS

/*
Función: menuPrincipal
Propósito: Mostrar el menú principal del programa.
*/
void menuPrincipal();

/*
Función: mostrarInstrucciones
Propósito: Mostrar las instrucciones del juego.
*/
void mostrarInstrucciones();

/*
Función: entrarAlCasino
Propósito: Entrar al casino y mostrar el menú del casino.
*/
void entrarAlCasino();

/*
Función: menuCasino
Propósito: Mostrar el menú del casino con las opciones de juego.
*/
void menuCasino();

/*
Función: jugarBlackjack
Propósito: Implementar el juego de Blackjack.
*/
void jugarBlackjack();

/*
Función: obtenerCarta
Propósito: Obtener una carta aleatoria del mazo.
Parámetro 1: cartas - Un arreglo de enteros representando las cartas disponibles en el mazo.
*/
int obtenerCarta(int cartas[]);

/*
Función: calcularValorMano
Propósito: Calcular el valor total de una mano en el juego de Blackjack.
Parámetro 1: mano - Un puntero a una estructura Mano que representa la mano del jugador o la casa.
*/
int calcularValorMano(Mano *mano);

/*
Función: jugarRuleta
Propósito: Implementar el juego de Ruleta.
*/
void jugarRuleta();

/*
Función: generarNumeroAleatorio
Propósito: Un numero aleatorio dentro de un intervalo cerrado
Parámetro 1: min, el extremo inferior del intervalo.
Parámetro 2: max, el extremo superior del intervalo.
*/
int generarNumeroAleatorio(int min, int max);

/*
Función: jugarTragamonedas
Propósito: Implementar el juego de Tragamonedas.
*/
void jugarTragamonedas();

/*
Función: entrarMinijuegos
Propósito: Entrar a la sección de minijuegos y mostrar el menú de minijuegos.
*/
void entrarMinijuegos();

/*
Función: menuMinijuegos
Propósito: Mostrar el menú de minijuegos con las opciones disponibles.
*/
void menuMinijuegos();

/*
Función: jugarTrabajar
Propósito: Implementar el minijuego "Trabajar" donde el jugador puede ganar dinero virtual.
*/
void jugarTrabajar();

/*
Función: jugarPesca
Propósito: Implementar el minijuego "Pesca" donde el jugador puede ganar dinero virtual.
*/
void jugarPesca();

/*
Función: jugarMenteMaestra
Propósito: Implementar el minijuego "Mente Maestra" donde el jugador puede ganar dinero virtual.
*/
void jugarMenteMaestra();

/*
Función: mostrarEstadisticas
Propósito: Mostrar las estadísticas del jugador en el casino.
*/
void mostrarEstadisticas();

/*
Función: tiendaVirtual
Propósito: Acceder a la tienda virtual para comprar artículos con el dinero virtual ganado.
*/
void tiendaVirtual();
/*
Función: mostrarMenuTienda
Propósito: Mostrar el menú de la tienda.
*/
void mostrarMenuTienda();

/*
Función: comprarMultiplicador
Propósito: Valida si el usuario tiene el saldo suficiente y efectua la compra del multiplicador.
*/
void comprarMultiplicador();
/*
Función: comprarDisminucionCooldowns
Propósito: Valida si el usuario tiene el saldo suficiente y efectua la compra del multiplicador.
*/
void comprarDisminucionCooldowns();

/*
Función: comprarEstatusVIP
Propósito: Valida si el usuario tiene el saldo suficiente y efectua la compra del estatus vip.
*/
void comprarEstatusVIP();

/*
Función: guardarYcargarProgreso
Propósito: Guardar y cargar el progreso del jugador en el juego.
*/
void guardarYcargarProgreso();

/*
Función: guardarProgreso
Propósito: Escribe en el archivo txt dado y guarda los datos del jugador
Parametro 1: nombreArchivo, string con el nombre del txt a acceder
*/
void guardarProgreso(char nombreArchivo[]);

/*
Función: cargarProgreso
Propósito: Lee en el archivo txt dado y guarda los datos del jugador
Parametro 1: nombreArchivo, string con el nombre del txt a acceder
*/
void cargarProgreso(char nombreArchivo[]);

int main() {
	setlocale(LC_ALL,"");
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios

    bool salir = false;
    while (!salir) {
    	system("cls");
        menuPrincipal();
        int opcion;
        printf("\nIngrese su opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                mostrarInstrucciones();
                break;
            case 2:
            	if(saldoJugador>=250){
				
                entrarAlCasino();
            } else{
            	printf("Saldo minimo insuficiente, ingresa a los minjuegos para ganar más. \n");
            	getch();
			}
                break;
            case 3: 
            	entrarMinijuegos();
            case 4:
                mostrarEstadisticas();
                break;
            case 5:
                tiendaVirtual();
                break;
            case 6:
                guardarYcargarProgreso();
                break;
            case 7:
                salir = true;
                break;
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    }

    printf("¡Gracias por jugar en el casino!\n");

    return 0;
}

void menuPrincipal() {
    printf("\n===== MENÚ PRINCIPAL =====\n");
    printf("1. Instrucciones\n");
    printf("2. Entrar al casino\n");
    printf("3. Entrar a los minijuegos\n");
    printf("4. Estadísticas\n");
    printf("5. Tienda virtual\n");
    printf("6. Guardar y cargar progreso\n");
    printf("7. Salir\n");
}

void mostrarInstrucciones() {
    system("cls");
    printf("=======INSTRUCCIONES=======\n\n");
    printf("1. Deberás ganar dinero en los minijuegos primero antes de poder acceder al casino.\n");
    printf("Cada juego y minuuego tiene sus respectivas reglas dentro\n\n");
    printf("2. Lo que ganes podrás utilizarlo en la tienda\n\n");
    printf("3. Es importante que guardes tu progreso para poder continuar en otra sesión\n\n");
    getch();
	
}

void entrarAlCasino() {
     bool salir = false;
    while (!salir) {
    	system("cls");
        menuCasino();
        int opcion;
        printf("\nIngrese su opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                jugarBlackjack();
                break;
            case 2:
                jugarRuleta();
                break;
            case 3:
                jugarTragamonedas();
                break;
            case 4:
                salir = true;
                break;
            
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    }
}

void menuCasino() {
    printf("\n===== MENÚ DEL CASINO =====\n");
    printf("1. Jugar Blackjack\n");
    printf("2. Jugar Ruleta\n");
    printf("3. Jugar Tragamonedas\n");
    printf("4. Salir\n");
}

void jugarBlackjack() {
    
    float apuesta;

    int cartas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}; // Valores de las cartas
    char continuar = 's';

    while (continuar == 's') {
    	system("cls");
    	printf("===== Bienvenido al Blackjack =====\n");
	    printf("Reglas del Blackjack:\n"); 
	    printf("1. Tienes que llegar lo más cerca posible a 21\n");
	    printf("2. Si te pasas, pierdes\n");
	    printf("3. Las cartas van a parar de repartirse hasta que superen o igualen 17\n");
	    printf("4. Cada carta numérica tiene su valor normal, el K, Q y J valen 10\n");
	    printf("5. Los Ases pueden valer 1 u 11 según convenga\n\n");
    	//Colocar apuesta
    	printf("Tu saldo actual es: %.2f\n", saldoJugador);
    
    printf("Ingresa la cantidad de tu apuesta (digita 0 para regresar al menú): ");
    scanf("%f", &apuesta);
    
    // Validamos que el jugador tenga saldo suficiente
    if (apuesta > saldoJugador || apuesta == 0) {
        printf("Apuesta invalida... Regresando al menú\n");
        Sleep(2000);
        return;
    }

    saldoJugador -= apuesta; // Descontamos la apuesta del saldo del jugador
    juegosJugados++;
        Mano manoJugador, manoCasa;
        manoJugador.cantidad_cartas = 0;
        manoCasa.cantidad_cartas = 0;

        // Inicializar manos
        manoJugador.cartas[0].valor = obtenerCarta(cartas);
        manoJugador.cartas[1].valor = obtenerCarta(cartas);
        manoJugador.cantidad_cartas = 2;
        manoCasa.cartas[0].valor = obtenerCarta(cartas);
        manoCasa.cartas[1].valor = obtenerCarta(cartas);
        manoCasa.cantidad_cartas = 2;

        int valorManoJugador = calcularValorMano(&manoJugador);
        int valorManoCasa = calcularValorMano(&manoCasa);

        printf("Tu mano:\n");
        printf("Carta 1: %d\n", manoJugador.cartas[0].valor);
        printf("Carta 2: %d\n", manoJugador.cartas[1].valor);
        printf("Valor de tu mano: %d\n\n", valorManoJugador);

        // Turno del jugador
        char op;
        while (valorManoJugador < 21 && op != 'n') {
            printf("¿Quieres otra carta? (s/n): ");
            scanf(" %c", &op);
            if (op == 's') {
                int nuevaCarta = obtenerCarta(cartas);
                manoJugador.cartas[manoJugador.cantidad_cartas++].valor = nuevaCarta;
                printf("Nueva carta: %d\n", nuevaCarta);
                valorManoJugador = calcularValorMano(&manoJugador);
                printf("Valor de tu mano: %d\n\n", valorManoJugador);
            }
        }

        // Turno de la casa
        while (valorManoCasa < 17) {
            int nuevaCarta = obtenerCarta(cartas);
            manoCasa.cartas[manoCasa.cantidad_cartas++].valor = nuevaCarta;
            valorManoCasa = calcularValorMano(&manoCasa);
        }

        // Mostrar cartas de la casa
        printf("Las cartas de la casa son:\n");
        printf("Carta 1: %d\n", manoCasa.cartas[0].valor);
        printf("Carta 2: %d\n", manoCasa.cartas[1].valor);
        printf("Valor de la mano de la casa: %d\n\n", valorManoCasa);

        // Determinar el ganador
        if (valorManoJugador > 21) {
            printf("¡Te has pasado! Pierdes.\n");
        } else if (valorManoJugador == valorManoCasa) {
            printf("¡Empate!\n");
            saldoJugador += apuesta;
        } else if (valorManoJugador > valorManoCasa || valorManoCasa > 21) {
            printf("¡Ganaste!\n");
            saldoJugador += apuesta*2*bonus;
            gananciasTotales+= apuesta*2*bonus;
            victorias++;
        } else {
            printf("Gana la casa.\n");
        }

        printf("-------------------------------------------------\n");
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
    }
}

int obtenerCarta(int cartas[]) {
    return cartas[rand() % 13];
}

int calcularValorMano(Mano *mano) {
	
    int valor = 0;
    int ases = 0;

    // Calcular valor de las cartas en la mano
    for (int i = 0; i < mano->cantidad_cartas; i++) {
        if (mano->cartas[i].valor == 1) {  // Ases
            ases++;
            valor += 11;
        } else {
            valor += mano->cartas[i].valor;
        }
    }

    // Ajustar el valor de los Ases si es necesario
    while (valor > 21 && ases > 0) {
        valor -= 10;
        ases--;
    }

    return valor;
}

void jugarRuleta(){
	//Inicializamos variables
	int rojo[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	int negro[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
	int columna1[12] = {1,4,7,10,13,16,19,22,25,28,31,34};
	int columna2[12] = {2,5,8,11,14,17,20,23,26,29,32,35};
	int columna3[12] = {3,6,9,12,15,18,21,24,27,30,33,36};
	int selecTablero,acierto, ganancia;
	char color[10];
	
    
    float apuesta;
    char continuar = 's';

    while (continuar == 's') {
    	system("cls");
    	printf("===== Bienvenido a la ruleta =====\n");
    	printf("-----------------------------------\n\n");
    	//Colocar apuesta
    	printf("Tu saldo actual es: %.2f\n", saldoJugador);
    	printf("Selecciona tu apuesta: \n");
    	printf("1.- [x35] -> Apuesta Directa\n\n");
    	printf("2.- [x 3] -> Apuesta por Docenas (1-12, 13-24, 25-36)\n\n");
    	printf("3.- [x 3] -> Apuesta por Columnas (1ra, 2da, 3ra)\n\n");
    	printf("4.- [x 2] -> Apuesta por Mitades (1-18, 19-36)\n\n");
    	printf("5.- [x 2] -> Apuesta Par / Impar\n\n");
    	printf("6.- [x 2] -> Apuesta por Colores (Rojo, Negro)\n\n");
    	printf("7.- Regresar al menú\n\n\n");
    	int opcion_apuesta;
	    printf("Elige el tipo de apuesta: ");
	    scanf("%d", &opcion_apuesta);
	    
	     switch(opcion_apuesta) {
	    	case 1: // Apuesta Directa
	    		printf("Ingresa el número al que quieres apostar (0-36): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	case 2: // Apuesta por Docenas
	    		printf("Ingresa la docena a la quieres apostar (1-3): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	case 3: // Apuesta por Columnas
	    		printf("Ingresa la columna a la que quieres apostar (1-3): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	case 4: // Apuesta por Mitades
	    		printf("Ingresa la mitad a la que quieres apostar (1-2): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	case 5: // Apuesta Par / Impar
	    		printf("Ingresa si es par o impar (1 para par, 2 para impar): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	case 6: // Apuesta por Colores
	    		printf("Ingresa el color al que quieres apostar (1 para rojo, 2 para negro): ");
	    		scanf("%d",&selecTablero);
	    		break;
	    	default:
	    		printf("Opción de apuesta no válida.\n");
	    		return;
	    		break;
	    }
    	printf("Ingresa la cantidad de tu apuesta: ");
    	scanf("%f", &apuesta);
    
    // Validamos que el jugador tenga saldo suficiente
    if (apuesta > saldoJugador || apuesta == 0) {
        printf("Apuesta invalida..\n");
        return;
    }
    saldoJugador -= apuesta; // Descontamos la apuesta del saldo del jugador
    juegosJugados++;
    
    // Girar la ruleta
	    int numeroGanador = generarNumeroAleatorio(0, 36);
	// Asignar color al numerp
	for(int i = 0; i < 18; i++){
				if(numeroGanador == rojo[i]){
					strcpy(color, "Rojo");
				}else if(numeroGanador == negro[i]){
					strcpy(color,"Negro");
				}
			}
		
		
	    printf("-----------------\n");
	    printf("El número ganador es: %d %s\n", numeroGanador,color);
	    printf("-----------------\n");
	    
	//Verificar si el jugador ganó
	switch(opcion_apuesta) {
	    	case 1: // Apuesta Directa
	    		if(selecTablero==numeroGanador){
	    			acierto=1;
	    			ganancia=apuesta*35;
					saldoJugador += ganancia*bonus;
				}
	    		break;
	    		
		    case 2: // Apuesta por Docenas
			    if(numeroGanador > 0 && numeroGanador < 13 && selecTablero == 1){
			    	acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
				}
				else if(numeroGanador >= 13 && numeroGanador < 25 && selecTablero == 2){
					acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
				}
				else if(numeroGanador >= 24 && numeroGanador < 37 && selecTablero == 3){
					acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
				}
	    		break;
	    		
	    	case 3: // Apuesta por Columnas
	    		if(selecTablero == 1){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna1[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
						}
					}
				}
				
				else if(selecTablero == 2){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna2[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
						}
					}
				}
				
				else if(selecTablero == 3){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna3[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia*bonus;
						}
					}
				}
	    		break;
	    	case 4: // Apuesta por Mitades
	    		if(numeroGanador > 0 && numeroGanador <= 18 && selecTablero == 1){
			    	acierto=1;
				ganancia=apuesta*2;
				saldoJugador += ganancia*bonus;
				}
				else if(numeroGanador > 18 && numeroGanador <=36 && selecTablero == 2){
					acierto=1;
				ganancia=apuesta*2;
					saldoJugador += ganancia*bonus;
				}
	    		break;
	    	case 5: // Apuesta Par / Impar
	    		if(numeroGanador%2==0 && selecTablero==1){
	    			acierto=1;
	    			ganancia=apuesta*2;
	    			saldoJugador+=(apuesta*2)*bonus;
				}else if(numeroGanador%2!=0 && selecTablero==2){
	    			acierto=1;
	    			ganancia=apuesta*2;
					saldoJugador += ganancia*bonus;
				}
	    		break;
	    	case 6: // Apuesta por Colores
	    			if(selecTablero == 1){
					for(int i = 0; i < 18; i++){
						if(numeroGanador == rojo[i]){
							acierto = 1;
							ganancia=apuesta*2;
							saldoJugador += ganancia*bonus;
						}
					}
				}
				
				else if(selecTablero == 2){
					for(int i = 0; i < 18; i++){
						if(numeroGanador == negro[i]){
							acierto = 1;
							ganancia=apuesta*2;
							saldoJugador += ganancia*bonus;
						}
					}
				}
				
	    		break;
	    	default:
	    		printf("Opción de apuesta no válida.\n");
	    		break;
	    }
	    if(acierto==1){
	    	printf("Felicidades! Tu apuesta fue ganadora! Ganaste %d pesos\n", ganancia*bonus);
	    	victorias++;
	    	gananciasTotales += ganancia*bonus;
		}else{
			printf("Lo sentimos, tu apuesta no ganó.\n");
		}
        printf("-------------------------------------------------\n");
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
    }
}

// Función para generar un número aleatorio entre min y max (incluyendo min y max)
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para jugar al tragamonedas
void jugarTragamonedas() {
	

    float apuesta;
    char continuar = 's';

    while (continuar == 's') {
    	system("cls");
    printf("===== Bienvenido al Tragamonedas =====\n");
    printf("--------------------------------------\n");
    printf("El premio mayor vale 10 veces tu apuesta\n");
    printf("El premio menor vale 5 veces tu apuesta\n");
    printf("--------------------------------------\n\n");

    	//Colocar apuesta
    printf("Tu saldo actual es: %.2f\n", saldoJugador);
	printf("Ingresa la cantidad de tu apuesta (0 para regresar al menú): ");
    scanf("%f", &apuesta);
    
    // Validamos que el jugador tenga saldo suficiente
    if (apuesta > saldoJugador || apuesta == 0) {
        printf("Apuesta invalida..\n");
        return;
    }
    juegosJugados++;
    saldoJugador -= apuesta; // Descontamos la apuesta del saldo del jugador
    
    printf("Presiona ENTER para girar el rodillo...\n");
    getchar(); // Espera a que el usuario presione ENTER
    getchar(); // Limpia el buffer del teclado
	printf("---Girando el rodillo!---\n");
	Sleep(5000);
	
    // Genera tres números aleatorios para los tres rodillos
    int rodillo1 = generarNumeroAleatorio(0,10);
    int rodillo2 = generarNumeroAleatorio(0,10);
    int rodillo3 = generarNumeroAleatorio(0,10);

    printf("Los rodillos han girado...\n\n");
    printf("Resultado: [%d]  [%d]  [%d]\n\n", rodillo1, rodillo2, rodillo3);

    // Comprueba si los tres números son iguales
    if (rodillo1 == rodillo2 && rodillo2 == rodillo3) {
        printf("¡Felicidades! ¡Has ganado el premio mayor!\n");
        saldoJugador += apuesta*10*bonus; // Premio mayor de 100 unidades
        victorias++;
        gananciasTotales += apuesta*10*bonus;
    } else if (rodillo1 == rodillo2 || rodillo1 == rodillo3 || rodillo2 == rodillo3) {
        printf("¡Felicidades! ¡Has ganado un premio menor!\n");
        saldoJugador += apuesta*5*bonus; // Premio menor de 50 unidades
        victorias++;
        gananciasTotales+=apuesta*5*bonus;
    } else {
        printf("Lo siento, no has ganado esta vez...\n");
    }
    printf("-------------------------------------------------\n");
    	printf("Tu nuevo saldo es de %.2f\n\n", saldoJugador);
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
	}

}

void entrarMinijuegos(){
	bool salir = false;
    while (!salir) {
    	system("cls");
        menuMinijuegos();
        int opcion;
        printf("\nIngrese su opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (time(NULL) - ultimoJuegoTrabajar >= (60*cooldownReduction) || ultimoJuegoTrabajar == 0) { // Validar si han pasado 60 segundos desde el último juego
                    jugarTrabajar(); // Iniciar el minijuego
                } else {
                    printf("Debes esperar un minuto antes de volver a jugar.\n");
                    contadorTrabajo=0;
                    Sleep(3000);
                }
                break;
            case 2:
            	//Tiempo de espera menor debido a su dificultad
            	if (time(NULL) - ultimoJuegoM >= (30*cooldownReduction) || ultimoJuegoM == 0) { // Validar si han pasado 30 segundos desde el último juego
                jugarMenteMaestra();
                } else {
                    printf("Debes esperar 30 segundos antes de volver a jugar.\n");
                }
                break;
            case 3:
                if (time(NULL) - ultimoJuegoPesca >= (45*cooldownReduction) || ultimoJuegoPesca == 0) { // Validar si han pasado 45 segundos desde el último juego
                    jugarPesca(); // Iniciar el minijuego
                } else {
                    printf("Debes esperar 45 segundos antes de volver a jugar.\n");
                }
                break;
            case 4:
                salir = true;
                break;
            
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    }
}

void menuMinijuegos(){
    printf("\n===== MENÚ DE MINIJUEGOS =====\n");
    printf("1. Trabajar\n");
    printf("2. Jugar Mente Maestra\n");
    printf("3. Jugar Pesca\n");
    printf("4. Salir\n");
}

void jugarTrabajar() {
	system("cls");
    printf("===== Minijuego: Trabajar =====\n");

    // Mensajes aleatorios al entrar al minijuego
    char *mensajes[] = {
        "Trabajaste 18 horas en la maquiladora y te pagaron ",
        "Realizaste un trabajo freelance y recibiste un pago de ",
        "Hiciste algunas tareas en línea y obtuviste ",
        "Fuiste a trabajar como repartidor y ganaste ",
        "Te contrataron para una sesión de tutoría y recibiste ",
        "Trabajaste en la cafeteria de FMAT y te dieron ",
        "Le hiciste un ADA de Calculo a tu amigo y te pagó ",
        "Renunciaste de Messinas y te dieron de finiquito "
    };

    int num_mensajes = sizeof(mensajes) / sizeof(mensajes[0]);
    int indice_mensaje = rand() % num_mensajes;
    int pago= generarNumeroAleatorio(50,150);
    printf("%s%d pesos.", mensajes[indice_mensaje],pago);
    saldoJugador+=pago;
    gananciasTotales += pago;
    contadorTrabajo++;

    printf("\nRegresando al menú principal...\n");
	Sleep(3000);
	// Almacenar la hora en la que terminó el juego si ya jugó tres veces
     if(contadorTrabajo>2){
    ultimoJuegoTrabajar = time(NULL);
    }
}

void jugarPesca() {
	system("cls");
    printf("===== Minijuego Pesca =====\n");
    printf("Presiona la tecla de espacio la mayor cantidad de veces posible en 10 segundos para pescar!.\n");
    printf("Por cada pescado, ganas 4 unidades.\n\n");

    int contador = 0;
    clock_t inicio = clock(); // Marca de tiempo inicial

    // Ejecutar el juego durante 10 segundos
    while ((clock() - inicio) / CLOCKS_PER_SEC < 10) {
        if (_kbhit()) { // Verifica si se presionó una tecla
            if (_getch() == ' ') { // Si la tecla presionada es espacio
                contador++; // Incrementa el contador
                printf("\rPescados capturados: %d", contador);
                fflush(stdout); // Limpia el buffer de salida
            }
        }
    }

    // Calcular el saldo ganado
    float saldoGanado = contador * 4.0;
    saldoJugador += saldoGanado;

    printf("\n\nTiempo agotado. Has pescado un total de %d pescados.\n", contador);
    printf("Saldo ganado: %.2f unidades\n", saldoGanado);
    printf("Saldo actual: %.2f unidades\n", saldoJugador);
    printf("Regresando al menú...");
    Sleep(3000);
    ultimoJuegoPesca = time(NULL);
}

// Función para generar una operación matemática aleatoria
void generarOperacion() {
    // Genera dos números aleatorios entre 1 y 10
    int num1 = rand() % 30 + 1;
    int num2 = rand() % 30 + 1;

    // Genera un operador aleatorio (+, -, *)
    char operador;
    switch (rand() % 3) {
        case 0:
            operador = '+';
            break;
        case 1:
            operador = '-';
            break;
        case 2:
            operador = '*';
            break;
    }

    // Muestra la operación al jugador
    printf("¿Cuánto es %d %c %d? ", num1, operador, num2);

    // Lee la respuesta del jugador
    int respuesta;
    scanf("%d", &respuesta);

    // Calcula la respuesta correcta
    int resultado;
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
    }

    // Verifica si la respuesta del jugador es correcta
    if (respuesta == resultado) {
        printf("¡Respuesta correcta! Ganaste 40 créditos.\n");
        saldoJugador += 40;
    } else {
        printf("Respuesta incorrecta. La respuesta correcta era: %d\n", resultado);
    }
}

// Función para jugar al minijuego "Mente Maestra"
void jugarMenteMaestra() {
	system("cls");
    printf("===== Minijuego Mente Maestra =====\n");
    printf("Resuelve la mayor cantidad de operaciones matemáticas en 30 segundos.\n");
    printf("Por cada operación correcta, ganas 40 créditos.\n\n");

    clock_t inicio = clock(); // Marca de tiempo inicial
    float saldoAux=saldoJugador;

    // Juega durante 30 segundos
    while ((clock() - inicio) / CLOCKS_PER_SEC < 30) {
        generarOperacion();
    }
	float ganancia= saldoJugador-saldoAux;
    printf("\n¡Tiempo agotado! Has ganado un total de %.2f créditos.\n", ganancia);
    Sleep(3000);
    ultimoJuegoM= time(NULL);
}

void mostrarEstadisticas() {
	//Calculamos el porcentaje de victorias
	if(juegosJugados!=0){
		porcentajeVictorias = victorias/juegosJugados *100;
	}
	system("cls");
	if(vip==0){
    printf("===== Estadísticas del Jugador =====\n");
    printf("Juegos Jugados: %d\n", juegosJugados);
    printf("Ganancias Totales: %.2f\n", gananciasTotales);
    printf("Porcentaje de Victorias: %.2f%%\n", porcentajeVictorias);
    printf("Saldo Actual: %.2f unidades\n", saldoJugador);
    getch();
} else if(vip==1){
	printf("======================================\n");
printf("||       Estadísticas de %s    \n",nombreJugador);
printf("======================================\n");
printf("||  Juegos Jugados          ||   %d   \n", juegosJugados);
printf("||--------------------------||--------||\n");
printf("||  Ganancias Totales       ||  %.2f  \n", gananciasTotales);
printf("||--------------------------||--------||\n");
printf("||  Porcentaje de Victorias ||  %.2f%%  \n", porcentajeVictorias);
printf("||--------------------------||--------||\n");
printf("||  Saldo Actual            ||  %.2f  \n", saldoJugador);
printf("======================================\n");
getch();
}
}

// Función para comprar el multiplicador para juegos de casino
void comprarMultiplicador() {
    if (saldoJugador >= 10000.0) {
        bonus *= 1.3; // Aumenta en un 30% las ganancias del casino
        saldoJugador -= 10000.0; // Descuenta el costo del saldo del jugador
        printf("¡Has comprado el multiplicador para juegos de casino!\n");
    } else {
        printf("No tienes suficiente saldo para comprar el multiplicador para juegos de casino.\n");
    }
}

// Función para comprar la disminución de cooldowns
void comprarDisminucionCooldowns() {
    if (saldoJugador >= 6000.0) {
        cooldownReduction *= 0.75; // Disminuye el tiempo de espera para los minijuegos en un 25%
        saldoJugador -= 6000.0; // Descuenta el costo del saldo del jugador
        printf("¡Has comprado la disminución de cooldowns!\n");
    } else {
        printf("No tienes suficiente saldo para comprar la disminución de cooldowns.\n");
    }
}

// Función para comprar el estatus VIP
void comprarEstatusVIP() {
    if (saldoJugador >= 4500.0 && vip==0) {
        // Agrega decoración al nombre del jugador
        char decoracion[] = "|~~";
        strcat(decoracion, nombreJugador);
        strcat(decoracion, "~~|");
        strcpy(nombreJugador, decoracion);
        //Agregar el estatus para las estadisticas
        vip=1;
        saldoJugador -= 4500.0; // Descuenta el costo del saldo del jugador
        printf("¡Has comprado el estatus VIP!\n");
    } else {
        printf("No tienes suficiente saldo para comprar el estatus VIP.\n");
    }
}

// Función para mostrar el menú de la tienda virtual
void mostrarMenuTienda() {
    printf("===== Tienda Virtual =====\n");
    printf("Saldo actual: %.2f unidades\n", saldoJugador);
    printf("1. Comprar multiplicador para juegos de casino (Costo: 10,000 unidades)\n");
    printf("2. Comprar disminución de cooldowns (Costo: 6,000 unidades)\n");
    printf("3. Comprar estatus VIP (Costo: 4,500 unidades)\n");
    printf("4. Salir de la tienda\n");
}

// Función principal de la tienda virtual
void tiendaVirtual() {
    int opcion;
    do {
    	system("cls");
        mostrarMenuTienda();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                comprarMultiplicador();
                break;
            case 2:
                comprarDisminucionCooldowns();
                break;
            case 3:
                comprarEstatusVIP();
                break;
            case 4:
                printf("Saliendo de la tienda...\n");
                break;
            default:
                printf("Opción inválida. Por favor, selecciona una opción válida.\n");
        }
        printf("\n");
    } while (opcion != 4);
}

// Función para guardar el progreso del jugador en un archivo de texto
void guardarProgreso(char nombreArchivo[]) {
    FILE *archivo = fopen(nombreArchivo, "w"); // Abre el archivo en modo escritura
    if (archivo != NULL) {
    	fprintf(archivo, "%s\n", nombreJugador); // Guarda el nombre del jugador
        fprintf(archivo, "%.2f\n", saldoJugador); // Guarda el saldo del jugador
        fprintf(archivo, "%.2f\n", bonus); // Guarda el bonus para juegos de casino
        fprintf(archivo, "%.2f\n", cooldownReduction); // Guarda la reducción de cooldowns
        fprintf(archivo, "%d\n", juegosJugados); // Guarda el número total de juegos jugados
        fprintf(archivo, "%.2f\n", gananciasTotales); // Guarda las ganancias totales
        fprintf(archivo, "%.2f\n", victorias); //Guarda las victorias
        fprintf(archivo, "%.2f\n", porcentajeVictorias); // Guarda el porcentaje de victorias
        fprintf(archivo, "%d\n", vip);
        fclose(archivo); // Cierra el archivo
        printf("Progreso guardado correctamente en el archivo: %s\n", nombreArchivo);
        Sleep(2000);
    } else {
        printf("Error al guardar el progreso en el archivo.\n");
    }
}

// Función para cargar el progreso del jugador desde un archivo de texto
void cargarProgreso(char nombreArchivo[]) {
    FILE *archivo = fopen(nombreArchivo, "r"); // Abre el archivo en modo lectura
    if (archivo != NULL) {
    	fscanf(archivo, "%s", &nombreJugador); // Lee el nombre del jugador
        fscanf(archivo, "%f", &saldoJugador); // Lee el saldo del jugador
        fscanf(archivo, "%f", &bonus); // Lee el bonus para juegos de casino
        fscanf(archivo, "%f", &cooldownReduction); // Lee la reducción de cooldowns
        fscanf(archivo, "%d", &juegosJugados); // Lee el número total de juegos jugados
        fscanf(archivo, "%f", &gananciasTotales); // Lee las ganancias totales
        fscanf(archivo, "%f", &victorias); // Lee el porcentaje de victorias
        fscanf(archivo, "%f", &porcentajeVictorias); // Lee el porcentaje de victorias
        fscanf(archivo, "%d", &vip); // Lee el porcentaje de victorias
        fclose(archivo); // Cierra el archivo
        printf("Progreso cargado correctamente desde el archivo: %s\n\n", nombreArchivo);
        printf("Bienvenido de nuevo, %s!\n",nombreJugador);
        printf("Su saldo recuperado es de: %.2f",saldoJugador);
        Sleep(4000);
    } else {
        printf("Error al cargar el progreso desde el archivo.\n");
    }
}

// Función para guardar o cargar el progreso del jugador
void guardarYcargarProgreso() {
	system("cls");
    int opcion;
    printf("===== Guardar y Cargar Progreso =====\n");
    printf("1. Guardar progreso\n");
    printf("2. Cargar progreso\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    char nombreArchivo[100];

    switch (opcion) {
        case 1:
        	printf("Ingrese su nombre para identificarlo: ");
            scanf("%s", nombreJugador);
            printf("Ingrese el nombre del archivo para guardar su progreso: ");
            scanf("%s", nombreArchivo);
            guardarProgreso(nombreArchivo);
            break;
        case 2:
            printf("Ingrese el nombre del archivo para cargar su progreso: ");
            scanf("%s", nombreArchivo);
            cargarProgreso(nombreArchivo);
            break;
        default:
            printf("Opción inválida. Por favor, seleccione una opción válida.\n");
    }
}

