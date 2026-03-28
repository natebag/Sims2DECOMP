struct EBitArray_FUBS {
    void* m_buffer;
    int m_size;
    void Resize(int, int);
    void FreeUnusedBufferSpace();
};

void EBitArray_FUBS::FreeUnusedBufferSpace() {
    Resize(m_size, 0);
}
