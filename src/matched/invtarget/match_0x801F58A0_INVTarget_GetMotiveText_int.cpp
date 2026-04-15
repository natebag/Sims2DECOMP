// INVTarget::GetMotiveText(int, unsigned wchar_t *) at 0x801F58A0 (104B)
// MI vcall dispatch + forward to ObjSelector overload

typedef unsigned char u8;
class ObjSelector;
class INVTarget;

extern u8* g_invMgr;  // at -21508(r13)

class INVTarget {
public:
    int GetMotiveText(int type, unsigned short* text);
    int GetMotiveText(ObjSelector* sel, unsigned short* text);
};

int INVTarget::GetMotiveText(int /*type*/, unsigned short* text) {
    u8* mgr = g_invMgr;
    if (mgr == 0) return 0;
    u8* vt = *(u8**)mgr;
    short adj = *(short*)(vt + 0x78);
    ObjSelector* (*fn)(u8*) = *(ObjSelector* (**)(u8*))(vt + 0x7C);
    ObjSelector* sel = fn(mgr + adj);
    return this->GetMotiveText(sel, text);
}
