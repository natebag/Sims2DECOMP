/* cGZSndSys::addToList(cGZMusic *) at 0x800B90E8 (16B) */

struct cGZMusic {
    char pad[0x24];
    void* m_next;
};

struct cGZSndSys {
    char pad[0x408];
    cGZMusic* m_musicList;

    void addToList(cGZMusic* music);
};

void cGZSndSys::addToList(cGZMusic* music) {
    music->m_next = m_musicList;
    m_musicList = music;
}
