// 0x8026BDC8 AptGetSizeOfAptValue (40b)
typedef unsigned int uint;
typedef unsigned char uchar;

extern uchar gAptValueSizeTable[];

struct AptValue {
    uint m_data;
    char _pad[12];
    int m_size;
};

int AptGetSizeOfAptValue(AptValue *val) {
    uint type = val->m_data & 0x7F;
    if (type == 37) return val->m_size;
    return gAptValueSizeTable[type];
}
