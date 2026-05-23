/* include/types/Physics.h — canonical layout for Physics class
 *
 * S18 TypeArchaeologist deliverable. Opportunistic legacy promotion of
 * include/core/physics.h. Per-object physics simulation primitive (gravity,
 * velocity, position-update integration).
 */
#ifndef SIMS2_TYPES_PHYSICS_H
#define SIMS2_TYPES_PHYSICS_H

#include "../types.h"
#include "EVec3.h"

/* ============================================================================
 * Physics — per-object physics simulation state
 *
 * Size: 0x30 bytes (48 bytes), 3 EVec3 + 3 floats.
 *
 * Layout from ctor 0x80058F8C (all fields zero-init in ctor):
 *   0x00 EVec3 m_vec0   (position OR velocity — legacy unclear; used as
 *                         "current pos delta" per PhysicsMove)
 *   0x0C EVec3 m_vec1   (force/acceleration accumulator)
 *   0x18 EVec3 m_vec2   (gravity bias / additional bias vector)
 *   0x24 float m_field24
 *   0x28 float m_field28
 *   0x2C float m_field2C
 *
 * Methods PhysicsMove / PhysicsGravitate consume the EVec3 fields to
 * compute the per-tick position update. Concrete semantics of vec0 vs
 * vec1 vs vec2 not yet recovered — leave as opaque math state until a
 * SEMANTIC conversion of PhysicsMove (0x80098988) pins them.
 *
 * Cross-reference: src/matched/agent/match_0x80098988_Physics__PhysicsMove_EVec3.cpp
 * (ASMPROC stub — body reveals vec0/vec1 access pattern).
 * ========================================================================== */
class Physics {
public:
    /* 0x00 */ EVec3 m_vec0;        /* position OR velocity (TBD) */
    /* 0x0C */ EVec3 m_vec1;        /* force / acceleration accum */
    /* 0x18 */ EVec3 m_vec2;        /* gravity bias */
    /* 0x24 */ f32   m_field24;
    /* 0x28 */ f32   m_field28;
    /* 0x2C */ f32   m_field2C;

    Physics(void);
    ~Physics(void);

    void PhysicsMove(EVec3* outPos);
    void PhysicsGravitate(EVec3& gravity);
};

#endif /* SIMS2_TYPES_PHYSICS_H */
