void EAS_Free(void *, void *, int);

void *gEAS_Alloc;

struct StrData {
    unsigned short m_refCount;
    unsigned short m_pad;
    unsigned short m_capacity;
};

struct EAS_Assign {
    StrData *m_data;

    EAS_Assign *operator_eq(EAS_Assign *other);
};

EAS_Assign *EAS_Assign::operator_eq(EAS_Assign *other) {
    other->m_data->m_refCount++;
    StrData *myData = m_data;
    unsigned short rc = --myData->m_refCount;
    if (rc == 0) {
        EAS_Free(gEAS_Alloc, myData, myData->m_capacity + 9);
    }
    m_data = other->m_data;
    return this;
}
