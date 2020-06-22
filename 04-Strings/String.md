# Trabajo 4
# Operaciones con Strings

## GetLength
GetLength : Σ* -> N / GetLength(string) = { 0   si string=Epsilon
                                          { GetLength(string) +1    si string = string * w AND w ∈ Σ*

## IsEmpty

IsEmpty : Σ* -> Bool / IsEmpty(string) = { True   si String = Epsilon
                                         { False  si String != Epsilon

## MyStrcmp

MyStrcmp : Σ* x Σ* -> Bool / MyStrcmp(string1,string2) = {True      si String1=String2
                                                         { False    si String1!≠String 2 

## Power

Power : Σ* x N -> Σ* / Power(string1,n) = { Epsilon                       si n=0 OR 
                                          {string1                        si n=1
                                          {string1*Power(string1, n-1)    si string!= null
