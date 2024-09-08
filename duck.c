#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <category> <message>\n", argv[0]);
        return 1;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char filename[100];
    sprintf(filename, "%d-%02d-%02d-%02d-%02d.md", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

    FILE *file = fopen(filename, "w");
    filename[strlen(filename) - 3] = '\0';
    char title[100];
    sprintf(title, "%s", filename);
    title[13] = ':';
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    char template[] = "---\ntitle: %s\ncategory: %s\n---\n\n";
    fprintf(file, template, title, argv[1]);

    for(int i = 2; i < argc; i++) {
        fprintf(file, "%s ", argv[i]);
    }
    fclose(file);

    char command[500];
    //move the file to the _posts folder
    sprintf(command, "mv %s.md _posts/%s.md", filename, filename);
    system(command);

    system("git add .");
    system("git commit -m 'talking to duck'");
    system("git push");

    return 0;
}
