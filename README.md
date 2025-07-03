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
Output Demo:
-----------------
![image](https://github.com/user-attachments/assets/bc8c5a63-f1e7-47f5-8345-43fd07ff88d8)
![image](https://github.com/user-attachments/assets/16ef5073-1aef-43cf-a50c-c9372873b93f)
![image](https://github.com/user-attachments/assets/7952b30f-6971-4db3-9bfd-56d64d1aa02c)
![image](https://github.com/user-attachments/assets/78f0f944-2f36-4824-a6f7-9a14731fbbb5)


## 📄 Features
- Generic types using `void*`
- Efficient `quicksort`, `lower_bound`, and `upper_bound`
- AVL tree implementation for maps and sets

