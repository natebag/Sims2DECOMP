// 0x802B4AD0 AptValue::isNativeFunction (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isNativeFunction(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 9) {
        result = (val >> 27) & 1;
    }
    return result;
}
