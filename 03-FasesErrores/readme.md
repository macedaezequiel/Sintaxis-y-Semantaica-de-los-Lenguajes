# Fases de la Traducción y Errores

## Enunciado

### 6.1. Objetivos
* Identificar las fases de traducción y errores.
### 6.2. Temas
* Fases de traducción.

* Preprocesamiento.

* Compilación.

* Ensamblado.

* Vinculación (Link).

* Errores en cada fase.

### 6.3. Tareas

1. Investigar las funcionalidades y opciones que su compilador presenta para
limitar el inicio y fin de las fases de traducción.

2. Para la siguiente secuencia de pasos:
a. Transicribir en readme.md cada comando ejecutado y
b. Describir en readme.md el resultado u error obtenidos para cada paso.

### 6.3.1. Secuencia de Pasos
1. Escribir hello2.c, que es una variante de hello.c:

```C
#include <stdio.h>
int/*medio*/main(void){
int i=42;
 prontf("La respuesta es %d\n");
```

2. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su
contenido.

3. Escribir hello3.c, una nueva variante:

```C
int printf(const char *s, ...);
int main(void){
int i=42;
 prontf("La respuesta es %d\n");
```

4. Investigar la semántica de la primera línea.

5. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias
entre hello3.c y hello3.i.

6. Compilar el resultado y generar hello3.s, no ensamblar.

7. Corregir en el nuevo archivo hello4.c y empezar de nuevo, generar
hello4.s, no ensamblar.

8. Investigar hello4.s.

9. Ensamblar hello4.s en hello4.o, no vincular.

10.Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

11.Corregir en hello5.c y generar el ejecutable.

12.Ejecutar y analizar el resultado.

13.Corregir en hello6.c y empezar de nuevo.

14.Escribir hello7.c, una nueva variante:

```C
int main(void){
int i=42;
 printf("La respuesta es %d\n", i);
}
```

15.Explicar porqué funciona.

### 6.4. Restricciones
* El programa ejemplo debe enviar por stdout la frase La respuesta es 42, el
valor 42 debe surgir de una variable.

## Resolución

2. Para preprocesar hello2.c uso el comando gcc -E hello2.c -o hello2.i. El resultado que observo es que se genera hello2.i

4. En la primer linea declara la función printf. Int es el tipo de dato que retorna la funcion, printf es el nombre de la funcion, entre parentesis van los parametros que la fucion espera. const char * es el tipo de dato que espera que le pasen. "s" es el nombre de la variable que usara la funcion para trabajar con los datos que reciba por parametros.

5. Para preprocesar hello3.c uso el comando -E hello3.c -o hello3.i. La diferencia es que en hello3.i hay cuantro lineas extra al comienzo del archivo.

6. Para generar hello3.s uso el comando gcc -S hello3.c. Al usar este comando obtengo un warning, aconsejandome que escriba printf y no prontf. Además tengo que cerrar la llave del main para que no me tire un error.

7. Para generar hello4.s uso el comando gcc -S hello4.c. Ahora solo obtengo el warning.

8. En hello4.s puedo observar lenguaje assembler, identifico muchas funciones vistas en clase.

9. Para ensamblar sin vincular uso el siguiente comando: gcc -c hello4.c. Se crea el archivo hello4.o.

10. Para este punto modifico la funcion prontf que no existe y la escribo como printf. Se crea el ejecutable.

12. Como a printf no le paso su segundo parametro, en el que deberia poner la variable a la que hace referencia %d, cada vez que lo ejecuto me da un valor distinto.

13.  

15. hello7.c funciona porque le estoy especificando a printf que el valor uqe quiero que ponga en lugar del %d es el que esta en la variable i.

