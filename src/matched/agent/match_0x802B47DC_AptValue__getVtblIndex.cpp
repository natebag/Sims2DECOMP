// 0x802B47DC AptValue::getVtblIndex (12b)

struct AptValue {
    unsigned int m_data;
};

int AptValue__getVtblIndex(AptValue *self) {
    return self->m_data & 0x7F;
}
