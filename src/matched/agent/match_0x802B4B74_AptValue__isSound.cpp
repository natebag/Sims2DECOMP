// 0x802B4B74 AptValue::isSound (32b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isSound(AptValue *self) {
    unsigned int val = self->m_data;
    int result = 0;
    if ((val & 0x7F) == 21) {
        result = (val >> 27) & 1;
    }
    return result;
}
