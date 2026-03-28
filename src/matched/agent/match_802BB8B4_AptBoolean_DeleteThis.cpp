static void* s_freeList;
struct AptBool_DT {
    char pad[0x0C];
    void* m_next;
    void DeleteThis();
};
void AptBool_DT::DeleteThis() {
    m_next = s_freeList;
    s_freeList = this;
}
