static void* s_freeList3;
struct AptBool_Des {
    char pad[0x0C];
    void* m_next;
    void Destroy();
};
void AptBool_Des::Destroy() {
    m_next = s_freeList3;
    s_freeList3 = this;
}
