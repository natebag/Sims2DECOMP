/* include/types/EVec3.h — canonical 2D/3D vector types
 *
 * S18 TypeArchaeologist deliverable. Resolves the Phase 1 ABI caveat where
 * three headers declared local float/int typedefs (SANIM_EVec3, EAC_EVec3,
 * ISOM_EVec3) because the project lacked a single shared declaration.
 *
 * ============================================================================
 * Two distinct in-game vector layouts (both 12B, but different semantics):
 *
 *   EVec3   — three floats (12B). The dominant form. Used by graphics
 *             (EBound3, ERFont), physics (Physics::PhysicsMove), animation
 *             (SAnimator2, EAnimController), all TArray<EVec3> instances,
 *             lighting, particle effects, math primitives.
 *             Evidence: src/matched/agent/match_*_EVec3.cpp ASMPROC bodies
 *             use `lfs`/`stfs`/`fmadds` against vec3 fields; sanimator2
 *             SEMANTIC matches assign `float`s directly.
 *
 *   EVec3i  — three ints (12B). Niche use: ISimsObjectModel m_pos@+0x404
 *             and m_dir@+0x410. These are likely fixed-point world-grid
 *             coordinates (Sims uses an integer lot-space). Three trivial
 *             SEMANTIC matches confirm int copy semantics (lwz/stw triplets,
 *             no float ops).
 *             Evidence: src/matched/iobject/match_0x80053DE0 (SetPos),
 *             match_0x80053E08 (SetDir), match_0x8004EB6C (SetPosStatic).
 *
 * EVec2     — two floats (8B). UI / geometry / font / 2D intersection.
 *             Evidence: src/matched/agent/match_*_EVec2.cpp.
 * ============================================================================
 *
 * Compat note: existing matched .cpp files in src/matched/ declare their own
 * local `struct EVec3 { ... };` because each file's byte-match output is
 * locked to that local declaration's ABI. Those local declarations stay —
 * they are read-only per the byte-match floor. This canonical header is for
 * NEW semantic conversions and for future include/types/ headers that need
 * to reference these types without re-deriving them.
 */
#ifndef SIMS2_TYPES_EVEC3_H
#define SIMS2_TYPES_EVEC3_H

#include "../types.h"

/* ============================================================================
 * EVec2 — 8 bytes, 2 floats. UI / 2D geometry / font snap.
 *
 * Method inventory (declared so future consumers can forward-reference; bodies
 * live in matched/agent files):
 *   Print  — debug print stub
 * ========================================================================== */
struct EVec2 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;

    void Print();
};

/* ============================================================================
 * EVec3 — 12 bytes, 3 floats. Canonical math/graphics/physics vector.
 *
 * Used by (non-exhaustive):
 *   Physics::PhysicsMove(EVec3)        @ 0x80098988
 *   EBound3::Add(EVec3)                @ 0x802C5304
 *   SAnimator2::convertAnim... (float) @ 0x800655A4 (SEMANTIC)
 *   EInstance::ShadowDirAtPointWeighted@ 0x8038B6CC
 *   TArray<EVec3> instantiations       (~17 distinct VAs in agent/)
 *
 * Method inventory (from legacy include/core/e_vec3.h):
 *   Print     — debug print
 *   ToU8s / FromU8s   — pack/unpack to [0,255] byte triplet
 *   ToS8s / FromS8s   — pack/unpack to signed byte triplet
 * ========================================================================== */
struct EVec3 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;

    void Print();
    void ToU8s(u8* out) const;
    void FromU8s(u8* in);
    void ToS8s(s8* out) const;
    void FromS8s(s8* in);
};

/* ============================================================================
 * EVec3i — 12 bytes, 3 ints. Integer-coord variant for world-grid storage.
 *
 * Used by:
 *   ISimsObjectModel::m_pos (this+0x404) — SetPos copies via int loads/stores
 *   ISimsObjectModel::m_dir (this+0x410) — SetDir same shape
 *
 * No methods (POD trivially copyable; iobject SetPos is literally
 * `m_pos = v;` compiled to 3× lwz/stw against int fields).
 * ========================================================================== */
struct EVec3i {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
};

/* ============================================================================
 * Global axis constants (declared in legacy include/core/e_vec3.h; storage
 * presumably lives in .rodata once the math TU is decompiled).
 * ========================================================================== */
extern EVec3 _X_AXIS;
extern EVec3 _Y_AXIS;
extern EVec3 _Z_AXIS;

#endif /* SIMS2_TYPES_EVEC3_H */
