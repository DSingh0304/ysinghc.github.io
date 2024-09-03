#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//import a library to execute os commands
#include <unistd.h>


int main(int argc, char *argv[]) {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char filename[100];
    sprintf(filename, "%02d-%02d-%d-%02d-%02d.md", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    char template[] = "---\ntitle: %s\ncategories: General\n---\n\n";
    fprintf(file, template, filename);

    for(int i = 1; i < argc; i++) {
        fprintf(file, "%s ", argv[i]);
    }
    fclose(file);

    char command[500];
    sprintf(command, "mv %s ../_posts/%s", filename, filename);
    system(command);

    system("git add .");
    system("git commit -m 'talking to duck'");
    system("git push");

    return 0;
}