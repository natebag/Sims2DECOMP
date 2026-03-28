extern void AptDisplayListState_remove_all_2(void *);

struct AptCharacterInst_2 {
    char pad0[0x0C];
    void *m_displayList;
    int m_destroyed;
    void DestroyGCPointers();
};

void AptCharacterInst_2::DestroyGCPointers()
{
    if (m_displayList != 0) {
        AptDisplayListState_remove_all_2(m_displayList);
    }
    m_destroyed = 1;
}
