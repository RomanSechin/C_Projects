#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
    DIR * folder;
    folder = opendir("C:\\Program Files");
    if(folder == NULL)
    {
        printf("Can't open directory\n");
        exit(1);
    }

    if(closedir(folder) != 0)
    {
        printf("Can't close directory\n");
        exit(2);
    }

    //system("pause");
    return 0;
}
