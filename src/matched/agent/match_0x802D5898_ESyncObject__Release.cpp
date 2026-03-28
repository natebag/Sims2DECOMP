/* ESyncObject::Release(unsigned int) at 0x802D5898 (52B) */

struct Vt_ESyncObject_Release { char pad[0x18]; short m_off; int (*m_fn)(void *, unsigned int); };
struct S_ESyncObject_Release { Vt_ESyncObject_Release *m_vt; void func(unsigned int id); };

void S_ESyncObject_Release::func(unsigned int id) {
    Vt_ESyncObject_Release *vt = m_vt;
    short off = vt->m_off;
        vt->m_fn((char *)this + off, id);
}
