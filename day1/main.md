## Reference

- [GCC Doc reference](https://man7.org/linux/man-pages/man1/gcc.1.html)
- [Make file docs](https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/7/html/developer_guide/managing-more-code-make)

## **Core Concept: Compilation & Toolchain**

You learned how C code turns into a program:

1. Preprocessing
2. Compilation
3. Assembly
4. Linking

Key idea: building software is a **step-by-step pipeline**, not one action.

---

## **Compilers**

Worked with:

- GCC
- Clang

Basic pattern:

```bash
gcc main.c -o main
```

Important flags:

- `-Wall -Wextra` → catch mistakes early
- `-g` → debugging
- `-O2` → optimization

---

## **Makefile Basics**

You learned how to automate builds:

### Structure:

```make
target: dependencies
	command
```

### Example:

```make
main: main.c
	gcc main.c -o main
```

---

## **Key Make Concepts**

- **Targets** → what you build (`main`)
- **Dependencies** → what it depends on (`main.c`)
- **Rules** → how to build

---

## **Power Features**

- Variables:

```make
CC = gcc
CFLAGS = -Wall -Wextra -g
```

- Automatic variables:
  - `$@` → target
  - `$<` → first dependency

---

## **Mental Model**

- `make` = smart builder (only rebuilds when needed)
- Not the same as npm
- Focused on **file dependencies and compilation**

---

## **What You Can Do Now**

- Compile C programs correctly
- Use compiler flags confidently
- Write a working Makefile
- Understand how builds actually work

---

## **One-line takeaway**

> You moved from “running code” to understanding **how software is built under the hood**

---

That should cover the request.
