// 0x802B4BF4 AptValue::isCIH (52b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__isCIH(AptValue *self, int includeAll) {
    unsigned int val = self->m_data;
    int result = 0;
    unsigned int type = val & 0x7F;
    if (type - 12 <= 7) {
        if (includeAll || (val & 0x08000000)) {
            result = 1;
        }
    }
    return result;
}
