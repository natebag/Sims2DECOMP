// 0x80364ED0 ERenderSurface::SetSize(int, int, int) (24B)
// ASMPROC_this_alias_rN: reg=9 after=".L_fSetSize"
// ASMPROC_swap_adj: a=stw b=li which=first
// ASMPROC_swap_adj: a=stw b=li which=first

class ERenderSurface {
public:
    int SetSize(int w, int h, int p);
};

int ERenderSurface::SetSize(int w, int h, int p) {
    *(volatile int*)((char*)this + 24) = p;
    *(volatile int*)((char*)this + 0) = w;
    *(volatile int*)((char*)this + 4) = h;
    return 1;
}
