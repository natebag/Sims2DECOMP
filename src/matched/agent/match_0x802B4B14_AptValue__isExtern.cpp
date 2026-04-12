// 0x802B4B14 AptValue::isExtern (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isExtern(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 11) {
        result = (val >> 27) & 1;
    }
    return result;
}
