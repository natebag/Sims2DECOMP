// 0x802B4A70 AptValue::isInteger (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isInteger(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 7) {
        result = (val >> 27) & 1;
    }
    return result;
}
