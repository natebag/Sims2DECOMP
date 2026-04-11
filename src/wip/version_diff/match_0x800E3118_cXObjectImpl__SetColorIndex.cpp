/* cXObjectImpl::SetColorIndex(unsigned char) at 0x800E3118 (116B) */

struct SCVt {
    char pad1[0x1E8];
    short m_offSet;
    char _p1[2];
    int (*m_setFunc)(void *, int, int);
    char pad2[0x2C8];
    short m_offGet;
    char _p2[2];
    int (*m_getFunc)(void *);
};

struct SCInner { char pad[0x04]; SCVt *m_vt; };

struct cXObjSC {
    char pad[0x04];
    SCInner *m_inner;
    int SetColorIndex(unsigned char colorIndex);
};

int cXObjSC::SetColorIndex(unsigned char colorIndex) {
    SCInner *inner = m_inner;
    SCVt *vt = inner->m_vt;
    short off1 = vt->m_offGet;
    int (*fn1)(void *) = vt->m_getFunc;
    int result = fn1((char *)inner + off1);

    inner = m_inner;
    vt = inner->m_vt;
    short off2 = vt->m_offSet;
    int (*fn2)(void *, int, int) = vt->m_setFunc;
    fn2((char *)inner + off2, 55, colorIndex);

    return result;
}
