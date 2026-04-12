// 0x802B4A90 AptValue::isRegister (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isRegister(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 4) {
        result = (val >> 27) & 1;
    }
    return result;
}
