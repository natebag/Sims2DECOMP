struct ERC { void* m_inner; };
extern "C" void* allocFlushable(void*, unsigned int size, int flags);
void* ERC_AllocFlushable(ERC* self, unsigned int size, int flags) {
    return allocFlushable((char*)self->m_inner + 0x18, size, flags);
}
