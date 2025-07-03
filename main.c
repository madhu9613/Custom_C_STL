#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "avl_map.h"
#include "avl_set.h"
#include "algorithms.h"

int int_cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void read_multiple_ints(Vector* v) {
    char buffer[256];
    printf("Enter numbers (space or comma separated), then press Enter:\n> ");
    getchar(); // flush newline
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;

    char* token = strtok(buffer, " ,\n");
    while (token) {
        int* val = malloc(sizeof(int));
        *val = atoi(token);
        vector_push_back(v, val);
        token = strtok(NULL, " ,\n");
    }
}

void vector_menu() {
    Vector* v = vector_create();
    int choice;
    while (1) {
        printf("\n--- Vector Menu ---\n");
        printf("1. Push Multiple\n");
        printf("2. Print Vector\n");
        printf("3. Sort Vector\n");
        printf("4. Lower Bound\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            read_multiple_ints(v);
        }
        else if (choice == 2) {
            printf("Vector: ");
            for (size_t i = 0; i < v->size; i++)
                printf("%d ", *(int*)vector_at(v, i));
            printf("\n");
        }
        else if (choice == 3) {
            quicksort(v->data, 0, v->size - 1, int_cmp);
            printf("Vector sorted.\n");
        }
        else if (choice == 4) {
            int x;
            printf("Enter value to search lower_bound: ");
            scanf("%d", &x);
            void** lb = lower_bound(v->data, v->data + v->size, &x, int_cmp);
            if (lb == v->data + v->size)
                printf("No element >= %d found.\n", x);
            else
                printf("Lower bound of %d: %d\n", x, *(int*)*lb);
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    for (size_t i = 0; i < v->size; i++)
        free(vector_at(v, i));
    vector_free(v);
}

void map_menu() {
    AVLMap* map = avl_map_create(int_cmp);
    int choice;
    char buffer[256];

    while (1) {
        printf("\n--- Map Menu ---\n");
        printf("1. Insert Multiple Key-Value Pairs (e.g. 1:100 2:200)\n");
        printf("2. Get Value by Key\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key:value pairs (space or comma separated):\n> ");
            getchar();
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            char* token = strtok(buffer, " ,\n");
            while (token) {
                int* key = malloc(sizeof(int));
                int* val = malloc(sizeof(int));
                sscanf(token, "%d:%d", key, val);
                avl_map_insert(map, key, val);
                token = strtok(NULL, " ,\n");
            }
        }
        else if (choice == 2) {
            int x;
            printf("Enter key: ");
            scanf("%d", &x);
            void* result = avl_map_get(map, &x);
            if (result)
                printf("Map[%d] = %d\n", x, *(int*)result);
            else
                printf("Key not found.\n");
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    // Freeing skipped for brevity (could be implemented with AVL traversal)
    free(map);
}

void set_menu() {
    AVLSet* set = avl_set_create(int_cmp);
    int choice;
    char buffer[256];

    while (1) {
        printf("\n--- Set Menu ---\n");
        printf("1. Insert Multiple Elements\n");
        printf("2. Check if Element Exists\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter values (space or comma separated):\n> ");
            getchar();
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            char* token = strtok(buffer, " ,\n");
            while (token) {
                int* val = malloc(sizeof(int));
                *val = atoi(token);
                avl_set_insert(set, val);
                token = strtok(NULL, " ,\n");
            }
        }
        else if (choice == 2) {
            int x;
            printf("Enter value to check: ");
            scanf("%d", &x);
            printf("Set contains %d? %s\n", x, avl_set_contains(set, &x) ? "Yes" : "No");
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    free(set);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Vector Operations\n");
        printf("2. Map Operations\n");
        printf("3. Set Operations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            vector_menu();
        else if (choice == 2)
            map_menu();
        else if (choice == 3)
            set_menu();
        else if (choice == 4)
            break;
        else
            printf("Invalid choice!\n");
    }

    printf("Exiting program.\n");
    return 0;
}
