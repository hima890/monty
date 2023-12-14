# Monty Project Readme

## Overview

The Monty project is an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes, similar to Python. The interpreter relies on a unique stack data structure with specific instructions to manipulate it. The project involves implementing various opcodes to perform stack operations.

## Data Structures

The project uses two main data structures, defined in the header file:

### `stack_t` - Doubly Linked List Representation of a Stack

```c
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
```

### `instruction_t` - Opcode and its Function

```c
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

The code is compiled using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

All output is printed on `stdout`, and any error messages are printed on `stderr`.

## Monty Language

Monty byte code files have the `.m` extension. Each file contains instructions, with one instruction per line. The interpreter executes the byte codes line by line and stops if an error occurs or when the entire file is executed.

## Usage

```
./monty file
```

- If no file or more than one argument is provided, it prints: `USAGE: monty file` and exits with `EXIT_FAILURE`.
- If it can't open the file, it prints: `Error: Can't open file <file>` and exits with `EXIT_FAILURE`.
- If an invalid instruction is encountered, it prints: `L<line_number>: unknown instruction <opcode>` and exits with `EXIT_FAILURE`.
- If `malloc` fails, it prints: `Error: malloc failed` and exits with `EXIT_FAILURE`.

## Tasks

### 0. push, pall

#### `push`

The `push` opcode pushes an element onto the stack. Usage: `push <int>`. If the argument is not an integer or not provided, it prints an error message.

#### `pall`

The `pall` opcode prints all values on the stack. If the stack is empty, it doesn't print anything.

### 1. pint

#### `pint`

The `pint` opcode prints the value at the top of the stack. If the stack is empty, it prints an error message.

### 2. pop

#### `pop`

The `pop` opcode removes the top element of the stack. If the stack is empty, it prints an error message.

### 3. swap

#### `swap`

The `swap` opcode swaps the top two elements of the stack. If the stack contains less than two elements, it prints an error message.

### 4. add

#### `add`

The `add` opcode adds the top two elements of the stack. If the stack contains less than two elements, it prints an error message.

### 5. nop

#### `nop`

The `nop` opcode does nothing.

### 6. sub (Advanced)

#### `sub`

The `sub` opcode subtracts the top element of the stack from the second top element. If the stack contains less than two elements, it prints an error message.

### 7. div (Advanced)

#### `div`

The `div` opcode divides the second top element of the stack by the top element. If the stack contains less than two elements or the top element is 0, it prints an error message.

### 8. mul (Advanced)

#### `mul`

The `mul` opcode multiplies the second top element of the stack with the top element. If the stack contains less than two elements, it prints an error message.

### 9. mod (Advanced)

#### `mod`

The `mod` opcode computes the remainder of the division of the second top element by the top element. If the stack contains less than two elements or the top element is 0, it prints an error message.

### 10. comments (Advanced)

Comments in Monty start with `#` and are ignored by the interpreter.

### 11. pchar (Advanced)

#### `pchar`

The `pchar` opcode prints the character at the top of the stack. If the value is not in the ASCII table or the stack is empty, it prints an error message.

### 12. pstr (Advanced)

#### `pstr`

The `pstr` opcode prints the string starting at the top of the stack. It stops when the stack is empty, the value is 0, or the value is not in the ASCII table.

### 13. rotl (Advanced)

#### `rotl`

The `rotl` opcode rotates the stack to the top. The top element becomes the last one, and the second top element becomes the first one.

### 14. rotr (Advanced)

#### `rotr`

The `rotr` opcode rotates the stack to the bottom. The last element becomes the top element.

### 15. stack, queue (Advanced)

#### `stack` and `queue`

The `stack` opcode sets the data format to a stack (LIFO), and `queue` sets it to a queue (FIFO). When switching modes, the top and front of the stack are adjusted accordingly.

### 16. Brainf*ck (Advanced)

A Brainf*ck script that prints "School" followed by a new line.

### 17. Add two digits (Advanced)

Reads two digits from stdin, adds them, and prints the result.

### 18. Multiplication (Advanced)

Reads two digits from stdin, multiplies them, and prints the result.

### 19. Multiplication Level Up (Advanced)

Reads two digits from stdin, multiplies them, and prints the result followed by a new line.
