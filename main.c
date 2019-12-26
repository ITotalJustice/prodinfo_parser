#include <stdio.h>
#include <stdlib.h>
#include "prodinfo.h"
#include "util.h"


void app_start(void)
{
    printf("\n");
    printf("Welcome to the prodinfo parser!\n");
    printf("Select an option from below...\n\n\n");
}

void app_exit(void)
{
    printf("\n");
    printf("exiting...\n\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("not enough args!\n");
        return -1;
    }

    if (!is_file(argv[1]))
    {
        printf("%s is not a file... exiting!\n", argv[1]);
        return -1;
    }

    app_start();
    prodinfo_t *prodinfo = calloc(1, sizeof(prodinfo_t));
    read_prodinfo(prodinfo, argv[1]);
    
    display_device_id(prodinfo);

    free(prodinfo);
    app_exit();

    return 0;
}