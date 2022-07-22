# Compression and Decompression
* Simple project to showcase compression and Decompression of Bytes of data

## The compression algorithms exploits below features of the data
* The project uses Run-length encoding compression algorithm and exploits the repeating values to perform compression.
* The data buffer has same value repeated in series
* The consecutive data elements are replaced by count byte and data byte
* To differentiate between count and actual data, the MSB bit is utilised
* MSB is always set in count byte, and unset in data byte
* if the data is not repeating, the original byte is retained.

### Status

|Build & Unit Test|Codacy|
|:--:|:--:|
|[![Build - Linux](https://github.com/Bharathgopal/compression_algorithm/actions/workflows/build.yml/badge.svg)](https://github.com/Bharathgopal/compression_algorithm/actions/workflows/build.yml)|[![Codacy Badge](https://app.codacy.com/project/badge/Grade/6667e022d69f4e4090e0a62ee2fa6b78)](https://www.codacy.com/gh/Bharathgopal/compression_algorithm/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Bharathgopal/compression_algorithm&amp;utm_campaign=Badge_Grade)|



## Build and run the Project
### Pre-requisites
* Makefile
* GCC 
* gcov for code coverage
* [Unity Throw the Switch](https://github.com/ThrowTheSwitch/Unity) source code files

#### Build and run
```
    make
    make run
```

#### Code coverage
```
    make coverage
```

#### Code size
```
    make codesize
```

#### Clean project
```
    make clean
```
## Limitations
* The algorithm uses the repeating data values to compress the data. However, if the data is not repeating, the compression is not effective. 
* To overcome this, any exisitng compression method with proven compression ratio can be leveraged. 
* Collection of availabel compression techniques is provided by [TurboBench:Compressor Benchmark](https://github.com/powturbo/TurboBench)

# References
* [Run-length Encoding](https://en.wikipedia.org/wiki/Run-length_encoding)
* [TurboBench:Compressor Benchmark](https://github.com/powturbo/TurboBench)
