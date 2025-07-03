# Advanced STL-like C Library

This project mimics parts of C++ STL in the C programming language using:
- **Vector**: A generic resizable array.
- **AVLMap**: A self-balancing binary search tree for key-value pairs.
- **AVLSet**: A set data structure using AVL tree (via map).
- **Algorithms**: Sorting, lower/upper bound algorithms.

## 🗂️ Project Structure
```
advanced_stl_c/
├── include/       # Header files
├── src/           # Implementation files
├── main.c         # Demo usage
├── Makefile       # Build system
└── README.md
```

## 🛠️ How to Build
```bash
make 
---
or (if it doesnot work you can use)

 gcc -Iinclude main.c src/*.c -o main
##short notes on it 
| Part        | Meaning                                                                                      |
| ----------- | -------------------------------------------------------------------------------------------- |
| `gcc`       | GNU C Compiler — compiles your `.c` files                                                    |
| `-Iinclude` | Tells the compiler to look for header files (`#include "..."`) inside the `include/` folder. |
| `main.c`    | The entry point — your `main()` function is here.                                            |
| `src/*.c`   | Compiles all `.c` source files in the `src/` directory (like vector.c, avl\_map.c etc.)      |
| `-o main`   | Output binary file will be named `main` (instead of `a.out`)                                 |

./main
```

## 📄 Features
- Generic types using `void*`
- Efficient `quicksort`, `lower_bound`, and `upper_bound`
- AVL tree implementation for maps and sets

