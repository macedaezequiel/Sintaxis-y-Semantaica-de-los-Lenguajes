# Trabajo 4
# Operaciones con Strings

## GetLength
GetLength : Σ* -> N / GetLength(string) = { 0   si string='/0'
                                          { GetLength(string) +1    si string = string * w AND w ∈ Σ*

## IsEmpty

IsEmpty : Σ* -> Bool / IsEmpty(string) = { True   si String = '/0'
                                         { False  si String != '/0'

## MyStrcmp

MyStrcmp : Σ* x Σ* -> Bool / MyStrcmp(string1,string2) = {True      si String1=String2
                                                         { False    si String1!≠String 2 

## Power

Power : Σ* x N -> Σ* / Power(string1,n) = { '/0'                          si n=0
                                          {string                         si n=1
                                          {string1*Power(string1, n-1)    si string!= null
