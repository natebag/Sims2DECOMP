// 0x802B4BB4 AptValue::isMath (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isMath(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 23) {
        result = (val >> 27) & 1;
    }
    return result;
}
