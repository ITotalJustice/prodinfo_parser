#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


bool is_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return false;
    fclose(f);
    return true;
}

size_t read_file(void *out, size_t size, uint64_t offset, FILE *f)
{
    fseek(f, offset, SEEK_SET);
    return fread(out, size, 1, f);
}

void dump(const void *dump, size_t size, const char *file_out)
{
    FILE *f = fopen(file_out, "wb");
    fwrite(dump, size, 1, f);
    fclose(f);
}