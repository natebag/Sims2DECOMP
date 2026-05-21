// 0x8021CE00 FadeSquare::FadeSquare(void) (76B)
// Calls AddRefAsync(0x967660EAu) on _modelman, stores handle in m_field_0c, then StopDraw().

struct EResMan { void* AddRefAsync(unsigned int id); };
extern "C" char _modelman[];

struct FadeSquare {
    char pad[12];
    void* m_field_0c;
    float m_timer;
    int   m_flag;
    void StopDraw();
    FadeSquare();
};

FadeSquare::FadeSquare() {
    m_field_0c = ((EResMan*)_modelman)->AddRefAsync(0x967660EAu);
    StopDraw();
}
