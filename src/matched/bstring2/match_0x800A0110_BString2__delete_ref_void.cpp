// 0x800A0110 BString2::delete_ref(void) (96 B)
// FLAGS: -fno-schedule-insns
//
// Wide-char (BString2) sibling of BString::delete_ref (0x8009BFB4). Drops a
// reference on the shared rep; when m_ref_count hits zero the rep is destroyed
// (explicit complete-object dtor) and the rep object is freed via the allocator.

struct basic_string_ref2 {
    unsigned short* m_data;
    int             m_length;
    int             m_capacity;
    int             m_ref_count;
    ~basic_string_ref2();
};

extern void* GetAllocator_sr2();
extern void  Free_sr2(void*, basic_string_ref2*);

struct BString2 {
    basic_string_ref2* m_rep;
    void delete_ref();
};

void BString2::delete_ref()
{
    --m_rep->m_ref_count;
    if (m_rep->m_ref_count == 0) {
        m_rep->~basic_string_ref2();
        basic_string_ref2* rep = m_rep;
        void* alloc = GetAllocator_sr2();
        Free_sr2(alloc, rep);
    }
}
