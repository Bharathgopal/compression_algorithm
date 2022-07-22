#include "compression_algorithm.h"

#if 0
uint8_t data_ptr[] = {0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 0x64, 0x64,
                      0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x45, 0x56, 0x56,
                      0x56, 0x09, 0x09, 0x09};
#else
uint8_t data_ptr[] = {0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 0x64, 0x64,
                      0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x45, 0x56, 0x57,
                      0x56, 0x09, 0x09, 0x10};
#endif
int main()
{
    printf("Actual data = \n");
    for (size_t i = 0; i < 24; i++)
    {
        printf("%02X ", data_ptr[i]);
    }
    
    int compress_size = compress_bytes(data_ptr, 24);

    printf("\nSize after compression = %d\n", compress_size);
    printf("compressed data = \n");
    for (size_t i = 0; i < compress_size; i++)
    {
        printf("%02X ", data_ptr[i]);
    }
    
    int decompress_size = decompress_bytes(data_ptr, compress_size);
    
    printf("\nSize after decompression = %d", decompress_size);
    printf("\nDecompressed data = \n");
    for (size_t i = 0; i < decompress_size; i++)
    {
        printf("%02X ", data_ptr[i]);
    }
    return 0;
}