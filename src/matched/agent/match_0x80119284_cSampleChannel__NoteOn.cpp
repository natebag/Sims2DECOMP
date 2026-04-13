// FLAGS: -fno-schedule-insns
/* cSampleChannel::NoteOn(void) at 0x80119284 (100B) */

struct NOVt {
    char pad1[0x20]; short m_off2; char _p1[2]; int (*m_fn2)(void *);
    char pad2[0x68]; short m_off1; char _p2[2]; int (*m_fn1)(void *, int);
};
struct NOImpl { NOVt *m_vt; };

struct cSampleChannelNO {
    char pad[0x04];
    NOImpl *m_impl;
    int NoteOn(void);
};

int cSampleChannelNO::NoteOn(void) {
    NOImpl *impl = m_impl;
    NOVt *vt = impl->m_vt;
    short off1 = vt->m_off1;
    int (*fn1)(void *, int) = vt->m_fn1;
    fn1((char *)impl + off1, 0);

    impl = m_impl;
    vt = impl->m_vt;
    short off2 = vt->m_off2;
    int (*fn2)(void *) = vt->m_fn2;
    return fn2((char *)impl + off2);
}
