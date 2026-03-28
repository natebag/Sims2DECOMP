static void* s_freeList_AptInteger_ForceDelete;
struct AptInteger_ForceDelete_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptInteger_ForceDelete_S::func() {
    m_next = s_freeList_AptInteger_ForceDelete;
    s_freeList_AptInteger_ForceDelete = this;
}
