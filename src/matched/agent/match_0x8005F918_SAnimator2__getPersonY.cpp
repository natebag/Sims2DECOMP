/* SAnimator2::getPersonY(void) at 0x8005F918 (64B) */

struct PersonPosVtableY {
    char pad[0x340];
    short m_vbaseOff;
    void *(*m_getPosFunc)(void *);
};

struct PersonPosInnerY {
    char pad[0x04];
    PersonPosVtableY *m_vtable;
};

struct PersonPosObjY {
    PersonPosInnerY *m_inner;
};

struct SAnimator2Y {
    char pad[0x04];
    PersonPosObjY *m_posObj;

    int getPersonY(void);
};

int SAnimator2Y::getPersonY(void) {
    PersonPosObjY *obj = m_posObj;
    PersonPosInnerY *inner = obj->m_inner;
    PersonPosVtableY *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    void *(*fn)(void *) = vt->m_getPosFunc;
    int *result = (int *)fn((char *)inner + off);
    return result[0];
}
