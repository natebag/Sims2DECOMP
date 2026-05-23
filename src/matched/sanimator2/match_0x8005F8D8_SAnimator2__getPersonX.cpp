// FLAGS: -fno-schedule-insns
/* 0x8005F8D8 (64 bytes) - SAnimator2::getPersonX(void) */

struct PersonPosVtable {
    char pad[0x340];
    short m_vbaseOff;
    void *(*m_getPosFunc)(void *);
};

struct PersonPosInner {
    char pad[0x04];
    PersonPosVtable *m_vtable;
};

struct PersonPosObj {
    PersonPosInner *m_inner;
};

struct SAnimator2 {
    char pad[0x04];
    PersonPosObj *m_posObj;
    int getPersonX();
};

int SAnimator2::getPersonX() {
    PersonPosObj *obj = m_posObj;
    PersonPosInner *inner = obj->m_inner;
    PersonPosVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    void *(*fn)(void *) = vt->m_getPosFunc;
    int *result = (int *)fn((char *)inner + off);
    return result[1];
}
