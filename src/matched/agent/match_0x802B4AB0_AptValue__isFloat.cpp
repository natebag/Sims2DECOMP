// 0x802B4AB0 AptValue::isFloat (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isFloat(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 6) {
        result = (val >> 27) & 1;
    }
    return result;
}
