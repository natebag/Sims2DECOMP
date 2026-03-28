static void* s_freeList_AptFloat_ForceDelete;
struct AptFloat_ForceDelete_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptFloat_ForceDelete_S::func() {
    m_next = s_freeList_AptFloat_ForceDelete;
    s_freeList_AptFloat_ForceDelete = this;
}
