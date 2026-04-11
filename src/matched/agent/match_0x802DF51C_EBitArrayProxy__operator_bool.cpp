struct EBitArrayProxy {
    void* m_array;
    int m_index;
};

extern int GetBit(void* arr, int idx);

int EBitArrayProxy__operator_bool(EBitArrayProxy* self) {
    return GetBit(self->m_array, self->m_index);
}
