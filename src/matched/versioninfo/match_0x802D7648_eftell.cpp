/* eftell at 0x802D7648 (52B) */

struct EftellVt { char pad[0x30]; short m_off; int (*m_fn)(void *); };
struct EftellObj { char pad[0x28]; EftellVt *m_vt; int eftell(void); };

int EftellObj::eftell(void) {
    EftellVt *vt = m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    return fn((char *)this + off);
}
