struct EBitArray_AB {
    void* m_buffer;
    int m_size;
    void AddBits(int val, int nbits);
    void Add(int val);
};

void EBitArray_AB::Add(int val) {
    AddBits(val, m_size);
}
