// 0x8021CE4C (100B) FadeSquare::~FadeSquare(void)
// Variant L: if/else dispatch — EResource::DelRef on m_c OR fallback helper with magic constants + delete branch.

extern char g_fadeSquareGlobal[];

void EResource_DelRef(void* obj);
void FadeSquare_AltCleanup(void* g, unsigned int magic);
void __builtin_delete(void* p);

struct FadeSquare {
    char pad_00_0b[12];
    void* m_field_0c;
    void dtor(int flag);
};

void FadeSquare::dtor(int flag) {
    if (m_field_0c != 0) {
        EResource_DelRef(m_field_0c);
    } else {
        FadeSquare_AltCleanup(g_fadeSquareGlobal, 0x967660EAU);
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
