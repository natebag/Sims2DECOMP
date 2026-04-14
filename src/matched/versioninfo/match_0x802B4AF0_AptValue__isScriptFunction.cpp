// 0x802B4AF0 AptValue::isScriptFunction (36b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isScriptFunction(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    unsigned int type = val & 0x7F;
    if (type - 43 <= 2) {
        result = (val >> 27) & 1;
    }
    return result;
}
