# Projects — Based on Day 1 to Day 7

---

## Beginner Projects (Day 1–3 skills)

### 1. Binary Converter Tool

- Takes a decimal number as input, prints it in binary, hex, and octal
- Use bitwise shifts and masks (day 3)
- Bonus: accept input in any base and convert to others

### 2. Bitwise Flag System

- Simulate Linux file permissions (rwx) using bitwise operators
- Functions: `set_permission()`, `remove_permission()`, `check_permission()`
- Print permissions like `rwx r-x --x`
- Teaches how flags work in real binaries

### 3. Data Type Inspector

- Takes any value, shows how it's stored in memory byte by byte
- Use `unsigned char *` to walk through raw bytes
- Print hex dump of int, float, double, pointer
- Introduces you to how `xxd` works internally

---

## Intermediate Projects (Day 4–7 skills)

### 4. Custom `strings` Command

- Read a binary file byte by byte using `fopen`/`fread`
- Extract and print all printable ASCII sequences longer than 4 characters
- This is literally what `strings` does — now you know how it works
- Uses: pointers, arrays, file I/O, char checks

### 5. XOR Encryptor/Decryptor

- Encrypt a file with a multi-byte XOR key
- Write encrypted output to a new file
- Decrypt it back with the same key
- Uses: bitwise XOR, file I/O, pointers, `fgets`
- Real RE skill — XOR is the most common obfuscation in malware

### 6. Simple Memory Scanner

- Write a program with a "secret" variable
- Write a second program that reads `/proc/<pid>/maps` and `/proc/<pid>/mem` to find the value in memory
- Uses: pointers, file I/O, hex, data types
- Intro to how tools like `scanmem`/GameConqueror work

---

## Advanced Projects (Combines everything + RE)

### 7. ELF Header Parser

- Read a compiled ELF binary with `fopen`
- Parse and print the ELF header manually using structs and pointers:
  - Magic bytes, architecture, entry point, section headers
- Compare your output with `readelf -h`
- This is your first real reverse engineering project

### 8. Simple Disassembler (x86)

- Read the `.text` section of an ELF binary
- Decode basic x86 instructions: `mov`, `push`, `pop`, `call`, `ret`, `nop`
- Print address + opcode + mnemonic like `objdump` does
- Huge learning experience — connects C to assembly

### 9. Password Crackme Series

- Write 3 increasingly harder "crackme" binaries:
  - Level 1: plain `strcmp` against hardcoded password
  - Level 2: XOR-obfuscated password comparison
  - Level 3: custom hash check (simple sum/xor of characters)
- Then crack your own binaries using `gdb`, `ltrace`, `strings`, `objdump`
- The classic RE learning exercise

### 10. Function Call Tracer

- Write a program that uses `__attribute__((instrument_function))` GCC hooks
- Log every function entry/exit with address and timestamp
- Resolve function names using your own symbol table parser
- Produces output similar to `ltrace`/`ftrace`
