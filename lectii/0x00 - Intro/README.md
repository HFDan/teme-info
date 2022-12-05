# Intro

C++ este un limbaj de programare compilat, "general-purpose", imperativ.

## Compilat?

Un limbaj de programare compilat este un limbaj care necesita un program separat, numit "compiler", care genereaza
instructiunile rulate de procesor.

> dafuq does that mean?

Procesorul nu intelege textul scris de tine, iar tu nu intelegi 01100010 01101001 01101110 01100001 01110010 01111001. Compilerul "traduce" din textul pe care il scrii tu in instructiuni pe care procesorul le intelege.

Sa luam in considerare codul de mai jos.
(Nu e nicio problema daca nu intelegi tot ce scrie mai jos, vom discuta mai tarziu).

```c++
// code.cpp

#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;
    
    return 0;
}

```

Programul de mai sus ar trebui sa afiseze "Hello, world!" in consola.

Hai sa incercam sa il rulam!

```console
dani@overlord:~$ ./code.cpp
./code.cpp: line 3: syntax error near unexpected token '('
./code.cpp: line 3: 'int main(int argc, char** argv) {'
```

Tocmai am incercat sa rulam cod de C++ drept un [Shell Script](https://en.wikipedia.org/wiki/Shell_script), ceea ce, in mod evident, nu va functiona. Avem nevoie de o metoda sa transformam codul nostru in ceva ce procesorul poate intelege.

### The compiler saves the day

Pentru a rula codul nostru, acesta trebuie **compilat**.

Exista mai multe compilatoare de C++.
| Compiler  | Windows       | Linux        | MacOS X          |
| --------- | ------------- | ------------ | ---------------- |
| MSVC      | ✅             | ❔ (Via Wine) | ❌                |
| GNU (G++) | ✅ (Via MinGW) | ✅            | ✅ (Via homebrew) |
| Clang     | ✅             | ✅            | ✅                |
| Intel     | ✅             | ✅            | ✅                |

Personal, daca esti pe Windows, recomand fie [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/), fie [clang-cl](https://visualstudio.microsoft.com/vs/features/cplusplus/) (MSVC vine impreuna cu clang-cl).

Daca esti pe OSX sau Linux, recomand **clang**.

Deci, hai sa compilam codul nostru!

```console
dani@overlord:~$ clang++ code.cpp
```

By default, clang si gcc for genera un executabil cu numele `a.out`. MSVC in schimb genereaza un executabil cu acelasi nume pe care il are fisierul care contine codul nostru (aici, `code.exe`).

Linux/OSX:

```console
dani@overlord:~$ ./a.out
Hello, world!
```

Windows:

```console
C:\Users\dani> run lmao.exe
Hello, world!
```

Nota: De aici in colo, vor fi aratate doar prompt-uri pentru Linux/OSX...

Deci, ce s-a intamplat?

Compilatorul nostru a transformat codul in:

```c
0x55                   
0x48 0x89 0xe5             
0x48 0x83 0xec 0x10          
0xc7 0x45 0xfc 0x00 0x00 0x00 0x00 
0x89 0x7d 0xf8             
0x48 0x89 0x75 0xf0          
0x48 0x8b 0x3d 0xf3 0x2d 0x00 0x00 
0x48 0x8d 0x35 0x30 0x0e 0x00 0x00 
0xe8 0x67 0xfe 0xff 0xff       
0x48 0x89 0xc7             
0x48 0x8b 0x35 0xcd 0x2d 0x00 0x00 
0xe8 0x68 0xfe 0xff 0xff       
0x31 0xc0                
0x48 0x83 0xc4 0x10          
0x5d                   
0xc3                   
```

Dar, sa citesti instructiuni in hexazecimal e cam greu, asa ca o sa le traducem in instructiuni *mnemonice*

```asm
; a.out+0x11b0

main:
    ; Prologue. Asa incepe fiecare functie in C/C++
    ; Cateodata, in loc de cele doua instructiuni vei vedea 'enter'. Inseamna acelasi lucru.
    0x00000000000011b0 <+0>:    push   rbp
    0x00000000000011b1 <+1>:    mov    rbp,rsp
    
    ; Alocam memorie pe stack (vom studia stack-ul si heap-ul mai tarziu)
    0x00000000000011b4 <+4>:    sub    rsp,0x10

    ; Mutam cateva valori pe stack. Nu par sa fie folosite la ceva.
    0x00000000000011b8 <+8>:    mov    DWORD PTR [rbp-0x4],0x0
    0x00000000000011bf <+15>:   mov    DWORD PTR [rbp-0x8],edi
    0x00000000000011c2 <+18>:   mov    QWORD PTR [rbp-0x10],rsi

    ; Pregatim un "apel" catre o functie.
    0x00000000000011c6 <+22>:   mov    rdi,QWORD PTR [rip+0x2df3] ; Mutam valoarea primului parametru in registrul rdi
    0x00000000000011cd <+29>:   lea    rsi,[rip+0xe30] ; Al doilea parametru e mutat in registrul rsi
    0x00000000000011d4 <+36>:   call   0x1040 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt> ; Apelam o functie cu un nume gigantic. Functia va returna o valoare in registrul rax.

    0x00000000000011d9 <+41>:   mov    rdi,rax ; Mutam valoarea returnata de prima functie in rdi
    0x00000000000011dc <+44>:   mov    rsi,QWORD PTR [rip+0x2dcd] ; Al doilea parametru in rsi.
    0x00000000000011e3 <+51>:   call   0x1050 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt> ; Mai apelam inca o functie

    0x00000000000011e8 <+56>:   xor    eax,eax ; Setam eax sa fie 0. eax este versiunea "mica" a lui rax. rax are 64 de biti, iar eax are 32.

    0x00000000000011ea <+58>:   add    rsp,0x10 ; De-alocam memoria de pe stack.

    ; Epilog. Fiecare functie in C/C++ se termina asa.
    0x00000000000011ee <+62>:   pop    rbp ; Cateodata, in loc de 'pop rbp' vei vedea 'leave'. Sunt acelasi lucru.
    0x00000000000011ef <+63>:   ret    
```

Este OK daca nu intelegi instructiunile inca. Le arat decat pentru a demonstra ce face compilerul.

## In sfarsit, code

In sfarsit, dupa ce am vazut ce face compilerul, vom scrie primul nostru program.

Programul va afisa un mesaj in consola.

Vom incepe cu niste boilerplate. Fiecare program trebuie sa aiba o functie cu semnatura `int main(int, char**)`, care preia doua argumente. `argc` si `argv`. Vom studia semnificatia celor doua argumente mai tarziu.

Utilizarea unei functii `main` cu semnatura `int main(void)` sau `voud main(void)` nu este indicat, chiar daca sunt acceptate.

In functia `main` vom returna `0` daca programul si-a terminat executia cu succes.

```c++
// code.cpp

// BAD!
int main() {
    return 0;
}

// EVEN WORSE!
void main() {

}

// GOOD!
int main(int argc, char** argv) {
    return 0;
}

// OK, dar non-standard. A se folosi decat pe OSX/Linux
int main(int argc, char** argv, char** envp) {
    return 0;
}
```

Pentru a afisa un mesaj, vom folosi **`obiectul`** `std::cout` (ATENTIE: NU e o functie, e un **obiect**).

```c++
// code.cpp

int main(int argc, char** argv) {
    std::cout << "Un mesaj foarte interesant" << std::endl; // Observa ca fiecare "instructiune" se termina cu ';'
    return 0;
}

```

Hai sa il compilam!

```console
dani@overlord:~$ clang++ code.cpp
code.cpp:2:3: error: use of undeclared identifier 'std'
  std::cout << "Un mesaj foarte interesant" << std::endl;
  ^
code.cpp:2:48: error: use of undeclared identifier 'std'
  std::cout << "Un mesaj foarte interesant" << std::endl;
                                               ^
2 errors generated.

```

> Ce s-a intamplat?

Se pare ca clang nu poate gasi **simbolul** numit `std`, deoarece noi nu l-am declarat nicaieri.

Am incercat sa folosim functii din STL (Standard Template Library. STL este un set de functii si clase care ajuta in folosirea eficienta a C++. STL este inclus cu compiler-ul in general.), fara sa le declaram intai.

Pentru a folosi `std::cout` si `std::endl`, va fi nevoie sa **includem** iostream, un component al STL.

```c++
// code.cpp
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Un mesaj foarte interesant" << std::endl; // Observa ca fiecare "instructiune" se termina cu ';'
    return 0;
}
```

Acum programul poate fi compilat fara erori.

```console
dani@overlord:~$ clang++ code.cpp
dani@overlord:~$ ./a.out
Un mesaj foarte interesant
```

Note: `#include` desi este asemanator cu `import` din python, JS, C#, etc. NU face acelasi lucru. `#include` va citi fisierul pe care i-l dai, il va copia, si ii va da paste in locul sau.

Adica, `#include "code.cpp"`, va fi inlocuit de compiler cu continutul fisierului `code.cpp`

Poti citi continutul fisierului `iostream` [aici](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/iostream)
