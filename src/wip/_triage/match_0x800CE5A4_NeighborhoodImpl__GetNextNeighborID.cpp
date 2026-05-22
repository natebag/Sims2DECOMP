// 0x800CE5A4 NeighborhoodImpl::GetNextNeighborID(short) const (84B)
// TRIAGE

class NeighborhoodImpl {
public:
    char pad_000[116];
    void** m_begin;   // 116
    void** m_end;     // 120
    short GetNextNeighborID(short id) const;
};

short NeighborhoodImpl::GetNextNeighborID(short id) const {
    void** beg = m_begin;
    int count = (int)((char*)m_end - (char*)beg) >> 2;
    if ((unsigned int)id >= (unsigned int)count) goto fail;
    {
        void** beg2 = beg;
        int count2 = count;
        do {
            id = (short)(id + 1);
            if (beg2[id - 1] != 0) return id;
        } while ((unsigned int)id < (unsigned int)count2);
    }
fail:
    return 0;
}
