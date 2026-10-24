#include "Utils.h"
#include <cstring>

char *my_strdup(const char *src)
{
    if (!src)
        return nullptr;
    char *dest = new char[strlen(src) + 1];
    strcpy(dest, src);
    return dest;
}