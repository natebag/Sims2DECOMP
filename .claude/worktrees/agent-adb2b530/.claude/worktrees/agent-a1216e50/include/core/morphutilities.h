#ifndef MORPHUTILITIES_H
#define MORPHUTILITIES_H

#include "types.h"

// Forward declaration
class EIStaticModel;

// ============================================================================
// MorphUtilities - Morph/blend shape utility class
// From: morphutilities.obj
// Layout: { EIStaticModel** m_models(0x00) }
// ============================================================================
class MorphUtilities {
public:
    MorphUtilities(EIStaticModel** models);
    ~MorphUtilities(void);

    // Additional non-small functions exist in morphutilities.obj

private:
    EIStaticModel** m_models;  // 0x00 - pointer to array of model pointers
};

#endif // MORPHUTILITIES_H
