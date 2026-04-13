// ESimsCam::SetZoom(float)
// Address: 0x80017070 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

struct ESimsCam {
    char pad[0x448];
    float m_zoom;
    
    void SetZoom(float zoom);
};

// Force lis/addi pattern
extern float g_defaultZoom __attribute__((section(".sdata")));

extern void ESimsCam_Update(ESimsCam* cam, float val);

void ESimsCam::SetZoom(float zoom) {
    m_zoom = zoom;
    register float* globalAddr = &g_defaultZoom;
    ESimsCam_Update(this, *globalAddr);
}
