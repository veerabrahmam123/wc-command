#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

int main(int argc, char* argv[])
{

   
    int TotalWords = 0;
    int TotalLines = 0;
    int TotalBytes = 0;
    int i;
    char buffer[4096];
    FILE *fp;
    int result = 0;

    for (i = 1; i < argc; i++) {
        int Word_Count = 0;
        int Line_Count = 0;
        fp = fopen(argv[i], "r");

        if (fp != NULL) {
            while (!feof(fp)) {
                result = fread(buffer, 1, (sizeof buffer)-1, fp);
                for (int i=0; i < result; i++) {
                    if ((isspace(buffer[i]) && !isspace(buffer[i+1])) ||
                            (!isspace(buffer[i]) && (i+1) == result)) {
                        ++Word_Count;
                    }
                    if (buffer[i]== '\n') {
                        ++Line_Count;
                    }
                }
            }
            fclose(fp);

            printf("%d %5d %5d   %s \n", Line_Count, Word_Count, result, argv[i]);

            TotalWords += Word_Count;
            TotalLines += Line_Count;
            TotalBytes += result;
        }
        else
            printf("wc is  %s No such file or directory \n", argv[i]);
    }
    if (argc > 2) {
        printf("%8d %8d %8d total \n", TotalWords, TotalLines, TotalBytes);
    }

    return 0;
}
