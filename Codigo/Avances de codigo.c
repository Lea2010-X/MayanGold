#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

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

// bool enEspera = false; // Variable booleana para controlar el estado de espera

time_t ultimoJuegoTrabajar = 0; // Variable para almacenar la hora del �ltimo juego


//PROTOTIPOS

/*
Funci�n: menuPrincipal
Prop�sito: Mostrar el men� principal del programa.
*/
void menuPrincipal();

/*
Funci�n: mostrarInstrucciones
Prop�sito: Mostrar las instrucciones del juego.
*/
void mostrarInstrucciones();

/*
Funci�n: entrarAlCasino
Prop�sito: Entrar al casino y mostrar el men� del casino.
*/
void entrarAlCasino();

/*
Funci�n: menuCasino
Prop�sito: Mostrar el men� del casino con las opciones de juego.
*/
void menuCasino();

/*
Funci�n: jugarBlackjack
Prop�sito: Implementar el juego de Blackjack.
*/
void jugarBlackjack();

/*
Funci�n: obtenerCarta
Prop�sito: Obtener una carta aleatoria del mazo.
Par�metro 1: cartas - Un arreglo de enteros representando las cartas disponibles en el mazo.
*/
int obtenerCarta(int cartas[]);

/*
Funci�n: calcularValorMano
Prop�sito: Calcular el valor total de una mano en el juego de Blackjack.
Par�metro 1: mano - Un puntero a una estructura Mano que representa la mano del jugador o la casa.
*/
int calcularValorMano(Mano *mano);

/*
Funci�n: entrarMinijuegos
Prop�sito: Entrar a la secci�n de minijuegos y mostrar el men� de minijuegos.
*/
void entrarMinijuegos();

/*
Funci�n: menuMinijuegos
Prop�sito: Mostrar el men� de minijuegos con las opciones disponibles.
*/
void menuMinijuegos();

/*
Funci�n: jugarTrabajar
Prop�sito: Implementar el minijuego "Trabajar" donde el jugador puede ganar dinero virtual.
*/
void jugarTrabajar();

/*
Funci�n: mostrarEstadisticas
Prop�sito: Mostrar las estad�sticas del jugador en el casino.
*/
void mostrarEstadisticas();

/*
Funci�n: tiendaVirtual
Prop�sito: Acceder a la tienda virtual para comprar art�culos con el dinero virtual ganado.
*/
void tiendaVirtual();

/*
Funci�n: guardarYcargarProgreso
Prop�sito: Guardar y cargar el progreso del jugador en el juego.
*/
void guardarYcargarProgreso();
int main() {
	setlocale(LC_ALL,"");
    srand(time(NULL)); // Inicializar la semilla para la generaci�n de n�meros aleatorios

    bool salir = false;
    while (!salir) {
        menuPrincipal();
        int opcion;
        printf("\nIngrese su opci�n: ");
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
                printf("Opci�n no v�lida. Por favor, elija una opci�n v�lida.\n");
        }
    }

    printf("�Gracias por jugar en el casino!\n");

    return 0;
}

void menuPrincipal() {
    printf("\n===== MEN� PRINCIPAL =====\n");
    printf("1. Instrucciones\n");
    printf("2. Entrar al casino\n");
    printf("3. Entrar a los minijuegos\n");
    printf("4. Estad�sticas\n");
    printf("5. Tienda virtual\n");
    printf("6. Guardar y cargar progreso\n");
    printf("7. Salir\n");
}

void mostrarInstrucciones() {
    // Implementaci�n de las instrucciones
}

void entrarAlCasino() {
     bool salir = false;
    while (!salir) {
        menuCasino();
        int opcion;
        printf("\nIngrese su opci�n: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                jugarBlackjack();
                break;
            case 2:
                //jugarRuleta();(En construccion)
                break;
            case 3:
                //jugarTragamonedas();(En construccion)
                break;
            case 4:
                salir = true;
                break;
            
            default:
                printf("Opci�n no v�lida. Por favor, elija una opci�n v�lida.\n");
        }
    }
}

void menuCasino() {
    printf("\n===== MEN� DEL CASINO =====\n");
    printf("1. Jugar Blackjack\n");
    printf("2. Jugar Ruleta\n");
    printf("3. Jugar Tragamonedas\n");
    printf("4. Salir\n");
}

void jugarBlackjack() {
    printf("===== Bienvenido al Blackjack =====\n");
    printf("Reglas del Blackjack:\n");
    printf("1. Tienes que llegar lo m�s cerca posible a 21\n");
    printf("2. Si te pasas, pierdes\n");
    printf("3. La casa va a parar hasta que supere o iguale 17\n");
    printf("4. Cada carta num�rica tiene su valor normal, el K, Q y J valen 10\n");
    printf("5. Los Ases pueden valer 1 u 11 seg�n convenga\n\n");

    int cartas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}; // Valores de las cartas
    char continuar = 's';

    while (continuar == 's') {
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
            printf("�Quieres otra carta? (s/n): ");
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
            printf("�Te has pasado! Pierdes.\n");
        } else if (valorManoJugador == valorManoCasa) {
            printf("�Empate!\n");
        } else if (valorManoJugador > valorManoCasa || valorManoCasa > 21) {
            printf("�Ganaste!\n");
        } else {
            printf("Gana la casa.\n");
        }

        printf("-------------------------------------------------\n");
        printf("�Quieres seguir jugando? (s/n): ");
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

void entrarMinijuegos(){
	bool salir = false;
    while (!salir) {
        menuMinijuegos();
        int opcion;
        printf("\nIngrese su opci�n: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (time(NULL) - ultimoJuegoTrabajar >= 60 || ultimoJuegoTrabajar == 0) { // Validar si han pasado 10 segundos desde el �ltimo juego
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
                printf("Opci�n no v�lida. Por favor, elija una opci�n v�lida.\n");
        }
    }
}
void menuMinijuegos(){
    printf("\n===== MEN� DE MINIJUEGOS =====\n");
    printf("1. Trabajar\n");
    printf("2. Jugar Mente Maestra\n");
    printf("3. Jugar Pesca\n");
    printf("4. Salir\n");
}

void jugarTrabajar() {
    printf("===== Minijuego: Trabajar =====\n");

    // Mensajes aleatorios al entrar al minijuego
    char *mensajes[] = {
        "Trabajaste 18 horas en la maquiladora y ganaste 200 pesos.",
        "Realizaste un trabajo freelance y recibiste un pago de 300 pesos.",
        "Hiciste algunas tareas en l�nea y obtuviste 150 pesos.",
        "Fuiste a trabajar como repartidor y ganaste 250 pesos.",
        "Te contrataron para una sesi�n de tutor�a y recibiste 180 pesos."
    };

    int num_mensajes = sizeof(mensajes) / sizeof(mensajes[0]);
    int indice_mensaje = rand() % num_mensajes;
    printf("%s\n", mensajes[indice_mensaje]);

     // Almacenar la hora en la que termin� el juego
    ultimoJuegoTrabajar = time(NULL);

    printf("\nRegresando al men� principal...\n");

}

void mostrarEstadisticas() {
    // Implementaci�n de mostrar estad�sticas(En construccion)
}

void tiendaVirtual() {
    // Implementaci�n de la tienda virtual(En construccion)
}

void guardarYcargarProgreso() {
    // Implementaci�n de guardar y cargar progreso(En construccion)
}

