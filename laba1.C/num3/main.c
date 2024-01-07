#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int* printSubstringInclusions(char*, int, ...);

typedef enum Errors {
    SUCCESS = 0,
    ERROR = 1
} Errors;



int main(int argc, const char* argv[])
{
    int i, number_row, number_symbol, number_file, * values, * valuesPointer;

    values = printSubstringInclusions("", 1, "/Users/accessdenied/Documents/Учеба/Projects/ОВС/Лабораторные работы/Лабораторная работа 2/Ex3/Ex3.txt");
    valuesPointer = values;
    if (values == NULL)
    {
        printf("Arguments invalid or file can not be open");
        return ERROR;
    }


    for (i = 1; *valuesPointer != 0; i++)
    {
        number_file = *valuesPointer++;
        number_row = *valuesPointer++;
        number_symbol = *valuesPointer++;
        printf("Count number %d in file %d: \trow %d, symbol %d\n", i, number_file, number_row, number_symbol);
    }


    if (values != NULL) free(values);
    return SUCCESS;
}

int* printSubstringInclusions(char* const str, int count, ...)
{
    int* values, * valuesPointer;
    va_list ap;
    FILE* file = NULL;
    char ch, * strPointer = str;
    int
        i,
        findedIndex = -1,
        number_row = 1,
        number_symbolInRow = 0;

    if (count < 1) return NULL;

    values = calloc(BUFSIZ, sizeof(char));
    if (values == NULL) return NULL;
    valuesPointer = values;

    va_start(ap, count);
    for (i = 0; i < count; i++)
    {
        //считываем файл
        if (!(file = fopen(va_arg(ap, char*), "r")))
        {
            continue;
        }

        strPointer = str;
        findedIndex = -1;//found
        number_row = 1;
        number_symbolInRow = 0;

        while ((ch = fgetc(file)) != EOF)
        {
            //Обновляем строку
            if (ch == '\n')
            {
                number_symbolInRow = 0;
                number_row++;

                findedIndex = -1;
                strPointer = str;

                continue;
            }
            number_symbolInRow++;



            //Ищем слово
            if (ch == *strPointer++)
            {
                if (findedIndex == -1) findedIndex = number_symbolInRow;
            }
            else
            {
                strPointer = str;
                findedIndex = -1;
            }



            //Найдено слово
            if (*strPointer == '\0')
            {
                *valuesPointer++ = (i + 1);
                *valuesPointer++ = number_row;
                *valuesPointer++ = findedIndex;

                strPointer = str;
                findedIndex = -1;
            }
        }

        fclose(file);
    }

    va_end(ap);
    return values;
}









/*#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

enum StatusCode {
    INCORRECTED_READ_FILE
};

enum StatusCode find_substring_in_files(const char* substring, int num_files, ...);

int main()
{
    enum StatusCode Status = find_substring_in_files("dom", 1, "test.lab1.txt");
    if (Status == INCORRECTED_READ_FILE) {
        printf("Incorrected Error: invalid read file");
        return 1;
    }
    return 0;
}

enum StatusCode find_substring_in_files(const char* substring, int num_files, ...)
{
    va_list files;
    va_start(files, num_files);

    for (int i = 0; i < num_files; i++) {
        const char* file_path = va_arg(files, const char*);

        FILE* file;
        if ((file = fopen(file_path, "r")) == NULL) {
            return INCORRECTED_READ_FILE;
        }

        // printf("Searching for \"%s\" in file: %s\n", substring, file_path);

        char line[256];
        int line_number = 1;

        while (fgets(line, sizeof(line), file)) {
            int line_length = strlen(line);
            int column_number = 1;
            int substring_length = strlen(substring);

            for (int j = 0; j <= line_length - substring_length; j++) {

                int match = 1;


                for (int k = 0; k < substring_length; k++) {

                    if (line[j + k] != substring[k]) {
                        match = 0;
                        break;
                    }
                }



                if (match) {
                    // printf("Found at line: %d, column: %d\n", line_number, column_number);
                }



                column_number++;
            }

            line_number++;
        }

        fclose(file);
    }

    va_end(files);
}*/