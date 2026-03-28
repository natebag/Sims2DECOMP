#ifndef MOTIVECURVESET_H
#define MOTIVECURVESET_H

#include "types.h"

// MotiveCurveSet - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (0 named), 13 methods

class MotiveCurveSet {
public:
    // Constructors / Destructors
    MotiveCurveSet(MotiveCurve *, int)  // 0x80260370

    // Methods
    void PrintMotiveGraph(__sFILE *, StringSet *);  // 0x8025F1E4 (140B)
    void PrintMotiveGraph(char *);  // 0x8025F270 (136B)
    void LoadFromFile(unsigned int, short);  // 0x8025F2F8 (684B)
    void size(void);  // 0x8025F6D8 (44B)
    void LoadFromStringSet(char **, int);  // 0x8025F5A4 (308B)
    void operator[](int);  // 0x80260260 (56B)
    void begin(void);  // 0x802601FC (44B)
    void end(void);  // 0x80260228 (56B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (LoadFromFile, LoadFromStringSet)
    u32 m_field_004;  // 0x004 [R] (LoadFromFile)
};

#endif // MOTIVECURVESET_H
