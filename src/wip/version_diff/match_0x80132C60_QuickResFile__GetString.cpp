/* QuickResFile::GetString(StringBuffer &, short, short) at 0x80132C60 (188B) */

typedef unsigned int uint;

struct StringBuffer {
    void erase(void);
    void append(char*, int);
};

void* FindResStrings(void*, void*, int);

struct QuickResFile {
    void GetString(StringBuffer&, short, short) const;
};

void QuickResFile::GetString(StringBuffer& buf, short col, short row) const {
    buf.erase();

    uint* self = (uint*)this;
    uint* data = (uint*)self[2];
    if (!data) return;

    uint* arr = (uint*)data[4];
    uint count = 0;
    if (arr) count = *(arr - 1);

    void* begin = (void*)arr;
    void* end = (void*)((char*)arr + count * 12);
    void* found = FindResStrings(begin, end, (int)col);
    if (!found) return;
    if (row <= 0) return;

    char** strings = *(char***)found;
    uint str_count = 0;
    if (strings) str_count = *((uint*)strings - 1);
    if ((int)row > (int)str_count) return;

    char* str = strings[row - 1];
    if (!str) return;

    buf.append(str, -1);
}
