// FLAGS: -fno-schedule-insns
// 0x800CDD40 (56 bytes)
// NeighborhoodImpl::FindNeighborByID(int)

struct NeighborhoodImpl_FNBI {
    char pad[116];
    void** m_neighborsBegin;
    void** m_neighborsEnd;
    void* FindNeighborByID(int id) const;
};

void* NeighborhoodImpl_FNBI::FindNeighborByID(int id) const {
    register void** begin asm("r11");
    void** end;
    unsigned int count;
    if (id <= 0) goto null_exit;
    begin = m_neighborsBegin;
    end = m_neighborsEnd;
    count = (end - begin);
    if ((unsigned int)id <= count) goto proceed;
null_exit:
    return 0;
proceed:
    {
        register int idx asm("r9") = id - 1;
        return *(void**)((char*)begin + (idx << 2));
    }
}
