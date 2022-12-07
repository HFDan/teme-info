# Scoping, Variabile si I/O

## Variabile

O variablia este o unitate de memorie careia ii este atribuita o valoare. Folosim variablie pentru a salva valori si a le accesa mai tarziu.

### Declarare

Declaram variabile dupa urmatorul model

`[modificatori] <tip> [modificatori] <nume> [= valoare];`

```c++
// Acestea sunt numai tipurile PRIMITIVE de variabile.
// O variabila poate stoca si un obiect.

char byte = 'a'; // Un caracter. Desi char este facut sa stocheze caractere, poate stoca orice numar intre -128 si 127. Also, char e folosit des pentru a accesa direct memorie, fiind cea mai mica unitate accesibila (8 biti, adica 1 byte).
char alt_caracter = 24; // OK

int un_numar_intreg = 1; // Numar intreg intre -2.147.483.648 si 2.147.483.647

float numar_real_mic = 0.5; // Maxim 7 cifre
double numar_real_mare = 0.55523; // Maxim 15 cifre

bool a_f = true // Bool poate fi fie 'true' sau 'false'. Nimic altceva.

```

#### Modificatori

Inainte de nume, putem adauga modificatori, cum ar fi `const`, `unsigned`, `long`, `short`

##### const

Const face o variabila sa nu mai poata fi modificata.

```c++
const int a = 5;

a = 2; // Eroare la compilare.

```

##### unsigned

Unsigned schimba `int` din numere intregi in naturale.

```c++
unsigned int a = 5;

unsigned int b = -1; // Comportament nedefinit. Va deveni 4294967295
```

##### long

Long 'dubleaza' lungimea unei variabile **primitive**.

```c++
long int a; // Din 32 de biti, acum avem 64. Cuprins intre -9.223.372.036.854.775.808 si 9.223.372.036.854.775.807
long long int a; // Nu va face nimic (in general). Are efect doar pe platformele unde int are 16 biti.

// Variablilele de sus pot fi scrise fara int
long a; // OK
long long a; // Tot OK

long double a; // Definit de compiler. Unele compilere accepta long double, altele il trateaza ca pe orice alt double.
```

##### short

Short 'injumatateste' lungimea unui `int`.

```c++
short int a; // Numar intre -32768 si 32767
short a; // Acelasi lucru
```

## I/O

I/O inseamna 'Input-Output'. Este procesul prin care se obtine comunicare cu utilizatorul, un fisier, etc.

Fisierul `iostream` contine functii si obiecte care ne pot ajuta.

```c++
#include <iostream>

// Citim un numar intreg
int a;
std::cin >> a; // std::cin citeste din fisierul 'stdin' pana la primul 'space'.

std::cout << a; // Stim deja ce face.
```

### stdout si stdin

`stdout` si `stdin` sunt niste fisiere speciale. Atunci cand programul porneste, ele sunt 'legate' de consola.

Pentru a *scrie* in consola, sciriem in fisierul `stdout`.

Pentru a *citi* din consola, citim din fisierul `stdin`.

`std::cin` si `std::cout` sunt niste obiecte care citesc si scriu din `stdin` si `stdout`.

Pe langa `stdin` si `stdout` mai exista si `stderr`.

In `stderr` scriem erori, folosind `std::cerr`.

```c++
#include <iostream>

std::cerr << "O eroare interesanta";

```

`stderr` nu este 'legat' de `stdout`, iar mesajele afisate in `stdout` vor aparea mai repede ca cele din `stderr` (in unele cazuri).

De exemplu:

```c++
#include <iostream>

std::cerr << "Eroare" << std::endl;
std::cout << "Mesaj" << std::endl;
```

Poate afisa:

```console
Mesaj
Eroare
```

## Scoping

'Scopurile' sunt sectiuni de cod in care variabilele 'traiesc'

Un 'scop' este o sectiune de cod situata intre `'{'` si `'}'`. Variablilele dintr-un scop pot fi accesate **numai** in interiorul scopului in care au fost creeate.

Exemplu:

```c++
int main(int argc, char** argv) {
    int a = 5;

    {
        int b = 2;
        std::cout << b; // OK. 'b' se afla in scop.
        std::cout << a; // Tot OK. Si 'a' se afla in scop.
    }

    {
        int c = 4;
        std::cout << c; // OK
        std::cout << a; // OK.
        std::cout << b; // 'b' nu e in scopul nostru.
    }
    
    std::cout << a; // OK
    std::cout << b; // Nu se va compila. 'b' nu se afla in scopul in care se regaseste aceasta linie de cod.
    std::cout << c; // Also nope.
}
```

La sfarsitul unui scop, fiecare variablila din interiorul sau 'moare'.

```c++
int main(int argc, char** argv) {
    int a = 5;

    {
        int b = 2;
        // 'b' moare
    }

    {
        int c = 4;
        // 'c' moare
    }
    
    // 'a' moare
}
```

Cand spunem ca o variabila 'moare', inseamna ca memoria unde se afla acea variabila este eliberata, iar *destructorul* sau e apelat (unde e cazul).

### Shadowing si ODR

#### Shadowing

'Shadowing' inseamna  **redefinirea** unei variabile intr-un scop mai 'adanc'.

```c++
int a = 7;
{
    int a = 10; // Atentie: NU este acelasi 'a'. Este cu totul alta variabila. 'a'-ul din scopul superior si 'a'-ul acesta au doar acelasi nume.
    std::cout << a << std::endl; // Orice referinta la 'a' va fi reprezentata de variabila 'a' din cel mai apropiat scop.
}
std::cout << a << std::endl;
```

Va afisa:

```console
10
7
```

Prin shadowing, putem schimba si *tipul* unei variabile.

```c++
int a = 7;
{
    double a = 2.5;
    std::cout << a << std::endl;
}
std::cout << a << std::endl;
```

Va afisa:

```console
2.5
7
```

#### ODR

ODR (One definiton rule) spune ca intr-un program o variabila, o functie, o clasa, etc. poate fi definita **cel mult** odata.

```c++
int a = 54;
a = 24; // Ok. Nu creem alt 'a'. Este acelasi 'a'. Doar i-am schimbat valoarea.

int a = 123; // Eroare compiler. 'a' a fost definit deja.
```

Exceptie de la ODR face conceptul de shadowing, explicat mai sus.
