// 0x802B4A50 AptValue::isBoolean (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isBoolean(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 5) {
        result = (val >> 27) & 1;
    }
    return result;
}
