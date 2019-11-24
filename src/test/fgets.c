#include <stdio.h>
#include <string.h>

char line[8192];

int main(int argc, char *argv[])
{
    FILE *file;
    const char *path = "etc/jobmanager.etc";

    file = fopen(path, "r");

    while(fgets(line, 8192, file)) {
        printf("%s", line);
    }

    return 0;
}