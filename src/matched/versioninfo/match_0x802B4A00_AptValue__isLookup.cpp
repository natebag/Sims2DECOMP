// 0x802B4A00 AptValue::isLookup (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isLookup(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 8) {
        result = (val >> 27) & 1;
    }
    return result;
}
