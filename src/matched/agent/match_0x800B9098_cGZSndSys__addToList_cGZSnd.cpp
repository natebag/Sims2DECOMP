/* cGZSndSys::addToList(cGZSnd *) at 0x800B9098 (16B) */

struct cGZSnd {
    char pad[0x3C];
    void* m_next;
};

struct cGZSndSys {
    char pad[0x404];
    cGZSnd* m_sndList;

    void addToList(cGZSnd* snd);
};

void cGZSndSys::addToList(cGZSnd* snd) {
    snd->m_next = m_sndList;
    m_sndList = snd;
}
