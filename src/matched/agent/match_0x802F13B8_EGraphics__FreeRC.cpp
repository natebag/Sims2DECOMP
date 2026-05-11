// 0x802F13B8 EGraphics::FreeRC(ERC*, RCMode) (64B)
// Tech #56 MI-vcall via secondary vtable at p+112, slot 1 (vt+8/vt+12).
// Sibling-port from 0x802F1350 EGraphics::FreeDL (only offset 100->112 differs).

struct ERC;
enum RCMode { RC_NONE = 0 };

struct EGraphics {
    void FreeRC(ERC* rc, RCMode mode);
};

void EGraphics::FreeRC(ERC* rc, RCMode mode) {
    if (rc != 0) {
        char* vt = *(char**)((char*)rc + 112);
        short thisOff = *(short*)(vt + 8);
        void (*fn)(void*, int) = *(void(**)(void*, int))(vt + 12);
        fn((char*)rc + thisOff, 3);
    }
}
