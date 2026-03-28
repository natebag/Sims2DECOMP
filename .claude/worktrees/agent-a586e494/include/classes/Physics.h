#ifndef PHYSICS_H
#define PHYSICS_H

#include "types.h"

// Physics - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 10 known fields (0 named), 18 methods

class Physics {
public:
    // Constructors / Destructors
    Physics(void)  // 0x8011896C
    ~Physics(void);  // 0x80118A00

    // Methods
    void PhysicsMove(EVec3 *);  // 0x80118A50 (924B)
    void PhysicsGravitate(EVec3 &);  // 0x80118DEC (364B)
    void PhysicsGetPos(void);  // 0x80122504 (40B)
    void PhysicsSetDrag(float);  // 0x80122650 (40B)
    void PhysicsSetVelocity(EVec3 &);  // 0x8012259C (68B)
    void PhysicsSetMaxVelocity(float);  // 0x80122678 (40B)
    void PhysicsSetAcceleration(EVec3 &);  // 0x8012260C (68B)
    void PhysicsSetPos(EVec3 &);  // 0x8012252C (68B)
    void PhysicsSetConstants(float, float, float);  // 0x801226CC (56B)
    void PhysicsGetVelocity(void);  // 0x80122570 (44B)
    void PhysicsGetAccelerationScale(void);  // 0x801226A0 (44B)
    void PhysicsGetAcceleration(void);  // 0x801225E0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (PhysicsGravitate, PhysicsMove)
    f32 m_field_004;  // 0x004 [R/W] (PhysicsGravitate, PhysicsMove)
    f32 m_field_008;  // 0x008 [R/W] (PhysicsGravitate, PhysicsMove)
    f32 m_field_00C;  // 0x00C [R/W] (PhysicsMove)
    f32 m_field_010;  // 0x010 [R] (PhysicsMove)
    f32 m_field_014;  // 0x014 [R] (PhysicsMove)
    f32 m_field_018;  // 0x018 [R/W] (PhysicsGravitate, PhysicsMove)
    u8 _pad_01C[8];  // 0x01C
    f32 m_field_024;  // 0x024 [R] (PhysicsMove)
    f32 m_field_028;  // 0x028 [R] (PhysicsMove)
    f32 m_field_02C;  // 0x02C [R] (PhysicsGravitate)
};

#endif // PHYSICS_H
