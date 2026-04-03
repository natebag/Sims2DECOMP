extern void AptDisplayListState_remove_all_3(void *);

struct AptCharacterInst_3 {
    char pad0[0x0C];
    void *m_displayList;
    int m_destroyed;
    void DestroyGCPointers();
};

void AptCharacterInst_3::DestroyGCPointers()
{
    if (m_displayList != 0) {
        AptDisplayListState_remove_all_3(m_displayList);
    }
    m_destroyed = 1;
}
