struct DataBlock_RB {
    int data;
};
void ReleaseBufferImpl(void* str, DataBlock_RB* data);
struct EString_RB {
    DataBlock_RB* m_data;
    void ReleaseBuffer();
};
void EString_RB::ReleaseBuffer() {
    ReleaseBufferImpl(this, m_data);
}
