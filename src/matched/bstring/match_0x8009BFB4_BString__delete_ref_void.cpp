// 0x8009BFB4 BString::delete_ref(void) (96 B)
// FLAGS: -fno-schedule-insns
//
// Drops a reference on the shared rep. Decrements m_ref_count; when it hits
// zero the rep is destroyed (explicit complete-object dtor) and the rep object
// itself is returned to the string allocator.

struct basic_string_ref {
    char* m_data;
    int   m_length;
    int   m_capacity;
    int   m_ref_count;
    ~basic_string_ref();
};

extern void* GetAllocator_sr();
extern void  Free_sr(void*, basic_string_ref*);

struct BString {
    basic_string_ref* m_rep;
    void delete_ref();
};

void BString::delete_ref()
{
    --m_rep->m_ref_count;
    if (m_rep->m_ref_count == 0) {
        m_rep->~basic_string_ref();
        basic_string_ref* rep = m_rep;
        void* alloc = GetAllocator_sr();
        Free_sr(alloc, rep);
    }
}
