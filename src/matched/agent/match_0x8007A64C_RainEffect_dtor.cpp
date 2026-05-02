// FLAGS: -msdata=eabi -G 8
// 0x8007A64C (288B) RainEffect::~RainEffect(void)
// SW2 Pack #3 Blueprint 8 — in-charge variant.
// Pattern: SetIsRaining(false); 2 emitter cleanup blocks (split + non-split) with
//          virtual delete via vt[+48 lha]/+52 lwz; DelRefAsync x2 against
//          EResourceManager singleton; flag-gated __builtin_delete tail.

class psystem;

class Emitter {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual ~Emitter();
    void UnReg(psystem*, bool);
};

class EResourceManager {
public:
    char m_internal[16];   // pad past -G 8 threshold so g_resourceManager goes to .data not .sdata
    void DelRefAsync(unsigned int);
};

class SAnimator2 {
public:
    static void SetIsRaining(bool);
};

extern EResourceManager g_resourceManager;       // 0x804B17CC
extern unsigned int g_rainSounds_a[3];           // 0x80423E38
extern unsigned int g_rainSounds_b[3];           // 0x80423E44
extern psystem* gEmitterA;                       // sda r13-22704
extern psystem* gEmitterB;                       // sda r13-22708

void __builtin_delete(void*);

struct RainEffect {
    void* m_vtable;             // +0
    Emitter* m_field_004;       // +4
    int m_field_008;            // +8 (split flag)
    char pad_00C[4];            // +12
    Emitter* m_field_010;       // +16
    char pad_014[32];           // +20..+51
    int m_soundIdx;             // +52
    void dtor(int flag);
};

void RainEffect::dtor(int flag) {
    SAnimator2::SetIsRaining(false);
    if (m_field_004 != 0) {
        if (m_field_008 == 0) {
            m_field_004->UnReg(gEmitterA, false);
        } else {
            m_field_004->UnReg(gEmitterB, false);
        }
        delete m_field_004;
    }
    g_resourceManager.DelRefAsync(g_rainSounds_a[m_soundIdx]);
    if (m_field_010 != 0) {
        m_field_010->UnReg(gEmitterA, false);
        delete m_field_010;
    }
    g_resourceManager.DelRefAsync(g_rainSounds_b[m_soundIdx]);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
