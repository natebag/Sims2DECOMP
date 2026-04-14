/* AptValue::isUndefined(void) const at 0x802B49F0 (16B) */

struct AptValue {
    unsigned int m_data;

    int isUndefined(void) const;
};

int AptValue::isUndefined(void) const {
    return ((m_data >> 27) & 1) ^ 1;
}
