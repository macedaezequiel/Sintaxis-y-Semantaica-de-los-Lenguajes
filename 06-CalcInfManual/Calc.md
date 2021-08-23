# Diseño Léxico del Lenguaje

Primero se genero una maquina de estado que identifique los tokens y lexemas validos para este LP en particular.

A la hora de implementarlo se desarrollo un scanner que tome los caracteres con la funcion getchar() y vaya almacenandolos en un buffer llamado 'lexema' hasta que el caracter que lee ya no sea parte de ese lexema.

Los caracteres se almacenan en una variable entera ya que son una representacion numerica en ascii

Un token es una categoria léxica, un lenguaje regular. En cambio, un lexema es un elemento que compone ese lenguaje regular

Una expresion regular es una expresion que describe que palabras son parte de un LR y cuales no.

Para resolver el problema de los espacios, cuando detecta que hay un espacio automaticamente pide el proximo token



## Gramatica Léxica

```xml
<token> ::= <constanteNatural> | <identificador> | <parentesis_Izq> | <parentesis_Der>| <adición> | <multiplicación> | <asignación> | <evaluación>
<constanteNatural> ::= <dígito> | <constanteNatural> <dígito> 
<identificador> ::= <letra> | <identificador> <letra> | <identificador> <dígito>
<adición> ::= +
<multiplicación> ::= *
<asignación> ::= =
<evaluación> ::= $
<letra> ::= una de a-z A-Z
<dígito> ::= uno de 0-9
<parentesis_Izq> ::= (
<parentesis_Der> ::= )
```

# Diseño sintáctico del Lenguaje

Para el Análisis Sintáctico se usa un análisis sintáctico descendente recursivo, ya que utiliza rutinas que pueden ser recursivas, cuya ejecución va "construyendo" un arbol de análisis sintáctico. Cada No terminal (a la izquierda) tiene asociada una rutina de analisis sintactico que puede reconocer cualquier secuencia de tokens generada por ese noterminal. La gramatica sintáctica presenta recursividad a derecha

## Gramatica Sintáctica

```xml
<programa>          ->  <listaSentencias> EOF
<listaSentencias>   ->  <sentencia> |  <listaSentencias> <sentencia>
<sentencia>         ->  <identificador> <asignación> <expresión> | <evaluación> <expresión>
<expresión>         ->  <termino> | <expresión> <adición> <termino>
<termino>           ->  <factor> | <factor> <multiplicacion> <termino>
<factor>            ->  <identificador> | <constanteNatural> | (<expresión>)
```


### Como usar la calculadora

La calculadora tiene dos funciones, la de evaluar una expresion y la de asignar una constante a un identificador. Para asignar un valor se debe usar el operador '=' y para evaluar una expresion se debe escribir el signo '$' antes de la expresion a evaluar.

Cada sentencia se debe ingresar en una nueva línea y para terminar el programa se debe enviar la señal de FDT (ctrl+z en Windows).
