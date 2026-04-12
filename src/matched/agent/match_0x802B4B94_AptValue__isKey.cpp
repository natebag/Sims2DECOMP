// 0x802B4B94 AptValue::isKey (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isKey(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 24) {
        result = (val >> 27) & 1;
    }
    return result;
}
