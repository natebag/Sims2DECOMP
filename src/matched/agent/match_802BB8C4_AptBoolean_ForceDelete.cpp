static void* s_freeList2;
struct AptBool_FD {
    char pad[0x0C];
    void* m_next;
    void ForceDelete();
};
void AptBool_FD::ForceDelete() {
    m_next = s_freeList2;
    s_freeList2 = this;
}
