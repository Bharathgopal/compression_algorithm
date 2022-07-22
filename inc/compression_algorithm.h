#ifndef COMPRESSION_ALGORITHM_H_
#define COMPRESSION_ALGORITHM_H_
/**
 * @file compression_algorithm.h
 * @author Bharath G (Bharathgopal75@gmail.com)
 * @brief Algorithms for compression and decompression of byte data
 * The compression algorithms exploits below features of the data
 * a. The consecutive data elements are replaced by count byte and data byte
 * b. To differentiate between count and actual data, the MSB bit is utilised
 * c. MSB is always set in count byte, and unset in data byte
 * d. if the data is not repeating, the original byte is retained.
 * 
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdint.h"
#include <stdio.h>
#include <string.h>

#define CONSECUTIVE_HASH    (0x80)  /**< Byte to or with count */
#define MAX_BYTE_VALUE      (0x7F)  /**< Maximum data value allowed */
#define NULL_PTR_PROBLEM    (0x00)  /**< Return value if pointer is NULL in a function */
/**
 * @brief Function to compress bytes of data
 * 
 * @param[in] data_buffer Pointer to a data buffer containing data to be compressed
 * @param[in] data_size Size of the data in the input buffer
 * @return int Return 0 if the pointer is NULL or new size of the compressed data
 * 
 * @note If the data_buffer is NULL, the function returns 0
 * @note The data after compressed size is left unmodified in the data buffer and is invalid
 */
int compress_bytes(uint8_t *data_buffer, size_t data_size);

/**
 * @brief 
 * 
 * @param[in] data_buffer Pointer to a data buffer containing data to be compressed
 * @param[in] data_size Size of the data in the input buffer
 * @return int Return 0 if the pointer is NULL or new size of the decompressed data
 * 
 * @note If the data_buffer is NULL, the function returns 0
 * @note The function assumes that the user takes care of passing data buffer which can hold 
 * the data after decompression. If not taken care the function might result in segmentation fault.
 */
int decompress_bytes(uint8_t *data_buffer, size_t data_size);

#endif