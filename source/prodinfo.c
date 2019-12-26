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

void read_prodinfo(prodinfo_t *prodinfo, const char *file)
{
    FILE *f = fopen(file, "rb");
    read_file(prodinfo, sizeof(prodinfo_t), 0, f);
    fclose(f);
}

void display_device_id(prodinfo_t *prodinfo)
{
    printf("Device ID:\t");
    for (uint8_t i = 0; i < DEVICE_ID_SIZE; i++)
        printf("%c", prodinfo->eec_b233_device_cert.device.id[i]);
    printf("\n");
}

void dump_magic()
{}

void dump_version()
{}

void dump_model()
{}

void dump_update_count()
{}

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

void dump_serial_num()
{}

void dump_ecc_p256_device_key()
{}

void dump_ecc_p256_device_cert()
{}

void dump_ecc_b233_device_key()
{}

void dump_ecc_b233_device_cert()
{}

void dump_ecc_p256_etik_key()
{}

void dump_ecc_p256_etik_cert()
{}

void dump_ecc_b233_etik_key()
{}

void dump_ecc_b233_etik_cert()
{}

void dump_ssl_key()
{}

void dump_ssl_cert()
{}

void dump_ssl_cert_hash()
{}

void dump_random_num()
{}

void dump_random_num_hash()
{}

void dump_gamecard_key()
{}

void dump_gamecard_cert()
{}

void dump_gamecard_cert_hash()
{}

void dump_rsa_2048_etik_key()
{}

void dump_rsa_2048_etik_cert()
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