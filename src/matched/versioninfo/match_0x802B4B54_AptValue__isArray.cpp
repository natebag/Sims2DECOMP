// 0x802B4B54 AptValue::isArray (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isArray(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 22) {
        result = (val >> 27) & 1;
    }
    return result;
}
