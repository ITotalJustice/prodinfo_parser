#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


bool is_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return false;
    fclose(f);
    return true;
}

size_t get_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);
    return size;
}

size_t read_file(void *out, size_t size, uint64_t offset, FILE *f)
{
    fseek(f, offset, SEEK_SET);
    return fread(out, size, 1, f);
}

void *read_entire_file(const char *file, size_t *size)
{
    if (!is_file(file)) return NULL;
    FILE *fp = fopen(file, "rb");
    *size = get_file_size(fp);
    void *buf = calloc(1, *size);
    fread(buf, 1, *size, fp);
    fclose(fp);
    return buf;
}

void dump(const void *dump, size_t size, const char *file_out)
{
    FILE *f = fopen(file_out, "wb");
    fwrite(dump, size, 1, f);
    fclose(f);
}