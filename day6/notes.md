## Day 6: Strings & Buffer Basics

## Core Concept

In C, a string is just an array of characters ending with a null terminator `'\0'`.

Example:

```c
char name[] = "John";
```

This is stored in memory as:

```c
'J' 'o' 'h' 'n' '\0'
```

That final `'\0'` tells C where the string ends.

---

## `char[]`

The normal way to store a mutable string in C is with a character array.

```c
char word[] = "cat";
```

This creates:

- `c`
- `a`
- `t`
- `'\0'`

Example:

```c
#include <stdio.h>

int main() {
    char word[] = "cat";
    printf("%s\n", word);
    return 0;
}
```

Important idea:

- Strings need space for the null terminator

So:

```c
char str[6] = "hello";
```

is correct because `"hello"` needs 5 characters plus `'\0'`.

---

## `strcpy`

`strcpy(dest, src)` copies one string into another.

Example:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "hello";
    char dest[10];

    strcpy(dest, src);
    printf("%s\n", dest);
    return 0;
}
```

This works because `dest` is large enough.

Danger:

```c
char dest[4];
strcpy(dest, "hello");
```

This is dangerous because `"hello"` needs 6 bytes including `'\0'`, but `dest` only has 4 bytes.

That causes a buffer overflow.

Why `strcpy` is dangerous:

- it does not check destination size
- it can write past the end of the buffer
- it can corrupt memory

---

## `gets`

`gets` reads input into a buffer, but it does not know the size of that buffer.

Old style example:

```c
char name[20];
gets(name);
```

This is dangerous because if the user types more than 19 characters, `gets` keeps writing past the end.

Why `gets` is dangerous:

- no length limit
- easy to overflow the buffer
- unsafe by design

Because of this, `gets` should never be used.

---

## Safer Alternative: `fgets`

Use `fgets` for input instead.

```c
#include <stdio.h>

int main() {
    char name[20];

    fgets(name, sizeof(name), stdin);
    printf("%s", name);
    return 0;
}
```

Why `fgets` is safer:

- it knows the buffer size
- it reads only up to the limit
- it leaves room for `'\0'`

One detail:

- `fgets` may keep the newline character `'\n'`

---

## Why This Matters

A lot of classic C bugs and security vulnerabilities come from unsafe string handling.

Common causes:

- copying too much data into a small buffer
- reading unchecked input into a fixed-size array
- forgetting that strings need `'\0'`

This is one of the foundations of buffer overflow bugs.

---

## Summary

- A C string is a `char` array ending with `'\0'`
- `char[]` is used to store mutable strings
- `strcpy` copies strings without checking size
- `gets` is dangerous and should never be used
- `fgets` is the safer choice for reading input

---

## One-line takeaway

> In C, strings are just character buffers, so if you do not control the size carefully, you can easily corrupt memory.

## `fgets` in C

`fgets` is a standard library function used to **read a line of text** from a file or standard input (keyboard). It's safer than `gets` because it limits how many characters are read.

### Syntax

```c
char *fgets(char *str, int n, FILE *stream);
```

**Parameters:**

- `str` — the buffer (char array) where the input is stored
- `n` — maximum number of characters to read (including the null terminator `\0`)
- `stream` — the input source: `stdin` for keyboard, or a `FILE *` for files

**Return value:** returns `str` on success, or `NULL` on error or end-of-file.

---

### Basic Example — Reading from Keyboard

```c
#include <stdio.h>

int main() {
    char name[50];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Hello, %s", name);  // fgets keeps the '\n', so no need for \n here
    return 0;
}
```

**Output:**

```
Enter your name: Alice
Hello, Alice
```

---

### Key Behaviors to Know

**1. It keeps the newline character `\n`**
When the user presses Enter, `fgets` stores the `\n` in the buffer. You often need to strip it:

```c
#include <string.h>

name[strcspn(name, "\n")] = '\0';  // removes the trailing newline
```

**2. It won't overflow your buffer**
It reads at most `n - 1` characters, always adding a `\0` at the end. This is what makes it safer than `gets`.

**3. It stops at a newline or EOF**
Even if `n` is large, reading stops when a `\n` is encountered.

---

### Reading from a File

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    char line[100];

    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  // print each line
    }

    fclose(fp);
    return 0;
}
```

This is a classic pattern for reading a file **line by line**.

---

### `fgets` vs `gets` vs `scanf`

| Feature              | `gets` | `scanf("%s")` | `fgets` |
| -------------------- | ------ | ------------- | ------- |
| Buffer overflow safe | ❌ No  | ❌ No         | ✅ Yes  |
| Reads spaces         | ✅ Yes | ❌ No         | ✅ Yes  |
| Keeps newline `\n`   | ❌ No  | ❌ No         | ✅ Yes  |
| Works with files     | ❌ No  | ❌ No         | ✅ Yes  |

> `gets` is so dangerous it was **removed from the C11 standard**. Always prefer `fgets`.

---

### Common Pitfalls

- **Forgetting to strip `\n`** — can cause string comparison bugs
- **Buffer too small** — if input is longer than `n-1`, the rest stays in the buffer for the next read
- **Not checking for `NULL`** — always check the return value, especially with files

---

Want me to go deeper on any part — like handling long inputs, file reading patterns, or comparing with `getline`?
