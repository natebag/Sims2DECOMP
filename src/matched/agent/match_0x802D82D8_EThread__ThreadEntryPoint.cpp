/* EThread::ThreadEntryPoint(void *) at 0x802D82D8 (56B) */

struct ThreadVt { char pad[0x10]; short m_off; int (*m_fn)(void *); };
struct EThread_TEP { char pad[0x338]; ThreadVt *m_vt; int ThreadEntryPoint(void *arg); };

int EThread_TEP::ThreadEntryPoint(void *arg) {
    ThreadVt *vt = m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    fn((char *)this + off);
    return 0;
}
