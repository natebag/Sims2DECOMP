/* EFileSystem::Destroy(EFile *&) at 0x802C7000 (76B) */

struct DFVt { char pad[0x10]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct DFSub { char pad[0x28]; DFVt *m_sub; };

struct EFileSysD {
    void Destroy(DFSub *&ref);
};

void EFileSysD::Destroy(DFSub *&ref) {
    DFSub *file = ref;
    DFVt *sub = file->m_sub;
    short off = sub->m_off;
    int (*fn)(void *) = sub->m_fn;
    fn((char *)file + off);
    ref = 0;
}
