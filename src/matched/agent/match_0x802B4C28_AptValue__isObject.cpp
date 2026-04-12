// 0x802B4C28 AptValue::isObject (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isObject(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 27) {
        result = (val >> 27) & 1;
    }
    return result;
}
