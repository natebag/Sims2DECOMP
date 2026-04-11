class ESimsCam;

// FLAGS: -fno-schedule-insns
// External functions
extern "C" void sub_80019A04(ESimsCam*);
extern "C" void sub_802E46A0(ESimsCam*, void*);

extern void* g_pViewport;

class ESimsCam {
    char pad[16];
    void* m_viewportPtr;  // offset 16
public:
    void ForceFullScreenViewport();
};

void ESimsCam::ForceFullScreenViewport() {
    if (g_pViewport != 0) {
        sub_80019A04(this);
        float localCoords[3] = {0.0f, 1.0f, 1.0f};
        sub_802E46A0((ESimsCam*)((char*)this + 16), localCoords);
    }
}
