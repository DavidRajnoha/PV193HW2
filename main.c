#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Missing input validation
int main(int argc, char* argv[]) {

    char limited_array[8];
    int isAdmin = 0;
    strcpy(limited_array, argv[2]); // 2. Buffer overflow
    int undeclared_variable;

    char *heap_buffer = (char*) malloc(8 * sizeof(char));
    strcpy(heap_buffer, argv[1]); // 3. Heap overflow
    printf("Heap: %s", heap_buffer); // 4. String information disclosure
    printf(heap_buffer); // 5. Potential string format vulnerability
    if (!undeclared_variable) { // 6. Usage of undeclared variable
        heap_buffer = NULL; // 7. Memory leak
    } else {
        free(heap_buffer);
        printf("%s", heap_buffer); // 8. Use after free
    }
    signed char smallInt;
    for (smallInt = 125; smallInt < 130; smallInt++) { // 9. Type overflow
        printf("Value of smallInt: %d\n", (int)smallInt);
        if (smallInt == -120) break;
    }
    if (isAdmin) {
        printf("%d\n", *heap_buffer); // 10. Null pointer dereference
        char command[256];
        snprintf(command, sizeof(command), "echo %s", argv[3]);
        system(command); // 11. Command injection

    } else {
        free(heap_buffer); // 12. Double free
    }

    return 0;
}
