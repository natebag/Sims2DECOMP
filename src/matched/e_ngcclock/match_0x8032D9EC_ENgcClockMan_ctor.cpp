// 0x8032D9EC ENgcClockMan::ENgcClockMan (20b)

extern int ENgcClockMan_vtable[];

struct ENgcClockMan {
    int* m_vt;
    ENgcClockMan();
};

ENgcClockMan::ENgcClockMan() {
    *(int**)this = ENgcClockMan_vtable;
}
