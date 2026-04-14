// 0x802B4BD4 AptValue::isScriptColour (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isScriptColour(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 26) {
        result = (val >> 27) & 1;
    }
    return result;
}
