/* EMutex::Release(char *) at 0x802CBA3C (52B) */

struct Vt_EMutex_Release { char pad[0x18]; short m_off; int (*m_fn)(void *, char *); };
struct S_EMutex_Release { Vt_EMutex_Release *m_vt; void func(char *name); };

void S_EMutex_Release::func(char *name) {
    Vt_EMutex_Release *vt = m_vt;
    short off = vt->m_off;
        vt->m_fn((char *)this + off, name);
}
