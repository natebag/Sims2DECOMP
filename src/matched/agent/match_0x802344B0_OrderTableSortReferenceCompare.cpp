struct EOrderTableData {
    void *m_instance;
    float m_sortRef;
    float m_sortRef2;
};

struct EInstance {
    char pad[0x18];
    int m_resId;
};

int OrderTableSortReferenceCompare(void *a, void *b) {
    EOrderTableData *otdA = (EOrderTableData *)a;
    EOrderTableData *otdB = (EOrderTableData *)b;

    if (otdA->m_sortRef < otdB->m_sortRef)
        return 1;
    if (otdA->m_sortRef > otdB->m_sortRef)
        return -1;

    if (otdA->m_sortRef2 < otdB->m_sortRef2)
        return 1;
    if (otdA->m_sortRef2 > otdB->m_sortRef2)
        return -1;

    EInstance *instA = (EInstance *)otdA->m_instance;
    EInstance *instB = (EInstance *)otdB->m_instance;
    return instA->m_resId - instB->m_resId;
}
