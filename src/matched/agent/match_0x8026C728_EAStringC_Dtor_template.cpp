// FLAGS: -fno-schedule-insns2

// EAStringC::~EAStringC(void) template — matches ~12 functions
// 0x8026c728, 0x80282044, 0x8028fcc8, 0x80298e88, 0x802a1dcc,
// 0x802a8b4c, 0x802aef64, 0x802b00d0, 0x802b4d68, 0x802ba2d8, 0x802bb754

struct EAStringC {
    char* m_ptr;
};

extern void* g_pool_mgr;
extern void Deallocate(void* pool, void* ptr, unsigned int size);
extern void builtin_delete(void* ptr);

void EAStringC_Dtor(EAStringC* self, int flag) {
    char* buf = self->m_ptr;
    unsigned short ref = *(unsigned short*)buf;
    unsigned short masked = ref - 1;
    ref = masked;
    *(unsigned short*)buf = ref;
    if (masked == 0) {
        unsigned short len = *(unsigned short*)(buf + 4);
        Deallocate(g_pool_mgr, buf, len + 9);
    }
    if (flag & 1) {
        builtin_delete(self);
    }
}
