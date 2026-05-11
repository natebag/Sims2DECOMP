// 0x802F1350 EGraphics::FreeDL(EDL*, RCMode) (64B)
// Tech #56 MI-vcall via secondary vtable at p+100, slot 1 (vt+8/vt+12).
// Sibling-template for EGraphics::Free* family (also: FreeRC at vt+112).

struct EDL;
enum RCMode { RC_NONE = 0 };

struct EGraphics {
    void FreeDL(EDL* dl, RCMode mode);
};

void EGraphics::FreeDL(EDL* dl, RCMode mode) {
    if (dl != 0) {
        char* vt = *(char**)((char*)dl + 100);
        short thisOff = *(short*)(vt + 8);
        void (*fn)(void*, int) = *(void(**)(void*, int))(vt + 12);
        fn((char*)dl + thisOff, 3);
    }
}
