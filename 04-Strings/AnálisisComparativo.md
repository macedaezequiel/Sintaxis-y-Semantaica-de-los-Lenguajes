
# Análisis Comparativo
------
a. **¿El tipo es parte del lenguaje en algún nivel?**

   * En C, a nivel semántico se manejan como secuencias de caracteres 
   * En Python, el tipo de dato pertenece al lenguaje y contieneoperaciones propias del string como 'string.upper()'
   
b. **¿El tipo es parte de la biblioteca?**   

   * En C, no existe el tipo de dato String. Cuando se necesita manipular strings, se utilizan "arrays" de tipo *char*. Se puede hacer uso de la libreria string.h para obtener funciones que manejen cadenas de caracteres.
   * En Python, Existe el String como tipo de dato pero tiene un funcionamiento parecido al array de chars, se incluyen algunas operaciones mas

c. **¿Qué alfabeto usa?**
   
   * C utiliza los simbolos del alfabeto ASCII como alfabeto.   
   * En Python se incluyen los mismos caracteres + caracteres Unicode.

d. **¿Cómo se resuelve la alocación de memoria?**

   * En C, cuando se declara una variable se reserva la memoria automáticamente para el tipo de dato, incluso si ésta tiene vacío su contenido. En el caso de manejar una cadena, se almacena en la variable el puntero a primer elemento del arreglo de caracteres.
   * En Python, Internamente se almacena la dirección de memoria del objeto string pero como programadores no operamos con el puntero sino directamente con el string, el lenguaje nos provee de esta abstracción.

e. **¿El tipo tiene mutabilidad o es inmutable?**

   * En C los *strings* al ser un array de caracteres permiten la mutabilidad de sus componentes.
   * En Python son inmutables, esto quiere decir que cada vez que modificamos un string crea en memoria una nueva instancia del objeto con el resultado

f. **¿El tipo es un *first class citizen*?**

   * En C, las cadenas no son consideradas *FCC*.
   * En Python si lo son.

g. **¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos?**

   * En C, se pasa la direccion del primer elemento del array.
   * En Python, se pasa directamente la variable.

h. **¿Y cuando son retornados por una función?**

   * En C, se retorna un puntero a un char.
   * En Python, se retorna una variable de tipo *string*.

------
