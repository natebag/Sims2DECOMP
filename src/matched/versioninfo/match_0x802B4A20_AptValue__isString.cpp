// 0x802B4A20 AptValue::isString (48b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isString(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    unsigned int type = val & 0x7F;
    if (type == 1 || type == 42) {
        if (val & 0x08000000) {
            result = 1;
        }
    }
    return result;
}
