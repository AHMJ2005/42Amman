#include <unistd.h>

int main(int c, char **v)
{
    int i = 0;

    if (c < 2)
    {
        write(1, "\n", 1);
        return 0;
    }

    while (v[1][i] != '\0')
    {
        
        while (v[1][i] == ' ' || v[1][i] == '\t')
            i++;

        
        if (v[1][i] == '\0')
            break;

        
        while (v[1][i] != '\0' && v[1][i] != ' ' && v[1][i] != '\t')
        {
            write(1, &v[1][i], 1);
            i++;
        }
        if (v[1][i] != '\0')
            write(1, " ", 1);
    }
    write(1, "\n", 1); 
    return 0;
}
