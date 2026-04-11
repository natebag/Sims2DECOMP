// 0x80364D24 EMovie::EMovie (20b)

extern int EMovie_vtable[];

struct EMovie {
    char _pad[8];   // 0x00 — parent class data
    int* m_vt;      // 0x08 — vtable slot
    EMovie();
};

EMovie::EMovie() {
    m_vt = (int*)EMovie_vtable;
}
