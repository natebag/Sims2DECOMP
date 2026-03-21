// espriterender.cpp - ESpriteRender, ESpriteRenderMan
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(espriterender.obj, espriterenderman.obj)
//
// Small functions (<=64 bytes) decompiled from these object files.
// ESpriteRender handles 2D sprite rendering, ESpriteRenderMan manages them.

#include "types.h"

//=============================================================================
// ESpriteRenderMan
//=============================================================================
class ESpriteRenderMan {
public:
    void* m_first;      // 0x00
    void* m_list;       // 0x04
    int m_enabled;      // 0x08

    // ESpriteRenderMan constructor
    // Address: 0x80036EA0, Size: 28
    ESpriteRenderMan() {
        m_first = NULL;
        m_enabled = 1;
        m_list = NULL;
    }
};
