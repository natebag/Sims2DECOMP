#ifndef PHYSICS_H
#define PHYSICS_H

#include "types.h"

struct EVec3;

// ============================================================================
// Physics - Physics simulation for game objects
// Size: 0x30 (48 bytes) based on constructor analysis
//
// Member layout (from constructor at 0x80058F8C):
//   +0x00: EVec3 m_vec0        (position/velocity)
//   +0x0C: EVec3 m_vec1        (force/acceleration)
//   +0x18: EVec3 m_vec2        (additional physics vector)
//   +0x24: float m_field24
//   +0x28: float m_field28
//   +0x2C: float m_field2C
// ============================================================================
class Physics {
public:
    Physics(void);
    ~Physics(void);

    void PhysicsMove(EVec3* outPos);
    void PhysicsGravitate(EVec3& gravity);

    // All floats initialized to 0.0 in constructor
    float m_vec0X;    // +0x00
    float m_vec0Y;    // +0x04
    float m_vec0Z;    // +0x08
    float m_vec1X;    // +0x0C
    float m_vec1Y;    // +0x10
    float m_vec1Z;    // +0x14
    float m_vec2X;    // +0x18
    float m_vec2Y;    // +0x1C
    float m_vec2Z;    // +0x20
    float m_field24;  // +0x24
    float m_field28;  // +0x28
    float m_field2C;  // +0x2C
};

#endif // PHYSICS_H
