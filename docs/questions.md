# Practice Questions — Day 1 to Day 7

---

## Day 1 — Hello World & GCC Setup

### Theory

1. What does `gcc -Wall -Wextra -g` do? Explain each flag.

- `gcc -Wall -Wextra -g` it prints the results when building a file to show if there are warnings into the problem such as untiliazed variables, trying to convert int to a string.

2. What is the difference between a compiler and an assembler?

- Compler converts human code into machine code so that the assembler can understand but assmbler what it does is that converts machine code into 0s and 1s so that the CPU can understand those instructions.

3. What are the 4 stages of C compilation (preprocessing, compilation, assembly, linking)?

- preprocessing involves checking for preprocessor directives into the project for exampel `#include<stdio.h>`.

- complication involves converting machine code into the asembly code so that CPUs can understand.

4. What file does `gcc` produce by default if you don't use `-o`?

- It produces the `./a.out` file.

5. What is a `Makefile` and why use one instead of typing `gcc` manually?

- Basically Makefile saves time, prevents rebuilding which helps to save computation for the machine, so Makefile it is a tool which is used to configure into the gcc should run files into the machine.

### Practical

1. Write a program that prints your name and age on separate lines.

```c
#include <stdio.h>

int main()
{

  int age = 23;
  char name[] = "Njox";

  printf("My name is: %s\n", name);
  printf("My age is: %d\n", age);

  return 0;
}
```

2. Compile it using `gcc` with debug symbols enabled. Then use `file` command on the output binary — what does it tell you?

```Makefile
# target dep
printName: printName.c
	gcc printName.c -o printName -Wall -Wextra -g

# clean
clean:
	rm -rf main a.out main.o printName
```

```sh
└─$ file printName
printName: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=3317f5e7aa4eee14cc55e4089435d4df9fb05880, for GNU/Linux 3.2.0, with debug_info, not stripped
```

- it tells me that the file is 64 bit, executable and CPU architecture is x86-64 and debugger is GNU/Linux.

3. Write a Makefile with `build`, `clean`, and `run` targets.

```Makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
CFILENAME = main.c
CBUILDFILE = main

main.c: main
	$(CC) -o $(CBUILDFILE) $(CFLAGS)

run:
	./CBUILDFILE

clean:
	rm -rf a.out $(CBUILDFILE) main.o
```

4. Use `gcc -E main.c` to see preprocessor output. What does `#include <stdio.h>` actually do?

- The stdio.h is the preprocessor directives which contains pre-written files which are used into Kali linux for compiling files and provides pre written files for the machine.

5. Compile your program to assembly with `gcc -S main.c`. Open `main.s` — can you find your string in it?

- I get a list of code which are written into assembly code which are scarry.

---

## Day 2 — Data Types & `sizeof()`

### Theory

1. How many bits are in 1 byte? 8 bit
2. What is the difference between `int`, `short`, `long`, and `long long` in terms of size?

- int has 4 bytes, short 4, long 8, long long 8.

3. Why does `sizeof(void *)` return the same value regardless of what it points to?

- 4 bytes

4. What format specifier do you use to print `sizeof()` results and why?

- `%zu` is used to format the size of the data type.

5. Why might `sizeof(int)` differ on a 32-bit vs 64-bit machine?

- because of different data size architecture also based on data model for some of the CPUs

### Practical

1. Write a program that prints the size of every basic C type (`char`, `short`, `int`, `long`, `long long`, `float`, `double`, `void *`) in both **bytes and bits**.

```c
#include <stdio.h>

int main()
{
    printf("The size of char: %zu\n", sizeof(char));
    printf("The size of short: %zu\n", sizeof(short));
    printf("The size of int: %zu\n", sizeof(int));
    printf("The size of long: %zu\n", sizeof(long));
    printf("The size of long long: %zu\n", sizeof(long long));
    printf("The size of float: %zu\n", sizeof(float));
    printf("The size of double: %zu\n", sizeof(double));
    printf("The size of void: %zu\n", sizeof(void *));

    return 0;
}
```

2. What does this print and why?
   ```c
   char a = 127;
   a = a + 1;
   printf("%d\n", a);
   ```
3. Write a program that shows the **range** (min and max) of `char`, `int`, and `long` using `<limits.h>`.
4. Declare a `struct` with a `char`, an `int`, and a `double`. Print `sizeof()` of the struct. Is it equal to the sum of its members? Why or why not?

```c
#include <stdio.h>

struct Info
{
    int age;
    double salary;
    char name[12];
};

int main()
{
    // Declare a `struct` with a `char`, an `int`, and a `double`. Print `sizeof()` of the struct. Is it equal to the sum of its members? Why or why not?
    struct Info person;

    printf("The size of struct: %zu\n", sizeof(person));

    return 0;
}
```

5. Use `xxd` to inspect the binary of your compiled program. Can you find the string literals in the hex dump?

---

## Day 3 — Bitwise Operators

### Theory

1. What is the result of `5 & 3`? Work it out in binary.
2. What is the difference between `&` and `&&`?
3. What does `~0` evaluate to and why?
4. How is left shift (`<<`) related to multiplication? How is right shift (`>>`) related to division?
5. Why are bitwise operators important in reverse engineering and malware analysis?

### Practical

1. Write a program that takes an integer and prints its binary representation using bitwise shifts.
2. Write a function `int is_bit_set(int num, int pos)` that checks if bit at position `pos` is set.
3. Use XOR to swap two variables **without a temporary variable**.
4. Write a program that sets, clears, and toggles the 3rd bit of a number.
5. XOR encryption: write a program that XOR-encrypts a string with a key byte, then decrypts it back. Print hex values using `%02x`.

---

## Day 4 — Pointers Fundamentals

### Theory

1. What is the difference between `&x` and `*p`?

- & stores the memory address of the variable and \* stores the value of the pointer variable.

2. If `int *p = &x`, what does `p` hold vs what does `*p` hold?

- p holds the memory location of x while \*p stores the value of the varibale.

3. What happens if you dereference a NULL pointer?
4. What is pointer arithmetic — what does `p + 1` actually add in bytes if `p` is an `int *`?

- Pointer arithmetic is the operation of adding a value into the pointer and `p + 1` moves the pointer one step based on the size of the variable.

5. Why do pointers matter in reverse engineering? (Think: memory addresses, stack, heap)

- Pointers matters because it helps to get memory location of the variables into the system also helps to get the memory location of the variable based on variable.

### Practical

1. Write a program that declares an `int`, creates a pointer to it, modifies the value through the pointer, and prints both the value and the address.

2. Given `int arr[] = {10, 20, 30, 40, 50}`, use a pointer (not `arr[i]`) to print all elements.
3. Write a `void swap(int *a, int *b)` function and demonstrate it works.
4. What does this print?
   ```c
   int x = 42;
   int *p = &x;
   printf("%ld\n", (long)(p + 1) - (long)p);
   ```
5. Write a program that prints the address of each element in an array. Verify the difference between consecutive addresses matches `sizeof(int)`.

---

## Day 5 — Double Pointers & Arrays

### Theory

1. What is a pointer to a pointer? Draw a diagram of `x`, `*p`, and `**dd`.
2. Why is `arr[i]` the same as `*(arr + i)`?
3. What is the difference between `int *p` and `int **pp`? How many dereferences to reach the value?
4. When would you use a double pointer in practice?
5. Can an array name be reassigned like a pointer? Why or why not?

### Practical

1. Write a program with `int x = 100`, a pointer `p` to `x`, and a double pointer `pp` to `p`. Print the value using `x`, `*p`, and `**pp`.
2. Write a function `void allocate(int **ptr, int value)` that mallocs an int and sets its value. Call it from main and print the result.
3. Write a program that creates an array of 5 ints, then iterates using:
   - (a) index notation `arr[i]`
   - (b) pointer arithmetic `*(arr + i)`
   - (c) a separate pointer `p++`
4. What does this print?
   ```c
   int arr[] = {1, 2, 3};
   int *p = arr;
   p++;
   printf("%d %d\n", *p, *(p + 1));
   ```
5. Write a function that takes `int **matrix` (array of int pointers) and prints a 3x3 grid.

---

## Day 6 — Strings, Buffer Overflow & Safe I/O

### Theory

1. How is a string stored in C? What marks its end?
2. Why is `strcpy` dangerous? What can happen if the destination buffer is too small?
3. What is a buffer overflow and why is it critical in security/RE?
4. What is the difference between `fgets` and `scanf` for reading input?
5. What do `xxd`, `od`, and `hd` do? When would you use them?

### Practical

1. Write a program that reads a name with `fgets`, then prints it. Remove the trailing newline.
2. Deliberately cause a buffer overflow with `strcpy` (like your `str.c`). Compile with and without `-fstack-protector`. What happens differently?
3. Rewrite the overflow example safely using `strncpy`. Make sure you null-terminate.
4. Write a program that takes a string and prints each character's ASCII value in decimal and hex:
   ```
   N -> 78 (0x4e)
   j -> 106 (0x6a)
   ```
5. Write a program that reads a line of input, then use `xxd` on the binary to find your string in memory.

---

## Day 7 — Functions

### Theory

1. What is the difference between a function declaration (prototype) and a definition?
2. What does `void` mean as a return type? As a parameter?
3. In C, are arguments passed by value or by reference? How do you simulate pass-by-reference?
4. What is the call stack? What happens when a function is called (stack frame, return address)?
5. Why is understanding the call stack essential for reverse engineering?

### Practical

1. Write a function `int power(int base, int exp)` that calculates base^exp using a loop.
2. Write a recursive `int factorial(int n)` function.
3. Write a function that takes a `char *` string and returns its length (your own `strlen`).
4. Write a program with 3 functions. Compile it, then use `objdump -d` to disassemble it. Can you find your functions in the assembly?
5. Write a function pointer example: declare a function, store its address in a pointer, and call it through the pointer.

---

## Bonus — Cross-Day RE Challenges

1. Write a program, compile with `-g`, then run `gdb ./program`. Set a breakpoint on `main`, step through it, and inspect variable values.
2. Write a simple XOR cipher program, compile it **without** `-g`, then use `objdump -d` and `strings` to try to recover the key from the binary.
3. Write a program with a hidden password check. Give the binary (not source) to a friend — can they find the password using `strings`, `ltrace`, or `gdb`?
4. Compile any of your day programs and use `readelf -h` to examine the ELF header. What is the entry point address?
5. Use `strace` on one of your compiled programs. What system calls does a simple `printf("hello")` actually make?
