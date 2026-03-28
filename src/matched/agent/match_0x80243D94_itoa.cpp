void strrev(char *);

static const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";

void itoa(unsigned int value, char *str, int base)
{
    int neg = value >> 31;
    if (neg && base == 10) {
        value = -(int)value;
    }
    int i = 0;
    do {
        unsigned int q = value / (unsigned int)base;
        unsigned int r = value - q * (unsigned int)base;
        str[i] = digits[r];
        i++;
        value = q;
    } while (value != 0);

    if (neg) {
        str[i] = '-';
        i++;
    }
    str[i] = 0;
    strrev(str);
}
