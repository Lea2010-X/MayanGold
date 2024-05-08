#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <string.h>
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
float saldoJugador=1000;

time_t ultimoJuegoTrabajar = 0; // Variable para almacenar la hora del último juego


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

int generarNumeroAleatorio();
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
Función: guardarYcargarProgreso
Propósito: Guardar y cargar el progreso del jugador en el juego.
*/
void guardarYcargarProgreso();

int main() {
	setlocale(LC_ALL,"");
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios

    bool salir = false;
    while (!salir) {
        menuPrincipal();
        int opcion;
        printf("\nIngrese su opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                mostrarInstrucciones();
                break;
            case 2:
                entrarAlCasino();
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
    // Implementación de las instrucciones
}

void entrarAlCasino() {
     bool salir = false;
    while (!salir) {
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
                //jugarTragamonedas();(En construccion)
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
    printf("===== Bienvenido al Blackjack =====\n");
    printf("Reglas del Blackjack:\n"); 
    printf("1. Tienes que llegar lo más cerca posible a 21\n");
    printf("2. Si te pasas, pierdes\n");
    printf("3. Las cartas van a parar de repartirse hasta que superen o igualen 17\n");
    printf("4. Cada carta numérica tiene su valor normal, el K, Q y J valen 10\n");
    printf("5. Los Ases pueden valer 1 u 11 según convenga\n\n");
    
    float apuesta;

    int cartas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}; // Valores de las cartas
    char continuar = 's';

    while (continuar == 's') {
    	//Colocar apuesta
    	printf("Tu saldo actual es: %.2f\n", saldoJugador);
    
    printf("Ingresa la cantidad de tu apuesta: ");
    scanf("%f", &apuesta);
    
    // Validamos que el jugador tenga saldo suficiente
    if (apuesta > saldoJugador || apuesta == 0) {
        printf("Apuesta invalida..\n");
        return;
    }

    saldoJugador -= apuesta; // Descontamos la apuesta del saldo del jugador
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
            saldoJugador += apuesta*2;
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
	printf("===== Bienvenido a la ruleta =====\n");
    printf("-----------------------------------\n\n");
    
    float apuesta;
    char continuar = 's';

    while (continuar == 's') {
    	//Colocar apuesta
    	printf("Tu saldo actual es: %.2f\n", saldoJugador);
    	printf("Selecciona tu apuesta: \n");
    	printf("1.- [x35] -> Apuesta Directa\n\n");
    	printf("2.- [x 3] -> Apuesta por Docenas (1-12, 13-24, 25-36)\n\n");
    	printf("3.- [x 3] -> Apuesta por Columnas (1ra, 2da, 3ra)\n\n");
    	printf("4.- [x 2] -> Apuesta por Mitades (1-18, 19-36)\n\n");
    	printf("5.- [x 2] -> Apuesta Par / Impar\n\n");
    	printf("6.- [x 2] -> Apuesta por Colores (Rojo, Negro)\n\n\n");
    	int opcion_apuesta;
	    printf("Elige el tipo de apuesta (1-6): ");
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
							saldoJugador += ganancia;
				}
	    		break;
	    		
		    case 2: // Apuesta por Docenas
			    if(numeroGanador > 0 && numeroGanador < 13 && selecTablero == 1){
			    	acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia;
				}
				else if(numeroGanador >= 13 && numeroGanador < 25 && selecTablero == 2){
					acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia;
				}
				else if(numeroGanador >= 24 && numeroGanador < 37 && selecTablero == 3){
					acierto=1;
				ganancia=apuesta*3;
							saldoJugador += ganancia;
				}
	    		break;
	    		
	    	case 3: // Apuesta por Columnas
	    		if(selecTablero == 1){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna1[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia;
						}
					}
				}
				
				else if(selecTablero == 2){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna2[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia;
						}
					}
				}
				
				else if(selecTablero == 3){
					for(int i = 0; i < 12; i++){
						if(numeroGanador == columna3[i]){
							acierto = 1;
							ganancia=apuesta*3;
							saldoJugador += ganancia;
						}
					}
				}
	    		break;
	    	case 4: // Apuesta por Mitades
	    		if(numeroGanador > 0 && numeroGanador <= 18 && selecTablero == 1){
			    	acierto=1;
				ganancia=apuesta*2;
				saldoJugador += ganancia;
				}
				else if(numeroGanador > 18 && numeroGanador <=36 && selecTablero == 2){
					acierto=1;
				ganancia=apuesta*2;
					saldoJugador += ganancia;
				}
	    		break;
	    	case 5: // Apuesta Par / Impar
	    		if(numeroGanador%2==0 && selecTablero==1){
	    			acierto=1;
	    			saldoJugador+=(apuesta*2);
				}else if(numeroGanador%2!=0 && selecTablero==2){
	    			acierto=1;
	    			ganancia=apuesta*2;
					saldoJugador += ganancia;
				}
	    		break;
	    	case 6: // Apuesta por Colores
	    			if(selecTablero == 1){
					for(int i = 0; i < 18; i++){
						if(numeroGanador == rojo[i]){
							acierto = 1;
							ganancia=apuesta*2;
							saldoJugador += ganancia;
						}
					}
				}
				
				else if(selecTablero == 2){
					for(int i = 0; i < 18; i++){
						if(numeroGanador == negro[i]){
							acierto = 1;
							ganancia=apuesta*2;
							saldoJugador += ganancia;
						}
					}
				}
				
	    		break;
	    	default:
	    		printf("Opción de apuesta no válida.\n");
	    		break;
	    }
	    if(acierto==1){
	    	printf("Felicidades! Tu apuesta fue ganadora! Ganaste %d pesos\n", ganancia);
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


void entrarMinijuegos(){
	bool salir = false;
    while (!salir) {
        menuMinijuegos();
        int opcion;
        printf("\nIngrese su opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (time(NULL) - ultimoJuegoTrabajar >= 60 || ultimoJuegoTrabajar == 0) { // Validar si han pasado 10 segundos desde el último juego
                    jugarTrabajar(); // Iniciar el minijuego
                } else {
                    printf("Debes esperar un minuto antes de volver a jugar.\n");
                }
                break;
            case 2:
                //jugarMenteM();(En construccion)
                break;
            case 3:
                //jugarPesca();(En construccion)
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

     // Almacenar la hora en la que terminó el juego
    ultimoJuegoTrabajar = time(NULL);

    printf("\nRegresando al menú principal...\n");

}

void mostrarEstadisticas() {
    // Implementación de mostrar estadísticas(En construccion)
}

void tiendaVirtual() {
    // Implementación de la tienda virtual(En construccion)
}

void guardarYcargarProgreso() {
    // Implementación de guardar y cargar progreso(En construccion)
}

