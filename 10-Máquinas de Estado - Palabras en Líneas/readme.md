# Máquinas de Estado - Palabras en Lineas

## Enunciado

Problema: Imprimir cada palabra de la entrada en su propia línea. La cantidad
de líneas en la salida coincide con la cantidad de palabras en la entrada. Cada
línea tiene solo una palabra.

### Tareas

#### 1. Árboles de Expresión

a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
de [KR1988].
b. Dibujar el árbol de expresión para la inicialización de los contadores: nl
= nw = nc = 0.
c. Dibujar el árbol de expresión para la expresión de control del segundo if:
c == ' ' || c == '\n' || c == '\t'.

#### 2. Máquina de Estado:

a. Describir en lenguaje dot [DOT2015] y dentro del archivo wl.gv la
máquina de estado que resuelve el problema planteado.
b. Formalizar la máquina de estados como una n-upla, basarse en el
Capítulo #1 del Volumen #3 de [MUCH2012].

#### 3. Implementaciones de Máquinas de Estado:

Las implementaciones varían en los conceptos que utilizan para representaar
los estados y las transiciones.

a. Implementación #1: Una variable para el estado actual.
i. Escribir el programa wl-1-enum-switch.c que siga la Implementación
#1, variante enum y switch.
Esta implementación es la regularización de la implementación de la
sección 1.5.4 de [KR1988]. Los estados son valores de una variable y
las transiciones son la selección estructurada y la actualización de esa
variable. Esta versión es menos eficiente que la versión de [KR1988],
pero su regularidad permite la automatización de la construcción del
programa que implementa la máquina de estados. Además de la
regularidad, esta versión debe:
* Utilizar typedef y enum en vez de define, de tal modo que la
variable estado se pueda declarar de la siguiente manera: State
s = Out;
* Utilizar switch en vez de if.
ii. Responder en readme.md: Indicar ventajas y desventajas de la versión
de [KR1988] y de esta implementción.

b. Implementación #2: Sentencias goto (sí, el infame goto)
i. Leer la sección 3.8 Goto and labels de [KR1988]
ii. Leer Go To Statement Considered Harmful de [DIJ1968].
iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].
iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día?
¿Algún lenguaje moderno lo utiliza?
v. Escribir el programa wl-2-goto.c que siga la Implementación #2.
En esta implementación los estados son etiquetas y las transiciones
son la selección estructurada y el salto incondicional con la sentencia
goto.




# Resolución

## 1

#### b. Arbol de expresión para la inicialización de contadores
![alt text](https://github.com/macedaezequiel/Sintaxis-y-Semantaica-de-los-Lenguajes/blob/master/10-M%C3%A1quinas%20de%20Estado%20-%20Palabras%20en%20L%C3%ADneas/Images/Arbol%20de%20expresion%20-%20Inicializacion%20de%20contadores.png "Arbol de expresión para la inicialización de contadores")


#### c. Arbol de expresión para el Control del segundo If

![alt text](https://github.com/macedaezequiel/Sintaxis-y-Semantaica-de-los-Lenguajes/blob/master/10-M%C3%A1quinas%20de%20Estado%20-%20Palabras%20en%20L%C3%ADneas/Images/Arbol%20de%20expresion%20-%20Control%20del%20segundo%20if.png "Arbol de expresión para el Control del segundo If")

## 2

#### a. Maquina de estados - Problema planteado

![alt text](https://github.com/macedaezequiel/Sintaxis-y-Semantaica-de-los-Lenguajes/blob/master/10-M%C3%A1quinas%20de%20Estado%20-%20Palabras%20en%20L%C3%ADneas/Images/Maquina%20de%20estados%20-%20Problema%20planteado.png "Maquina de estados - Problema planteado")

Nota: Aunque en el gráfico no supe como agregarlo, el estado inicial debería tener un supraindice con el simbolo '-' y el estado final uno con el '+'.

### b)

Formalizo la máquina de estados como una 5-upla de la siguiente manera  (Q, Σ, T, q0, F),

* Q es un conjunto finito no vacío de estados {Estado inicial, SAMELINE, NEWLINE, ENDOF(Estado Final)},
* Σ es el alfabeto de caracteres reconocidos por la máquina de estados (Todos los caracteres que acepte el lenguaje C),
* q0 ∈ Q es el estado inicial (Estado Inicial),
* F ∈ Q es el conjunto no vacío de estados finales (Estado Final)
* T: Q x Σ -> Q es la función de transiciones, es decir: T (q, x) = z significa que z es el estado al
cual transita la máquina de estados desde el estado q, al leer el carácter x.

## 3

a) ii. *Agregar ventajas y desventajas de esta version*

b) iv. A veces se puede justificar su uso pero generalmente ya no se usa.

