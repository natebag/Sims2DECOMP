static void* s_freeList_AptFloat_Destroy;
struct AptFloat_Destroy_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptFloat_Destroy_S::func() {
    m_next = s_freeList_AptFloat_Destroy;
    s_freeList_AptFloat_Destroy = this;
}
