#include <stdio.h>
#include <string.h>
#include <assert.h>

void copy_first_line(const char* src_path, const char* dest_path) {
    char buffer[100];

    FILE* p_src = fopen(src_path, "r");
    FILE* p_dest = fopen(dest_path, "w");

    // Pro tip: Use "&&"" to connect a string literal with the condition
    // The string literal is always true so it won't alter the condition
    // however it will be also printed out when assert failes
    assert(p_src != NULL && "Could not open source file.");
    assert(p_dest != NULL && "Could not create target file.");


    if (fgets(buffer, sizeof(buffer), p_src) != NULL) {

        int result = fputs(buffer, p_dest);

        assert(result != EOF && "Fehler beim Schreiben mit fputs!");
    }

    fclose(p_src);
    fclose(p_dest);
}

int main() {

    FILE* pFile = fopen("input.txt", "w");
    if (pFile == NULL) {
        return 1;
    }
    if (fputs("HelloWorld!\nSecond Line.", pFile) < 0) {
        printf("Error");
        fclose(pFile);
        return 1;
    }
    fclose(pFile);

    copy_first_line("input.txt", "output.txt");

    //  Unit-Test with assert
    FILE* check = fopen("output.txt", "r");
    assert(check != NULL);

    char result[100];
    if (fgets(result, sizeof(result), check) != NULL) {
        // Verify if content is correct
        assert(strcmp(result, "HelloWorld!\n") == 0 && "Content is not correct!");
    }
    else {
        assert(0 && "Target file is empty");
    }

    fclose(check);
    printf("Program successful! All asserts were TRUE.\n");

    return 0;
}