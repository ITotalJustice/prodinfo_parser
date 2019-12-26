#ifndef _PRODINFO_H_
#define _PRODINFO_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define CAL0_MAGIC          0x304C4143  // CAL0

#define DEVICE_ID_MAGIC     0x4E58      // NX.
#define DEVICE_ID_SIZE      0x10        // size of deviceID.


typedef enum
{
    ProductModel_NX = 0x1,
    ProductModel_Copper = 0x2
} ProductModel;

typedef struct
{
    uint16_t nx;                    // NX.
    uint8_t id[DEVICE_ID_SIZE];     // device ID.
    uint8_t end[0x2];               // -0.
} device_id_t;

typedef struct
{
    uint8_t _0x0[0x40];             // unkown.
    uint8_t _0x40[0x40];            // empty.
    uint8_t n_nxca1_prod1[0x12];    // NintendoNXCA1Prod1.
    uint8_t _0x92[0x30];            // empty.
    uint16_t _0xC2;                 // always 2.
    device_id_t device;             // device_id;
    uint8_t _0xD8[0x2C];            // empty.
    uint8_t _0x104[0x40];           // unkown.
    uint8_t _0x144[0x3C];           // unkown.
} eec_b233_device_cert_t;

typedef struct
{
    uint32_t magic;
    uint32_t version;
    uint32_t body_size;
    uint16_t model;
    uint16_t upper_count;
    uint8_t _0x10[0x10];
    uint8_t body_hash[0x20];
    uint8_t config_ld1[0x1E];
    uint8_t _0x005E[0x22];

    uint32_t wlan_country_codes_num;
    uint32_t wlan_country_codes_last_index;
    uint8_t wlan_country_codes[0x180];
    uint8_t _0x0208[0x8];
    uint8_t wlan_mac_address[0x06];
    uint8_t _0x0216[0xA];

    uint8_t bd_address[0x6];
    uint8_t _0x0226[0xA];

    uint8_t accelerometer_offset[0x06];
    uint8_t _0x0236[0x2];
    uint8_t accelerometer_scale[0x06];
    uint8_t _0x023E[0x2];
    uint8_t gyroscope_offset[0x06];
    uint8_t _0x0246[0x2];
    uint8_t gyroscope_scale[0x06];
    uint8_t _0x024E[0x2];

    uint8_t serial_num[0x18];
    uint8_t _0x0268[0x8];

    uint8_t EccP256DeviceKey[0x30];
    uint8_t _0x02A0[0x10];
    uint8_t EccP256DeviceCertificate[0x180];
    uint8_t _0x0430[0x10];
    uint8_t EccB233DeviceKey[0x30];
    uint8_t _0x0470[0x10];
    eec_b233_device_cert_t eec_b233_device_cert;
    uint8_t _0x0600[0x10];
    uint8_t EccP256ETicketKey[0x30];
    uint8_t _0x0640[0x10];
    uint8_t EccP256ETicketCertificate[0x180];
    uint8_t _0x07D0[0x10];
    uint8_t EccB233ETicketKey[0x30];
    uint8_t _0x0810[0x10];
    uint8_t EccB233ETicketCertificate[0x180];
    uint8_t _0x09A0[0x10];

    uint8_t ssl_key[0x110];
    uint8_t _0x0AC0[0x10];
    uint32_t ssl_cert_size;
    uint8_t _0x04AD4[0xC];
    uint8_t ssl_cert[0x800];
    uint8_t ssl_cert_hash[0x20];

    uint8_t random_num[0x1000];
    uint8_t random_num_hash[0x20];

    uint8_t gamecard_key[0x110];
    uint8_t _0x2430[0x10];
    uint8_t gamecard_cert[0x400];
    uint8_t gamecard_cert_hash[0x20];

    uint8_t rsa_2048_etik_key[0x220];
    uint8_t _0x2A80[0x10];
    uint8_t rsa_2048_etik_cert[0x240];
    uint8_t _0x2CD0[0x10];

    uint8_t battery_lot[0x18];
    uint8_t _0x2CF8[0x8];
    uint8_t speaker_calibration_value[0x800];
    uint8_t _0x3500[0x10];
    uint32_t region_code;
    uint8_t _0x3514[0xC];

    uint8_t amiibo_key[0x50];
    uint8_t _0x3570[0x10];
    uint8_t amiibo_ecqv_cert[0x14];
    uint8_t _0x3594[0xC];
    uint8_t amiibo_ecdsa_cert[0x70];
    uint8_t _0x3610[0x10];
    uint8_t amiibo_ecqv_bls_key[0x40];
    uint8_t _0x3660[0x10];
    uint8_t amiibo_ecqv_bls_cert[0x20];
    uint8_t _0x3690[0x10];
    uint8_t amiibo_ecqv_bls_root_cert[0x90];
    uint8_t _0x3730[0x10];

    uint32_t product_model; // see ProductModel.
    uint8_t _0x3744[0xC];
    uint8_t home_menu_colour_variation[0x6];
    uint8_t _0x3756[0xA];
    uint8_t lcd_backlight_brightness_mapping[0xC];
    uint8_t _0x376C[0x4];
    
    uint8_t ExtendedEccB233DeviceKey[0x50];
    uint8_t _0x37C0[0x10];
    uint8_t ExtendedEccP256ETicketKey[0x50];
    uint8_t _0x3820[0x10];
    uint8_t ExtendedEccB233ETicketKey[0x50];
    uint8_t _0x3880[0x10];
    uint8_t extended_rsa_2048_etik_key[0x240];
    uint8_t _0x3AD0[0x10];
    uint8_t extended_ssl_key[0x130];
    uint8_t _0x3C10[0x10];
    uint8_t extended_gamecard_key[0x130];
    uint8_t _0x3D50[0x10];
    
    uint32_t lcd_vendor_id;
    uint8_t _0x3D64[0xC];
    
    uint8_t ExtendedRsa2048DeviceKey[0x240];
    uint8_t _0x3FB0[0x10];
    uint8_t Rsa2048DeviceCertificate[0x240];
    uint8_t _0x4200[0x10];

    uint8_t UsbTypeCPowerSourceCircuitVersion;
    uint8_t _0x4221[0xF];

    uint32_t HomeMenuSchemeSubColor;
    uint8_t _0x4224[0xC];
    uint32_t HomeMenuSchemeBezelColor;
    uint8_t _0x4234[0xC];
    uint32_t HomeMenuSchemeMainColor1;
    uint8_t _0x444[0xC];
    uint32_t HomeMenuSchemeMainColor2;
    uint8_t _0x454[0xC];
    uint32_t HomeMenuSchemeMainColor3;
    uint8_t _0x464[0xC];

    uint8_t AnalogStickModuleTypeL;
    uint8_t _0x4271[0xF];
    uint8_t AnalogStickModelParameterL[0x12];
    uint8_t _0x4292[0xE];
    uint8_t AnalogStickFactoryCalibrationL[0x9];
    uint8_t _0x42A9[0x7];
    uint8_t AnalogStickModuleTypeR;
    uint8_t _0x42B1[0xF];
    uint8_t AnalogStickModelParameterR[0x12];
    uint8_t _0x42D2[0xE];
    uint8_t AnalogStickFactoryCalibrationR[0x9];
    uint8_t _0x42E9[0x7];

    uint8_t ConsoleSixAxisSensorModuleType;
    uint8_t _0x42F0[0xF];
    uint8_t ConsoleSixAxisSensorHorizontalOffset[0x6];
    uint8_t _0x4306[0xA];

    uint8_t battery_version;
    uint8_t _0x4311[0x2F];
    uint32_t home_menu_scheme_model;
} prodinfo_t;


//
bool check_if_cal_magic_valid(uint32_t magic);

//
void read_prodinfo(prodinfo_t *prodinfo, const char *file);

//
void display_device_id(prodinfo_t *prodinfo);


//
void dump_extended_rsa_2048_etik_key(prodinfo_t *prodinfo);

//
void dump_extended_ssl_key(prodinfo_t *prodinfo);

//
void dump_extended_gamecard_key(prodinfo_t *prodinfo);

#endif