#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


// opens the file.
// if it fails, it returns false.
// returns true (1) on success.
bool is_file(const char *path);

// seeks to the offset.
// reads into out until size.
size_t read_file(void *out, size_t size, uint64_t offset, FILE *f);

//
void *read_entire_file(const char *file, size_t *size);

// dump data to the file_out.
void dump(const void *dump, size_t size, const char *file_out);

#endif