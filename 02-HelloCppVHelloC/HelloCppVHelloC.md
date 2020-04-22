# C vs C++

### Hola Mundo en C

```C
#include <stdio.h>
int main()
{
    printf("Hola Mundo!");   
}
```


### Hola Mundo en C++

```C++
#include <iostream>
int main() {
    std::cout << "Hola Mundo!";

}
```


|     |     | C++ | C |
| --- | --- | --- | --- |
| Léxico | Diferencias | **std::cout <<** "Hola Mundo!" && **iostream** | **printf**("Hola Mundo!") **stdio.h**|
|        | Similitudes | El resto de simbolos que usan son iguales | El resto de simbolos que usan son iguales |
| Sintáctico | Diferencias | No hay diferencias Sintácticas | No hay diferencias Sintácticas |
|            | Similitudes |    Son similares Sintácticamente          |          Son similares Sintácticamente     | 
| Semántico | Diferencias | Se redirige el string  | Se llama a la función **printf()** |
|            | Similitudes |    El resto de simbolos estan Semánticamente iguales           |  El resto de simbolos estan Semánticamente iguales          |
