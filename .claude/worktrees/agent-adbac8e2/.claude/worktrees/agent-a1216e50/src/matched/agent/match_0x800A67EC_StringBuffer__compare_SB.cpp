/* 0x800A67EC (68 bytes) - StringBuffer::compare(StringBuffer &) const */

int strcmp(const char *, const char *);

class StringBuffer {
public:
    char *c_str(void) const;
    int compare(StringBuffer &other) const;
};

int StringBuffer::compare(StringBuffer &other) const
{
    char *a = c_str();
    char *b = other.c_str();
    return strcmp(a, b);
}
