/* efflush at 0x802D767C (52B) */

struct EfflushVt { char pad[0x38]; short m_off; int (*m_fn)(void *); };
struct EfflushObj { char pad[0x28]; EfflushVt *m_vt; int efflush(void); };

int EfflushObj::efflush(void) {
    EfflushVt *vt = m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    return fn((char *)this + off);
}
