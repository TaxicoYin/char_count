#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *path[100];
    if (argc == 1)
    {
        printf("file path:\n");
        scanf("%s", &path);
    }
    else if (argc == 2)
    {
        strcpy(path, argv[1]);
    }
    else
    {
        printf("parameter error!");
        return -1;
    }
    printf("opened file path:%s\n", path);
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("open file error\n");
        return -1;
    }
    char line[512] = {0};
    int count[36] = {0};
    while (fgets(line, sizeof(line), file))
    {
        // printf("%s\n", line);
        for (int i = 0; i < (sizeof(line) / sizeof(char)); i++)
        {
            char c = line[i];

            if (c >= 'A' && c <= 'Z')
            {
                count[c - 'A']++;
            }
            else if (c >= '0' && c <= '9')
            {
                count[c - 22]++;
            }
        }
    }
    printf("character:times of showing up\n");
    for (int i = 0; i < 36; i++)
    {
        if (i < 26)
        {
            printf("%c:%d\n", i + 'A', count[i]);
        }
        else
        {
            printf("%c:%d\n", i + 22, count[i]);
        }
    }
    fclose(file);

    return 0;
}
