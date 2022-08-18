#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char menu(void)
{
    printf("\n\nPlease select a mode:\n\n");
    printf("1.) Merger (merge prodinfo's)\n\n");

    char c = 0;
    do
    {
        c = getchar();
    } while (c != '1');

    return c;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("not enough args!\n");
        return -1;
    }

    if (!is_file(argv[1]) || !is_file(argv[2]))
    {
        printf("%s or %s is not a file... exiting!\n", argv[1], argv[2]);
        return -1;
    }

    //app_start();
    prodinfo_t *prodinfo = read_prodinfo(argv[1]);
    prodinfo_t *prodinfo2 = read_prodinfo(argv[2]);
    
    display_all(prodinfo);
    printf("\n");
    display_all(prodinfo2);

    //memcpy(&prodinfo->ssl_cert, &prodinfo2->ssl_cert, sizeof(ssl_cert_t));
    //memcpy(prodinfo->extended_ssl_key, prodinfo2->extended_ssl_key, 304);
    //memcpy(prodinfo->ssl_cert_hash, prodinfo2->ssl_cert_hash, 0x20);
    //memcpy(prodinfo->_0x3C10, prodinfo2->_0x3C10, 0x10);
    //ssl_cert_hash _0x3C10
    //memcpy(&prodinfo->ecc_b233_device_cert, &prodinfo2->ecc_b233_device_cert, sizeof(ecc_b233_device_cert_t));
    //memcpy(prodinfo->extended_ecc_b233_device_key, prodinfo2->extended_ecc_b233_device_key, 0x50);
    //memcpy(prodinfo->extended_rsa_2048_etik_key, prodinfo2->extended_rsa_2048_etik_key, 0x240);
    //memcpy(prodinfo->extended_rsa_2048_device_key, prodinfo2->extended_rsa_2048_device_key, 0x240);
    //memcpy(prodinfo->rsa_2048_device_cert, prodinfo2->rsa_2048_device_cert, 0x240);

    size_t size = 0;
    void *ptr = memcpy(read_entire_file(argv[1], &size), prodinfo, sizeof(prodinfo_t));
    dump(ptr, size, "new_prodinfo.bin");

    free(prodinfo);
    free(prodinfo2);
    free(ptr);
    app_exit();

    return 0;
}