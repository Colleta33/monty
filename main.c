#include "monty.h"

instruction_t instructions[] = {
    {"push", },
    {"pall", },
    {NULL, NULL}
};
/**
 *main - Entry point
 *@agv: argument count
 *@argv: argument vector
 *Return: exit status
 */
int main(int argc, char* argv[])
{
	const char* filename = argv[1];

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

      process_file(filename);

    return (EXIT_SUCCESS);
}
void free_stack(stack_t** stack)
{
    stack_t* current = *stack;
    while (current != NULL)
    {
        stack_t* temp = current;
        current = current->next;
        free(temp);
    }

    *stack = NULL;
}
void process_file(const char* filename)
{
       	unsigned int line_number = 0;
	char* opcode = strtok(line, " \t\n");
	char line[1024];
	 int found = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

      

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;

        
        if (opcode == NULL || opcode[0] == '#')
            continue;

        while 

        (int i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack_t, line_number);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            free_stack(&stack);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    free_stack(&stack);
    fclose(file);
}
