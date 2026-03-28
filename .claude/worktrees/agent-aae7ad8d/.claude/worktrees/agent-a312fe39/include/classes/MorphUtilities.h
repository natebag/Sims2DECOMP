#ifndef MORPHUTILITIES_H
#define MORPHUTILITIES_H

#include "types.h"

// MorphUtilities - struct layout extracted from assembly analysis
// Estimated minimum size: 0x124 (292 bytes)
// 2 known fields (0 named), 20 methods

class MorphUtilities {
public:
    // Constructors / Destructors
    MorphUtilities(EIStaticModel **)  // 0x80110C7C
    ~MorphUtilities(void);  // 0x80110CB0

    // Methods
    void ApplyAllMorphs(CasSimDescriptionS2C &);  // 0x80110D08 (128B)
    void ApplyMorph(CasEventMorphSimS2C::MorphPartS2C, float);  // 0x80110D88 (692B)
    void ApplyMorphHead(float);  // 0x8011103C (320B)
    void MorphLatticeOnBodyPart(unsigned int, float, unsigned int);  // 0x801114E8 (604B)
    void MorphLatticeOnHead(unsigned int, float, unsigned int);  // 0x8011117C (876B)
    /* ? */ GetHeadLatticeIndexAndValue(float, float &, int &, float &, int &);  // 0x80111A60 (560B)
    /* ? */ GetBodyLatticeIndexAndValue(float, float &, int &, float &, int &);  // 0x801118D0 (400B)
    /* ? */ GetFacialMorphTargetIndexAndValue(float, float &, int &, float &, int &);  // 0x80111744 (396B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (MorphLatticeOnBodyPart, MorphLatticeOnHead)
    u8 _pad_004[0x11C];  // 0x004
    u32 m_field_120;  // 0x120 [R] (MorphLatticeOnHead)
};

#endif // MORPHUTILITIES_H
