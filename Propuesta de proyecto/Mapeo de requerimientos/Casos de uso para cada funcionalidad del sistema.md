| CU-001 | Menú principal |     |
| --- | --- |     | --- |
| **Actor** | Jugador principal |     |
| **Descripción** | El programa permitirá al usuario acceder al menú |     |
| **Precondición** | El jugador ya ha iniciado el programa |     |
| **Secuencia normal** | **Paso** | **Acción** |
| 1   | El jugador inicia en el sistema |
| 2   | Se muestran las opciones del menú:” Instrucciones”,” Entrar al casino”, “Minijuegos”, “Estadísticas”, “Tienda virtual”,<br><br>“Cargar/guardar progreso”, y “Salir”. |
| **Primera ruta de acción** | 3   | El usuario ingresa en” instrucciones”. |
| 3.1 | El jugador selecciona las instrucciones de “Casino”. |
| 3.2 | El jugador selecciona las instrucciones de “Minijuegos”. |
| 3.3 | El jugador selecciona las instrucciones de “Tienda virtual” |
| 3.4 | El jugador regresa al menú principal |
| **Segunda ruta de acción** | 4   | El usuario ingresa en “Entrar al casino”. (CU-002) |
| 4.1 | El usuario regresa al menú principal |
| **Tercera ruta de acción** | 5   | El usuario Ingresa en “Minijuegos”. (CU-003) |
| 5.1 | El usuario regresa al menú principal |
| **Cuarta ruta de acción** | 6   | El usuario ingresa en “Estadísticas”. |
| 6.1 | Se le muestra al usuario sus respectivas estadísticas en formato de reporte de: “Porcentaje de victorias y derrotas”, “Ganancias totales”, “Saldo Actual”. |
| 6.2 | El usuario regresa al menú principal. |
| **Quinta ruta de acción** | 7   | El usuario ingresa en: “Tienda virtual”. (CU-004). |
| 7.1 | El usuario regresa al menú. |
| **Sexta ruta de acción** | 8   | El jugador ingresa en “Guardar/Cargar progreso”. (CU-005). |
| 8.1 | El jugador regresa al menú principal. |
| **Séptima ruta de acción** | 9   | El jugador sale del sistema. |
| **Octava ruta de acción** | 10  | El jugador escribe una opción que no está en el menú. |
| 10.1 | Se le muestra un mensaje de informándole que la opción puesta no está disponible en el menú. |
| 10.2 | El usuario vuelve a estar en el menú principal. |

| CU-002 | Casino |     |
| --- | --- |     | --- |
| **Actor** | Jugador principal |     |
| **Descripción** | El jugador puede jugar a los juegos del casino. |     |
| **Precondición** | El jugador ha accedido a esta opción en el menú principal y tiene créditos suficientes |     |
| **Secuencia normal** | **Paso** | **Acción** |
| 1   | Se le mostrará al jugador un menú de todas las opciones del casino: “Blackjack”, “Ruleta”, “Tragamonedas”, “Regresar al menú principal” |
| **Primera ruta de acción** | 2   | El usuario ingresa en” Blackjack ”. |
| 2.1 | El jugador ingresa la cantidad de créditos que apostar (250-50,000) |
| 2.1.1 | Si el jugador inserta una cantidad fuera del rango o en decimal, se le informará que ingrese de nuevo una cantidad. |
| 2.2 | El jugador empieza a jugar la mano de blackjack |
| 2.3 | Se le dan dos cartas al jugador y dos a la casa, pero a este último, una carta no se muestra para el jugador. |
| 2.4 | El jugador decide plantarse o pedir otra carta. |
| 2.4.1 | Si el jugador se planta, espera a que la casa tenga más que el jugador y 21 o menos. |
| 2.4.2 | Si el jugador pide más cartas, deberá tener 21 o menos. |
| 2.5 | El jugador pierde su dinero si la casa tiene 21 o está mas cerca de este o si se pasa de dicho número. |
| 2.5.1 | El jugador gana si tiene un número más grande que la casa y menor que 21 o si la casa se pasa |
| 2.5.2 | Se le pagará al jugador un 2.0 de su apuesta |
| 2.5.3 | Si en la primera mano el jugador obtiene Blackjack, una carta con valor de 10 y un as, ganará automáticamente la ronda, ganado un 2.5 de su apuesta. |
| 2.6 | El jugador desea jugar otra vez. |
| 2.7 | El jugador regresa al menú del casino |
| 2.8 | El jugador se queda sin créditos para jugar y se le regresa al menú principal |
| **Segunda ruta de acción** | 3   | El usuario ingresa en “Ruleta”. |
| 3.1 | El usuario apuesta en unas de las opciones. |
| 3.1.1 | El usuario decide apostar directo a un número (X35). |
| 3.1.2 | El usuario decide apostar por docenas (X3). |
| 3.1.3 | El usuario decide apostar por columnas (X3). |
| 3.1.4 | El usuario decide apostar por Mitades (X2). |
| 3.1.5 | El usuario decide apostar por Par o impar (X2) |
| 3.1.6 | EL usuario decide apostar por colores (X2) |
| 3.2 | El jugador ingresa una cantidad para apostar (250-50,000). |
| 3.2.1 | Si el jugador ingresa una cantidad incorrecta, se le informará que ingrese de nuevo una cantidad. |
| 3.3 | Se espera 10 segundos a que la ruleta termine de girar y se muestre el resultado. |
| 3.4 | Si se cumple la apuesta, ganará más créditos dependiendo de la apuesta. |
| 3.4.1 | Si no se cumple la apuesta, pierde los créditos. |
| 3.5 | El usuario decide jugar otra vez a la ruleta. |
| 3.6 | El jugador sale al menú del casino. |
| 3.7 | El jugador no tiene más créditos para jugar y se le regresa al menú principal. |
| **Tercera ruta de acción** | 4   | El usuario Ingresa en “Tragamonedas”. |
| 4.1 | El jugador ingresa la cantidad de créditos que apostar (250-50,000) para cada spin. |
| 4.2 | El jugador espera un tiempo y aparece el resultado en pantalla. |
| 4.3 | El jugador pierde el dinero que apostó en el spin. |
| 4.3.1 | El jugador multiplica su dinero dependiendo del resultado del spin. |
| 4.4 | El jugador hace otro spin. |
| 4.5 | El jugador no tiene más créditos para jugar y se le regresa al menú principal |
| 4.6 | El jugador regresa al menú del casino. |
| **Cuarta ruta de acción** | 5   | El usuario Regresa al menú principal. |
| **Quinta ruta de acción** | 6   | El jugador escribe una opción que no está en el menú del casino |
| 6.1 | Se le muestra un mensaje de informándole que la opción puesta no está disponible en el menú. |
| 6.2 | El usuario vuelve a ver el menú del casino |

| CU-003 | Minijuegos |     |
| --- | --- |     | --- |
| **Actor** | Jugador principal |     |
| **Descripción** | El jugador puede Ingresar a los minijuegos |     |
| **Precondición** | El jugador ha accedido a esta opción en el menú principal |     |
| **Secuencia normal** | **Paso** | **Acción** |
| 1   | Se le mostrará al jugador un menú de todas las opciones de los minijuegos: “Pesca”, “Trabajar”, “Mente maestra”, “Regresar al menú principal” |
| **Primera ruta de acción** | 2   | El usuario ingresa en” Pesca ”. |
| 2.1 | El jugador presiona la barra espaciadora para poder pescar en un tiempo de un minuto. |
| 2.2 | Pasado el tiempo, el jugador podrá ver cuántos créditos obtuvo. |
| 2.3 | El jugador tiene que esperar 5 min para volver a pescar. |
| 2.4 | Se regresa al usuario al menú de los minijuegos. |
| **Segunda ruta de acción** | 3   | El usuario ingresa en “Trabajar”. |
| 3.1 | Se le muestra un mensaje al jugador que ha hecho y se le darán los créditos dependiendo del trabajo (aleatorio) que haya hecho. |
| 3.2 | El jugador puede “trabajar” por 3 veces. |
| 3.3 | Utilizadas las 3 veces, el jugador tiene que esperar 5 minutos para volver a trabajar |
| 3.4 | Se regresa al usuario al menú de los minijuegos. |
| **Tercera ruta de acción** | 4   | El usuario Ingresa en “Mente maestra”. |
| 4.1 | El jugador resuelve el mayor número de operaciones matemáticas en un minuto para obtener créditos |
| 4.2 | Terminado el tiempo, el jugador puede ver los créditos que ha obtenido. |
| 4.3 | El jugador tiene que esperar 5 minutos para volver a jugar. |
| 4.4 | Se regresa al menú de los minijuegos. |
| **Cuarta ruta de acción** | 5   | El usuario Regresa al menú principal. |
| **Quinta ruta de acción** | 6   | El jugador escribe una opción que no está en el menú de los minijuegos. |
| 6.1 | Se le muestra un mensaje de informándole que la opción puesta no está disponible en el menú. |
| 6.2 | El usuario vuelve a ver el menú de los minijuegos. |

| CU-004 | Tienda virtual |     |
| --- | --- |     | --- |
| **Actor** | Jugador principal |     |
| **Descripción** | El jugador ingresa a la tienda virtual |     |
| **Precondición** | El jugador ha accedido a esta opción en el menú principal |     |
| **Secuencia normal** | **Paso** | **Acción** |
| 1   | Se le mostrará al jugador un menú de todas las opciones de la tienda virtual: “Multiplicadores de dinero”, “Personalización de estadísticas”, “Potenciadores de suerte”, “Regresar al menú principal”. |
| **Primera ruta de acción** | 2   | El usuario ingresa en” Multiplicadores ”. |
| 2.1 | El usuario verá un menú donde se le mostrarán los multiplicadores de los juegos de casino y minijuegos. |
| 2.2 | El usuario seleccionará una opción de los multiplicadores. |
| 2.3 | Si el jugador no tiene los suficientes créditos, se le informará que no puede comprar el multiplicador. |
| 2.4 | El usuario obtiene el multiplicador y los dispondrá en cualquier momento. |
| 2.5 | El usuario regresa al menú de la tienda virtual |
| **Segunda ruta de acción** | 3   | El usuario ingresa en” Personalización de estadísticas ”. |
| 3.1 | El usuario verá un menú donde se le mostrarán las personalizaciones de estadísticas de los juegos de casino. |
| 3.2 | El usuario seleccionará una opción del menú. |
| 3.3 | Si el jugador no tiene los suficientes créditos, se le informará que no puede comprar el elemento seleccionado. |
| 3.4 | Se regresa al usuario al menú de la tienda virtual. |
| **Tercera ruta de acción** | 4   | El usuario Ingresa en “Potenciadores de suerte”. |
| 4.1 | El usuario verá un menú donde se le mostrarán las personalizaciones de estadísticas de los minijuegos. |
| 4.2 | El usuario seleccionará una opción del menú. |
| 4.3 | Si el jugador no tiene los suficientes créditos, se le informará que no puede comprar el elemento seleccionado. |
| 4.4 | Se regresa al menú de la tienda virtual. |
| **Cuarta ruta de acción** | 5   | El usuario regresa al menú principal. |
| **Quinta ruta de acción** | 6   | El jugador escribe una opción que no está en el menú de la tienda virtual. |
| 6.1 | Se le muestra un mensaje de informándole que la opción puesta no está disponible en el menú. |
| 6.2 | El usuario vuelve a ver el menú de la tienda virtual. |

| CU-005 | Cargar/Guardar progreso |     |
| --- | --- |     | --- |
| **Actor** | Jugador principal |     |
| **Descripción** | El jugador puede cargar/guardar su progreso |     |
| **Precondición** | El jugador ha accedido a esta opción en el menú principal |     |
| **Secuencia normal** | **Paso** | **Acción** |
| 1   | Se le mostrará al jugador un menú de todas las opciones de la tienda virtual: “Cargar cuenta”, “Guardar cuenta”, y “Regresar al menú principal”. |
| **Primera ruta de acción** | 2   | El usuario ingresa en” Cargar Cuenta ”. |
| 2.1 | Se le pedirá al usuario ingresar: “Nombre de cuenta”, “Número de cuenta” |
| 2.1.1 | Si una de las opciones es incorrecta, se le informará al usuario que la cuenta es incorrecta o que no existe |
| 2.2 | Si la cuenta es correcta, se cargará todo el progreso de la cuenta seleccionada. |
| 2.3 | El usuario regresa al menú principal |
| **Segunda ruta de acción** | 3   | El usuario ingresa en” Guardar cuenta ”. |
| 3.1 | Se le pedirá al usuario ingresar “Nombre”, “Número de cuenta”, este último de 10 números. |
| 3.1.1 | Si alguno de los campos es incorrecto, se le informará al usuario que los vuelva a llenar |
| 3.2 | Si los campos son correctos, se guardará la cuenta exitosamente en el archivo correspondiente. |
| 3.3 | Se regresa al usuario al menú principal. |
| **Tercera ruta de acción** | 4   | El usuario regresa al menú principal |
| **Cuarta ruta de acción** | 5   | El jugador escribe una opción que no está en el menú. |
| 6.1 | Se le muestra un mensaje de informándole que la opción puesta no está disponible en el menú. |
| 6.2 | El usuario vuelve a ver el menú. |
