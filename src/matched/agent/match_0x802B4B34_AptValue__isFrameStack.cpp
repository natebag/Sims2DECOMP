// 0x802B4B34 AptValue::isFrameStack (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isFrameStack(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 20) {
        result = (val >> 27) & 1;
    }
    return result;
}
