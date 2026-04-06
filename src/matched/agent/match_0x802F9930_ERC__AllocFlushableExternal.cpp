struct ERC { void* m_inner; };
extern "C" void* allocFlushExt(void*, void* ptr, int flags);
void* ERC_AllocFlushableExternal(ERC* self, void* ptr, int flags) {
    return allocFlushExt((char*)self->m_inner + 0x18, ptr, flags);
}
