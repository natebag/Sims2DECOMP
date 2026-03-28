extern void AptDisplayListState_remove_all(void *);

struct AptCharacterInst_1 {
    char pad0[0x0C];
    void *m_displayList;
    int m_destroyed;
    void DestroyGCPointers();
};

void AptCharacterInst_1::DestroyGCPointers()
{
    if (m_displayList != 0) {
        AptDisplayListState_remove_all(m_displayList);
    }
    m_destroyed = 1;
}
