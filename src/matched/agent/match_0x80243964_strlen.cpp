typedef unsigned long size_t;

size_t strlen(const char *s)
{
    const char *start = s;
    if (((unsigned int)s & 3) != 0) {
        goto byte_check;
    }

    {
        unsigned int w = *(const unsigned int *)s;
        unsigned int magic = 0x80808080u;
        w = (unsigned int)(w + 0xFEFEFEFFu) & ~w;
        if ((w & magic) != 0) {
            goto byte_check;
        }

        {
            unsigned int magic2 = 0x80808080u;
            do {
                w = *(const unsigned int *)(s += 4);
                w = (unsigned int)(w + 0xFEFEFEFFu) & ~w;
            } while ((w & magic2) == 0);
        }
    }

byte_check:
    {
        char c = *s;
        if (c == 0) goto done;
        do {
            c = *++s;
        } while (c != 0);
    }
done:
    return (size_t)(s - start);
}
