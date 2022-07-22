#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "compression_algorithm.h"

int compress_bytes(uint8_t *data_buffer, size_t data_size)
{
    /* Check if the pointer is valid */
    if(NULL == data_buffer)
    {
        return NULL_PTR_PROBLEM;
    }

    uint8_t new_buf_index = 0, index = 0, count = 0;
    uint8_t val = data_buffer[index];

    /* Loop until all data bytes are scanned */
    while (data_size--)
    {
        /* If data byte is repeating, increment the count*/
        if (val == data_buffer[index])
        {
            count++;
        }
        else  
        {
            /* Replace repeating bytes of data with count, data */
            if (count >= 2)
            {
                data_buffer[new_buf_index] = CONSECUTIVE_HASH | count;
                data_buffer[new_buf_index + 1] = val;
                new_buf_index += 2;
            }
            else  /* Store non repeating data as-is */
            {
                data_buffer[new_buf_index] = val;
                new_buf_index += 1;
            }

            /* If the repeatition is broken, slect the next data and re-initialize count */
            val = data_buffer[index];
            count = 1;
        }
        index++;
    }
    /* Take care of last iteration of repeating and non repeating data */
    if (count >= 2)
    {
        data_buffer[new_buf_index] = CONSECUTIVE_HASH | count;
        data_buffer[new_buf_index + 1] = val;
        new_buf_index += 2;
    }
    else
    {
        data_buffer[new_buf_index] = val;
        new_buf_index += 1;
    }
    /* The new size of the compressed data buffer */
    return new_buf_index;
}

int decompress_bytes(uint8_t *data_buffer, size_t data_size)
{
    /* Check if the pointer is valid */
    if(NULL == data_buffer)
    {
        return NULL_PTR_PROBLEM;
    }

    uint8_t index = 0, val = 0, new_buf_index = 0;

    /* Size is considered double to have enough space */
    uint8_t new_data_ptr[2*data_size];

    /* Loop until all data bytes are scanned */
    while (index <= data_size-1)
    {
        val = data_buffer[index];
        
        /* Check whether the value is a data or count byte */
        if(val > MAX_BYTE_VALUE)
        {
            /* Mask the MSB to get actual count */
            val = MAX_BYTE_VALUE & val;
            /* Reproduce the repeating bytes of data */
            memset(&new_data_ptr[new_buf_index], data_buffer[index+1], val);
            new_buf_index += val;
            index += 2;
        }
        else /* If the value is actual data, copy as-is */
        {
            new_data_ptr[new_buf_index] = data_buffer[index];
            new_buf_index++;
            index++;
        }   
    }
    /* Copy all the decompressed data into the data_buffer passed to function
       User must pass data_buffer with sufficient space for expanding the actual data
    */
    memcpy(data_buffer, new_data_ptr, new_buf_index);
    
    /* The new size of the decompressed data buffer*/
    return new_buf_index;
}
