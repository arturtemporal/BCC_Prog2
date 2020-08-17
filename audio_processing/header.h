#ifndef __HEADER__
#define __HEADER__

#define ERR_ARQ_NAO_ENCONTRADO 1
#define ERR_BAD_MALLOC 2
#define ERR_ARG_NAO_ENCONTRADO 3
#define ERR_LEITURA_DADOS 4
#define ERR_CRIACAO_ARQ 5
#define ERR_ESCRITA_ARQ 6

#include <inttypes.h>

typedef struct wav_header {
    // 
    char chunk_id[4];
    uint32_t chunk_size;
    char format[4];
    // formato
    char sub_chunk1_id[4];
    uint32_t sub_chunk1_size;
    uint16_t audio_format;
    uint16_t number_of_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    // "data"
    char sub_chunk2_id[4];
    uint32_t sub_chunk2_size;
} wav_header_t;

typedef struct file_data {
    float level;
    float time;
    char* input_file;
    char* output_file;
} file_data_t;

#endif