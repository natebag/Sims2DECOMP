// EEngine::RetraceUpdate(float)
// 0x802E2D5C | 220 bytes
// Computes how many video retrace intervals occurred in the current frame.
// When active, takes max of four dt history floats; else uses raw dt arg.
// Divides by _retracetime (frame period), adds double 0.5 for rounding, converts to int.
// Clamps result to [1,15], stores to _retracecount, accumulates in _d_retraces.
//
// DOL layout:
//   lfs f0, _dtHist1; lfs f13, _dtHist0
//   f11 = f0; if f13>f0: f11=f13    (f11 = max(_dtHist1, _dtHist0))
//   lfs f0, _dtHist3; lfs f12, _dtHist2
//   f13 = f0; if f12>f0: f13=f12    (f13 = max(_dtHist3, _dtHist2))
//   f10 = f13; if f11>f13: f10=f11  (f10 = max(f11,f13))
//   fdivs f0, f10, _retracetime; fadd(double) f0, f0, 0.5; fctiwz f13, f0
//   stfd f13,8(r1); lwz r0,12(r1) = high 32 bits = integer result
//   _retracecount = r0; clamp [1,15]; _d_retraces += _retracecount

extern float _dtHist0;       // SDA[-26784] = 0x804FF080
extern float _dtHist1;       // SDA[-26780] = 0x804FF084
extern float _dtHist2;       // SDA[-26772] = 0x804FF08C
extern float _dtHist3;       // SDA[-26768] = 0x804FF090
extern float _retracetime;   // SDA[-22744] = 0x80500048
extern int _retracecount;    // SDA[-26804] = 0x804FF06C
extern int _d_retraces;      // SDA[-26808] = 0x804FF068

class EEngine {
public:
    int m_pad0;
    int m_pad4;
    int m_bActive;  // offset 8
    void RetraceUpdate(float dt);
};

void EEngine::RetraceUpdate(float dt) {
    int count;
    if (m_bActive) {
        float h1 = _dtHist1;
        float h0 = _dtHist0;
        float m1 = h1;
        if (h0 > h1) m1 = h0;
        float h3 = _dtHist3;
        float h2 = _dtHist2;
        float m2 = h3;
        if (h2 > h3) m2 = h2;
        float mmax = m2;
        if (m1 > m2) mmax = m1;
        count = (int)(mmax / _retracetime + 0.5);
        _retracecount = count;
        if (count > 0)
            goto clamp;
        goto set1;
    }
    count = (int)(dt / _retracetime + 0.5);
    _retracecount = count;
    if (count <= 0)
        goto set1;
clamp:
    if (count > 15)
        count = 15;
    goto store;
set1:
    count = 1;
store:
    _retracecount = count;
    _d_retraces = _d_retraces + _retracecount;
}
