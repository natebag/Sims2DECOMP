extern "C" void setBit(void* data, int index, int value);
struct EBitArrayProxy { void* m_data; int m_index; };
void EBitArrayProxy_op_assign(EBitArrayProxy* self, int value) {
    setBit(self->m_data, self->m_index, value);
}
