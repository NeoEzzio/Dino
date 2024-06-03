# Juego en Arduino con ESP32
Este proyecto consiste en el desarrollo de un juego interactivo utilizando un microcontrolador ESP32 y componentes electrónicos como una pantalla LCD, un buzzer, un potenciómetro y una protoboard. El juego implementa un personaje principal, el dinosaurio, que debe esquivar obstáculos representados por cactus y aves, mientras acumula puntos.

## Características principales
### Dinosaurio: 
El protagonista del juego, con la capacidad de caminar y saltar para esquivar obstáculos.
### Cactus y Ave: 
Obstáculos y elementos secundarios del juego, con movimientos simulados para aumentar la complejidad.
### Interacción con el usuario: 
Utilización de un botón para que el jugador controle el salto del dinosaurio.
### Pantalla LCD y Buzzer: 
Proporcionan retroalimentación visual y auditiva al jugador durante el juego.
### Puntuación y velocidad: 
Se acumulan puntos a medida que el dinosaurio esquiva obstáculos, y la velocidad del juego aumenta para aumentar la dificultad.
Estructura del código
El código del juego está organizado en archivos modulares, con clases especializadas para cada elemento del juego. Se utilizan conceptos avanzados de programación, como la herencia y el polimorfismo, para facilitar su implementación y mantenimiento.

## Archivos principales
### Dinosaurio.cpp/h: 
Clase que representa al personaje principal del juego, con funciones para caminar, saltar y obtener su posición.
### Cactus.cpp/h: 
Clase que representa a los obstáculos del juego, con funciones para moverlos y obtener su posición.
### Ave.cpp/h: 
Clase que representa a los elementos secundarios del juego, con funciones para moverlos y obtener su posición.
### Main.ino: 
Archivo principal que contiene la configuración inicial y el bucle principal del juego.
Funciones clave
- caminar() y saltar(): Controlan el movimiento del dinosaurio.
- mover(): Gestiona el movimiento de los obstáculos y elementos secundarios del juego.
- mostrarEstadoFinal(): Muestra la puntuación final del jugador y un mensaje indicando el fin del juego.
Configuración de pines
- Pantalla LCD: Se asignan los pines 22, 23, 5, 18, 19 y 21 para la conexión de la pantalla LCD al ESP32.
- Botón y Buzzer: Los pines 4 y 25 se asignan para la conexión del botón y el buzzer al ESP32.
## Cambios y mejoras
Aparición aleatoria del Ave: Se implementa un algoritmo para que el Ave aparezca aleatoriamente en la pantalla, evitando colisionar con los cactus.
Conteo de puntos y ajuste de velocidad: La puntuación se incrementa cada vez que el dinosaurio esquiva un obstáculo, y la velocidad del juego aumenta según el puntaje acumulado.
Sonido del buzzer: Se reproduce un sonido cada vez que el jugador presiona el botón para que el dinosaurio salte.
