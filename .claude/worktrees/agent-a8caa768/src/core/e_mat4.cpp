// e_mat4.cpp - 4x4 matrix math, quaternion math, related small functions
//
// Source obj files: e_mat4.obj, e_quat.obj

#include "core/e_mat4.h"
#include "core/e_vec3.h"
#include "types.h"

// External functions
extern void EMat4_Mult4x4_Impl(EMat4& out, EMat4& a, EMat4& b);
extern float EVec3_Length(EVec3* v);
extern void EQuat_ToMat4(EQuat* quat, EMat4* mat);
extern void EQuat_ExtractAxisAngle(EQuat* quat, EVec3* axis);
extern int printf(const char* fmt, ...);

// =============================================================================
// EMat4::Mult4x4
// Address: 0x802C9208, Size: 48
// Swaps args: calls impl with (r4, r5, r3) => out=this, a=param1, b=param2
// =============================================================================
void EMat4::Mult4x4(EMat4& a, EMat4& b) {
    EMat4_Mult4x4_Impl(a, b, *this);
}

// =============================================================================
// EMat4::PreScale
// Address: 0x802C9238, Size: 56
// Scales first 3 rows by scalar
// NON_MATCHING - loop structure with ctr
// =============================================================================
void EMat4::PreScale(float scale) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            m[row][col] *= scale;
        }
    }
}

// =============================================================================
// EMat4::GetColumn(int, EVec3&)
// Address: 0x802C949C, Size: 40
// Gets column from 3x3 portion (rows 0-2)
// =============================================================================
void EMat4::GetColumn(int col, EVec3& out) {
    out.x = m[0][col];
    out.y = m[1][col];
    out.z = m[2][col];
}

// =============================================================================
// EMat4::GetColumn(int, EVec4&)
// Address: 0x802C94C4, Size: 52
// Gets column from full 4x4 matrix
// =============================================================================
void EMat4::GetColumn(int col, EVec4& out) {
    out.x = m[0][col];
    out.y = m[1][col];
    out.z = m[2][col];
    out.w = m[3][col];
}

// =============================================================================
// EMat4::SetColumn(int, EVec3&)
// Address: 0x802C94F8, Size: 40
// Sets column in 3x3 portion (rows 0-2)
// =============================================================================
void EMat4::SetColumn(int col, EVec3& in) {
    m[0][col] = in.x;
    m[1][col] = in.y;
    m[2][col] = in.z;
}

// =============================================================================
// EMat4::SetColumn(int, EVec4&)
// Address: 0x802C9520, Size: 52
// Sets column in full 4x4 matrix
// =============================================================================
void EMat4::SetColumn(int col, EVec4& in) {
    m[0][col] = in.x;
    m[1][col] = in.y;
    m[2][col] = in.z;
    m[3][col] = in.w;
}

// =============================================================================
// EMat4::GetScaleX
// Address: 0x802C97CC, Size: 48
// Gets length of column 0 (X axis scale)
// =============================================================================
float EMat4::GetScaleX() {
    EVec3 col;
    GetColumn(0, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::GetScaleY
// Address: 0x802C97FC, Size: 48
// Gets length of column 1 (Y axis scale)
// =============================================================================
float EMat4::GetScaleY() {
    EVec3 col;
    GetColumn(1, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::GetScaleZ
// Address: 0x802C982C, Size: 48
// Gets length of column 2 (Z axis scale)
// =============================================================================
float EMat4::GetScaleZ() {
    EVec3 col;
    GetColumn(2, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::PostTranslate
// Address: 0x802CA2D4, Size: 56
// Adds translation to row 3 (translation row)
// m[3][0] += v.x, m[3][1] += v.y, m[3][2] += v.z
// =============================================================================
void EMat4::PostTranslate(EVec3& translation) {
    m[3][0] += translation.x;
    m[3][1] += translation.y;
    m[3][2] += translation.z;
}

// =============================================================================
// EMat4::PostScale
// Address: 0x802CA3D4, Size: 56
// Scales all 4 rows (full 4x4) by scalar
// NON_MATCHING - loop structure with ctr
// =============================================================================
void EMat4::PostScale(float scale) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            m[row][col] *= scale;
        }
    }
}

// =============================================================================
// EMat4::Print
// Address: 0x802CA640, Size: 4
// Empty stub (release build)
// =============================================================================
void EMat4::Print() const {
    // blr - empty in release
}

// =============================================================================
// EMat4::ExtractAxisRotation
// Address: 0x802CA720, Size: 64
// Converts matrix to quaternion, then extracts axis
// =============================================================================
void EMat4::ExtractAxisRotation(EVec3& axis) const {
    EQuat quat;
    EQuat_ToMat4(&quat, (EMat4*)this);
    EQuat_ExtractAxisAngle(&quat, &axis);
}

// =============================================================================
// EQuat::Print
// Address: 0x802CCB00, Size: 4
// Empty stub (release build)
// =============================================================================
void EQuat::Print() {
    // blr - empty in release
}

// =============================================================================
// EVec4::Print
// Address: 0x80361F34, Size: 4
// Empty stub (release build)
// =============================================================================
void EVec4::Print() {
    // blr - empty in release
}

// =============================================================================
// EVec3::Print
// Address: 0x802D5A6C, Size: 60
// Prints "(%f, %f, %f)" format
// =============================================================================
void EVec3::Print() {
    printf("(%f, %f, %f)", x, y, z);
}

// =============================================================================
// EVec3Decomp::GetBitCount
// Address: 0x802D6010, Size: 20
// Returns m_numComponents * m_bitsPerComp + 227
// =============================================================================
int EVec3Decomp::GetBitCount() {
    return m_numComponents * m_bitsPerComp + 227;
}

// =============================================================================
// EEngine::ClearCurrentLevel
// Address: 0x802E37B8, Size: 24
// Clears m_currentLevel if it matches the given level
// =============================================================================
void EEngine::ClearCurrentLevel(ERLevel* level) {
    if (m_currentLevel == level) {
        m_currentLevel = NULL;
    }
}

// =============================================================================
// EEngine::SetCurrentLevel
// Address: 0x802E38C4, Size: 8
// Sets m_currentLevel
// =============================================================================
void EEngine::SetCurrentLevel(ERLevel* level) {
    m_currentLevel = level;
}

// =============================================================================
// EGraphics::SetBackgroundColor (from e_quat.obj linkage)
// Address: 0x802F12D4, Size: 40
// Copies EVec3 to offset 0x80, stores idx at 0x10, flag at 0x8C
// =============================================================================

// =============================================================================
// EGraphics::GetBackgroundColor (from e_quat.obj linkage)
// Address: 0x802F12FC, Size: 40
// Copies EVec3 from offset 0x80, loads flag from 0x8C
// =============================================================================

// =============================================================================
// EGraphics::SetTint (from e_quat.obj linkage)
// Address: 0x802F2134, Size: 60
// Copies two EVec3 values
// =============================================================================

// =============================================================================
// EGraphics::GetTint (from e_quat.obj linkage)
// Address: 0x802F2170, Size: 60
// Copies two EVec3 values out
// =============================================================================

// =============================================================================
// operator<<(EStream&, EBound3&)
// Address: 0x802D2530, Size: 52 (from e_quat.obj)
// =============================================================================

// =============================================================================
// operator>>(EStream&, EBound3&)
// Address: 0x802D2764, Size: 52 (from e_quat.obj)
// =============================================================================

// =============================================================================
// operator<<(EStream&, EString2&)
// Address: 0x802D5378, Size: 52 (from e_quat.obj)
// =============================================================================

// =============================================================================
// EAnimController::GetAnimDistance
// Address: 0x802EA28C, Size: 64 (from e_quat.obj linkage)
// NON_MATCHING
// =============================================================================

// =============================================================================
// EAnimController::PrepareForCollision
// Address: 0x802EA28C, Size: 64 (from e_quat.obj linkage)
// NON_MATCHING
// =============================================================================

// =============================================================================
// EAnimController::CallbackIntermediateComputeMatrices
// Address: 0x802EB53C, Size: 52 (from e_quat.obj linkage)
// NON_MATCHING
// =============================================================================
