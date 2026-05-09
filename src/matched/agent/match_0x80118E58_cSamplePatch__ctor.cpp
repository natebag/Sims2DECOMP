// cSamplePatch::cSamplePatch(SndEvtHitPatch *, float) - 0x80118E58 (44B)
// Constructor: copies 2 ints from patch, stores volume, zero-inits 3 word fields.

struct SndEvtHitPatch {
    int m_a;          // +0x00
    int m_b;          // +0x04
};

class cSamplePatch {
public:
    char _pad0[4];    // +0x00
    int m_zero04;     // +0x04
    int m_b;          // +0x08
    int m_a;          // +0x0c
    int m_zero10;     // +0x10
    float m_volume;   // +0x14
    int m_zero18;     // +0x18
    cSamplePatch(SndEvtHitPatch* patch, float volume);
};

cSamplePatch::cSamplePatch(SndEvtHitPatch* patch, float volume)
{
    m_zero04 = 0;
    m_zero10 = 0;
    m_zero18 = 0;
    m_b = patch->m_b;
    m_a = patch->m_a;
    m_volume = volume;
}
