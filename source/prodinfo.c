#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "prodinfo.h"
#include "util.h"



bool check_if_cal_magic_valid(uint32_t magic)
{
    if (magic == CAL0_MAGIC) return true;
    printf("Incorrect magic! Got 0x%X wanted 0x%X\n", magic, CAL0_MAGIC);
    return false;
}

prodinfo_t * read_prodinfo(const char *file)
{
    prodinfo_t *prodinfo = calloc(1, sizeof(prodinfo_t));
    FILE *f = fopen(file, "rb");
    read_file(prodinfo, sizeof(prodinfo_t), 0, f);
    fclose(f);
    return prodinfo;
}



/*
*   Display.
*/

void display_magic(prodinfo_t *prodinfo)
{
    printf("Magic:\t0x%X\n", prodinfo->magic);
}

void display_version(prodinfo_t *prodinfo)
{
    printf("Prodinfo Version:\t%u\n", prodinfo->version);
}

void display_model(prodinfo_t *prodinfo)
{
    printf("Prodinfo Model:\t%u\n", prodinfo->model);
}

void display_update_count(prodinfo_t *prodinfo)
{
    printf("Update Count:\t%u\n", prodinfo->upper_count);
}

void display_configuration_id(prodinfo_t *prodinfo)
{
    printf("Configuration ID:\t");
    for (uint8_t i = 0; i < 0x1E; i++)
        printf("%c", prodinfo->config_ld1[i]);
    printf("\n");
}

void display_bd_address(prodinfo_t *prodinfo)
{
    printf("BD Address:\t%u\n", *prodinfo->bd_address);
}

void display_wlan_mac_address(prodinfo_t *prodinfo)
{}

void display_device_id(prodinfo_t *prodinfo)
{
    printf("Device ID:\t");
    for (uint8_t i = 0; i < DEVICE_ID_SIZE; i++)
        printf("%c", prodinfo->ecc_b233_device_cert.device.id[i]);
    printf("\n");
}

void display_battery_lot(prodinfo_t *prodinfo)
{
    printf("Battery Lot:\t");
    for (uint8_t i = 0; i < 0x18; i++)
        printf("%c", prodinfo->battery_lot[i]);
    printf("\n");
}

void display_region_code(prodinfo_t *prodinfo)
{
    printf("Region Code: %u\n", prodinfo->region_code);
}

void display_product_model(prodinfo_t *prodinfo)
{
    printf("Product Model: %s\n", prodinfo->product_model == ProductModel_NX ? "NX" : "Copper");
}

void display_lcd_vendor_id(prodinfo_t *prodinfo)
{}

void display_all(prodinfo_t *prodinfo)
{
    display_magic(prodinfo);
    display_version(prodinfo);
    display_model(prodinfo);
    display_update_count(prodinfo);
    display_configuration_id(prodinfo);
    display_bd_address(prodinfo);
    display_wlan_mac_address(prodinfo);
    display_device_id(prodinfo);
    display_battery_lot(prodinfo);
    display_region_code(prodinfo);
    display_product_model(prodinfo);
    display_lcd_vendor_id(prodinfo);
}



/*
*   Dump.
*/

void dump_body_hash()
{}

void dump_wlan_country_codes_num()
{}

void dump_wlan_country_codes_last_index()
{}

void dump_wlan_country_codes()
{}

void dump_wlan_mac_address()
{}

void dump_bd_address()
{}

void dump_accelerometer_scale()
{}

void dump_gyroscope_scale()
{}

void dump_serial_num(prodinfo_t *prodinfo)
{
    dump(prodinfo->serial_num, 0x18, "serial_number");
}

void dump_ecc_p256_device_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_p256_device_key, 0x30, "ecc_p256_device_key");
}

void dump_ecc_p256_device_cert(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_p256_device_cert, 0x180, "ecc_p256_device_cert");
}

void dump_ecc_b233_device_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_b233_device_key, 0x30, "ecc_b233_device_key");
}

void dump_ecc_b233_device_cert(prodinfo_t *prodinfo)
{
    dump(&prodinfo->ecc_b233_device_cert, 0x180, "eec_b233_device_cert");
}

void dump_ecc_p256_etik_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_p256_etik_key, 0x30, "ecc_p256_etik_key");
}

void dump_ecc_p256_etik_cert(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_p256_etik_cert, 0x180, "ecc_p256_etik_key");
}

void dump_ecc_b233_etik_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_b233_etik_key, 0x30, "ecc_b233_etik_key");
}

void dump_ecc_b233_etik_cert(prodinfo_t *prodinfo)
{
    dump(prodinfo->ecc_b233_etik_cert, 0x180, "ecc_b233_etik_cert");
}

void dump_ssl_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->ssl_key, 0x130, "ssl_key");
}

void dump_ssl_cert(prodinfo_t *prodinfo)
{
    dump(&prodinfo->ssl_cert, prodinfo->ssl_cert_size, "ssl_cert");
}

void dump_ssl_cert_hash()
{}

void dump_random_num()
{}

void dump_random_num_hash()
{}

void dump_gamecard_key(prodinfo_t *prodinfo)
{}

void dump_gamecard_cert(prodinfo_t *prodinfo)
{}

void dump_gamecard_cert_hash()
{}

void dump_rsa_2048_etik_key(prodinfo_t *prodinfo)
{}

void dump_rsa_2048_etik_cert(prodinfo_t *prodinfo)
{}

void dump_battery_lot()
{}

void dump_speaker_calibration_value()
{}

void dump_region_code()
{}

void dump_amiibo_key()
{}

void dump_product_model()
{}

void dump_extended_ecc_b233_device_keyy(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_ecc_b233_device_key, 0x50, "extended_ecc_b233_device_key");
}

void dump_extended_ecc_p256_etik_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_ecc_p256_etik_key, 0x50, "extended_ecc_p256_etik_key");
}

void dump_extended_ecc_b233_etik_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_ecc_b233_etik_key, 0x50, "extended_ecc_b233_etik_key");
}

void dump_extended_rsa_2048_etik_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_rsa_2048_etik_key, 0x240, "extended_rsa_2048_etik_key");
}

void dump_extended_ssl_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_ssl_key, 0x130, "extended_ssl_key");
}

void dump_extended_gamecard_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_gamecard_key, 0x130, "extended_gamecard_key");
}

void dump_extended_rsa_2048_device_key(prodinfo_t *prodinfo)
{
    dump(prodinfo->extended_rsa_2048_device_key, 0x240, "extended_rsa_2048_device_key");
}

void dump_rsa_2048_device_cert(prodinfo_t *prodinfo)
{
    dump(prodinfo->rsa_2048_device_cert, 0x240, "rsa_2048_device_cert");
}


/*
*   Replace.
*/

void replace_ssl_cert(prodinfo_t *prodinfo)
{
    
}

void replace_extended_ssl_key(prodinfo_t *prodinfo)
{}

/*void replace_ssl_key(prodinfo_t *prodinfo)
{}

void replace_ssl_key(prodinfo_t *prodinfo)
{}
*/