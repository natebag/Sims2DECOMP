/**
 * math_utils_decomp.cpp - Foundational math and utility class decompilation
 *
 * Decompiled classes: EVec2, EVec3, EMat4, CTilePt, EController,
 *   EControllerManager, EWindow, E3DWindow, EStream, EFile, EDummyFile
 *
 * These are the core utility classes used throughout the Sims 2 GameCube
 * codebase. The math library uses a right-handed coordinate system with
 * row-major 4x4 matrices (translation in row 3).
 *
 * Coordinate system:
 *   - Row-major EMat4: m[row][col], 64 bytes (4x4 floats)
 *   - Translation stored in row 3: m[3][0..2] = (tx, ty, tz)
 *   - Columns 0,1,2 of the upper 3x3 represent local X,Y,Z axes
 *   - GetScaleX/Y/Z returns the length of columns 0,1,2
 *   - Rotation matrices: RotateX/Y/Z set up standard rotation in the
 *     corresponding plane after first calling Id()
 *
 * Tile coordinate system (CTilePt):
 *   - Isometric tile grid stored as 3 signed bytes: x, y, level
 *   - Row = x + y, Column = x - y  (isometric diamond layout)
 *   - North/South use Row comparison, West/East use Column comparison
 *   - Conversions to world coords multiply by tile size (16 units) + offset 8
 *
 * Source objects: e_vec3.obj, e_mat4.obj, e_quat.obj, ctilept.obj,
 *   e_ctrl.obj, e_file.obj, e_stream.obj, e_window.obj, e_3dwindow.obj
 */

#include "types.h"
#include "core/e_vec3.h"
#include "core/e_mat4.h"

// ============================================================================
// Forward declarations and external functions
// ============================================================================

struct TilePt {
    int x;  // 0x00
    int y;  // 0x04
};

// FTilePt - fixed-point tile coordinates
// Stored as shifted integers: value = tile * 16 + 8
struct FTilePt {
    int x;  // 0x00  (tile_x * 16 + 8)
    int y;  // 0x04  (tile_y * 16 + 8)
};

struct TilePtDir;
struct EBtnToCmdAssoc;
struct EStorable;
struct ERenderSurface;
struct ERC;
struct EBound3;
struct EBoundSphere;
struct Quad;

template<typename T>
struct TRect {
    T left, top, right, bottom;
};

extern "C" void EORDbgTrace(const char* fmt, ...);
extern float sinf(float);
extern float cosf(float);
extern float atan2f(float, float);
extern float sqrtf(float);
extern float fabsf(float);

extern void EMat4_Mult4x4_Impl(EMat4& out, EMat4& a, EMat4& b);
extern float EVec3_Length(EVec3* v);
extern void EVec3_Normalize(EVec3* out, EVec3* in);
extern void EQuat_ToMat4(EQuat* quat, EMat4* mat);
extern void EQuat_ExtractAxisAngle(EQuat* quat, EVec3* axis);

// Global operator delete / new (used by various classes)
extern void operator_delete_impl(void* ptr);
extern void* operator_new_impl(unsigned int size);

// ############################################################################
//
//  SECTION 1: EVec2 / EVec3 - 2D/3D Vector Operations
//
// ############################################################################

// =============================================================================
// EVec2::Print - 0x802D5A34 (56 bytes)
// Prints vector as "x y\n" using EORDbgTrace
// NON_MATCHING: original preserves stack frame, compiler tail-call optimizes
// =============================================================================
void EVec2::Print(void) {
    EORDbgTrace("%f %f\n", x, y);
}

// =============================================================================
// EVec3::Print - 0x802D5A6C (60 bytes)
// Prints vector as "x y z\n" using EORDbgTrace
// NON_MATCHING: original preserves stack frame, compiler tail-call optimizes
// =============================================================================
void EVec3::Print(void) {
    EORDbgTrace("%f %f %f\n", x, y, z);
}

// =============================================================================
// EVec3::ToU8s - 0x802D5AA8 (120 bytes)
// Converts normalized float [0,1] components to unsigned byte [0,255], clamped
// NON_MATCHING: original uses CTR loop, compiler generates different loop
// =============================================================================
void EVec3::ToU8s(unsigned char* out) const {
    const float* src = &x;
    for (int i = 0; i < 3; i++) {
        float val = src[i] * 255.0f;
        if (val < 0.0f) {
            out[i] = 0;
        } else if (val > 255.0f) {
            out[i] = 255;
        } else {
            out[i] = (unsigned char)(int)val;
        }
    }
}

// =============================================================================
// EVec3::FromU8s - 0x802D5B20 (88 bytes)
// Converts unsigned byte [0,255] to normalized float [0,1]
// NON_MATCHING: CTR loop mismatch
// =============================================================================
void EVec3::FromU8s(unsigned char* in) {
    float* dst = &x;
    for (int i = 0; i < 3; i++) {
        dst[i] = (float)in[i] * (1.0f / 255.0f);
    }
}

// =============================================================================
// EVec3::ToS8s - 0x802D5B78 (120 bytes)
// Converts normalized float [-1,1] components to signed byte [-127,127]
// NON_MATCHING: CTR loop mismatch
// =============================================================================
void EVec3::ToS8s(signed char* out) const {
    const float* src = &x;
    for (int i = 0; i < 3; i++) {
        float val = src[i] * 127.0f;
        if (val < -127.0f) {
            out[i] = -127;
        } else if (val > 127.0f) {
            out[i] = 127;
        } else {
            out[i] = (signed char)(int)val;
        }
    }
}

// =============================================================================
// EVec3::FromS8s - 0x802D5BF0 (96 bytes)
// Converts signed byte [-127,127] to normalized float [-1,1]
// NON_MATCHING: CTR loop mismatch
// =============================================================================
void EVec3::FromS8s(signed char* in) {
    float* dst = &x;
    for (int i = 0; i < 3; i++) {
        dst[i] = (float)in[i] * (1.0f / 127.0f);
    }
}


// ############################################################################
//
//  SECTION 2: EMat4 - 4x4 Matrix Operations
//
//  Row-major layout:  m[row][col]
//  Row 0-2: rotation/scale (upper 3x3)
//  Row 3:   translation
//  Column i of upper 3x3 = local axis i (X=0, Y=1, Z=2)
//
// ############################################################################

// =============================================================================
// EMat4::Mult4x4 - 0x802C9208 (48 bytes)
// Wrapper: this = a * b. Calls external impl with swapped args.
// =============================================================================
void EMat4::Mult4x4(EMat4& a, EMat4& b) {
    EMat4_Mult4x4_Impl(a, b, *this);
}

// =============================================================================
// EMat4::PreScale(float) - 0x802C9238 (56 bytes)
// Scales the upper 3x3 (rows 0-2) by a uniform scalar.
// Row 3 (translation) is NOT scaled.
// NON_MATCHING: loop vs unrolled
// =============================================================================
void EMat4::PreScale(float scale) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            m[row][col] *= scale;
        }
    }
}

// =============================================================================
// EMat4::PreScale(EVec3&) - 0x802C9270 (152 bytes)
// Non-uniform scale of upper 3x3: row i *= scale[i].
// Fully unrolled 3x3 multiply in the original:
//   m[0][0..2] *= v.x;  m[1][0..2] *= v.y;  m[2][0..2] *= v.z;
// =============================================================================
void EMat4::PreScale(EVec3& v) {
    // Row 0 *= v.x
    m[0][0] *= v.x;
    m[0][1] *= v.x;
    m[0][2] *= v.x;
    // Row 1 *= v.y
    m[1][0] *= v.y;
    m[1][1] *= v.y;
    m[1][2] *= v.y;
    // Row 2 *= v.z
    m[2][0] *= v.z;
    m[2][1] *= v.z;
    m[2][2] *= v.z;
}

// =============================================================================
// EMat4::PreTranslate(EVec3&) - 0x802C9308 (72 bytes)
// Applies translation before existing transform:
//   m[3][col] += v.x * m[0][col] + v.y * m[1][col] + v.z * m[2][col]
// Uses CTR-based loop (3 iterations for columns 0..2).
// =============================================================================
void EMat4::PreTranslate(EVec3& v) {
    // The loop iterates over columns 0, 1, 2
    // For each column c:
    //   m[3][c] += v.x * m[0][c] + v.y * m[1][c] + v.z * m[2][c]
    for (int c = 0; c < 3; c++) {
        float accum = v.y * m[1][c];
        accum = v.x * m[0][c] + accum;  // fmadds
        accum = v.z * m[2][c] + accum;  // fmadds
        m[3][c] += accum;
    }
}

// =============================================================================
// EMat4::operator=(float) - 0x802C9454 (72 bytes)
// Fills all 16 elements with the same float value.
// Fully unrolled: stores f1 to all 16 float offsets.
// =============================================================================
EMat4& EMat4::operator=(float val) {
    m[0][0] = val; m[0][1] = val; m[0][2] = val; m[0][3] = val;
    m[1][0] = val; m[1][1] = val; m[1][2] = val; m[1][3] = val;
    m[2][0] = val; m[2][1] = val; m[2][2] = val; m[2][3] = val;
    m[3][0] = val; m[3][1] = val; m[3][2] = val; m[3][3] = val;
    return *this;
}

// =============================================================================
// EMat4::GetColumn(int, EVec3&) - 0x802C949C (40 bytes)
// Extracts column from upper 3x3 (rows 0-2) into an EVec3.
// =============================================================================
void EMat4::GetColumn(int col, EVec3& out) {
    out.x = m[0][col];
    out.y = m[1][col];
    out.z = m[2][col];
}

// =============================================================================
// EMat4::GetColumn(int, EVec4&) - 0x802C94C4 (52 bytes)
// Extracts full column (all 4 rows) into an EVec4.
// =============================================================================
void EMat4::GetColumn(int col, EVec4& out) {
    out.x = m[0][col];
    out.y = m[1][col];
    out.z = m[2][col];
    out.w = m[3][col];
}

// =============================================================================
// EMat4::SetColumn(int, EVec3&) - 0x802C94F8 (40 bytes)
// Sets column in upper 3x3 (rows 0-2).
// =============================================================================
void EMat4::SetColumn(int col, EVec3& in) {
    m[0][col] = in.x;
    m[1][col] = in.y;
    m[2][col] = in.z;
}

// =============================================================================
// EMat4::SetColumn(int, EVec4&) - 0x802C9520 (52 bytes)
// Sets full column (all 4 rows).
// =============================================================================
void EMat4::SetColumn(int col, EVec4& in) {
    m[0][col] = in.x;
    m[1][col] = in.y;
    m[2][col] = in.z;
    m[3][col] = in.w;
}

// =============================================================================
// EMat4::Normalize - 0x802C9554 (160 bytes)
// Normalizes each of the 3 column vectors of the upper 3x3.
// If a column is the zero vector, it's left as-is.
// =============================================================================
void EMat4::Normalize(void) {
    EVec3 col;
    for (int i = 0; i <= 2; i++) {
        GetColumn(i, col);
        // Check if column is non-zero before normalizing
        if (col.x != 0.0f || col.y != 0.0f || col.z != 0.0f) {
            EVec3_Normalize(&col, &col);
        }
        SetColumn(i, col);
    }
}

// =============================================================================
// EMat4::Transpose(EMat4&) - 0x802C95F4 (76 bytes)
// Transposes source matrix into this: this[col][row] = src[row][col].
// Uses CTR-based nested loop.
// =============================================================================
void EMat4::Transpose(EMat4& src) {
    for (int row = 0; row <= 3; row++) {
        for (int col = 0; col < 4; col++) {
            m[col][row] = src.m[row][col];
        }
    }
}

// =============================================================================
// EMat4::Transpose(void) - 0x802C9640 (152 bytes)
// In-place transpose. Swaps m[i][j] with m[j][i] for all i != j.
// Fully unrolled: 6 swap pairs.
// =============================================================================
void EMat4::Transpose(void) {
    float tmp;
    // Swap (0,1) <-> (1,0)
    tmp = m[0][1]; m[0][1] = m[1][0]; m[1][0] = tmp;
    // Swap (0,2) <-> (2,0)
    tmp = m[0][2]; m[0][2] = m[2][0]; m[2][0] = tmp;
    // Swap (0,3) <-> (3,0)
    tmp = m[0][3]; m[0][3] = m[3][0]; m[3][0] = tmp;
    // Swap (1,2) <-> (2,1)
    tmp = m[1][2]; m[1][2] = m[2][1]; m[2][1] = tmp;
    // Swap (1,3) <-> (3,1)
    tmp = m[1][3]; m[1][3] = m[3][1]; m[3][1] = tmp;
    // Swap (2,3) <-> (3,2)
    tmp = m[2][3]; m[2][3] = m[3][2]; m[3][2] = tmp;
}

// =============================================================================
// EMat4::Id - 0x802C96D8 (88 bytes)
// Sets matrix to 4x4 identity.
// Loads 0.0f and 1.0f from const pool, stores unrolled.
// =============================================================================
void EMat4::Id(void) {
    // Off-diagonal elements = 0.0f
    m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
    m[1][0] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][3] = 0.0f;
    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f;
    m[3][3] = 0.0f;
    // Diagonal = 1.0f
    m[0][0] = 1.0f;
    m[1][1] = 1.0f;
    m[2][2] = 1.0f;
}

// =============================================================================
// EMat4::Translate(EVec3&) - 0x802C9730 (80 bytes)
// Sets identity then places translation in row 3.
// Equivalent to: Id(); m[3] = v;
// =============================================================================
void EMat4::Translate(EVec3& v) {
    Id();
    m[3][0] = v.x;
    m[3][1] = v.y;
    m[3][2] = v.z;
}

// =============================================================================
// EMat4::Scale(EVec3&) - 0x802C9780 (76 bytes)
// Sets identity then places non-uniform scale on diagonal.
// Equivalent to: Id(); m[0][0] = v.x; m[1][1] = v.y; m[2][2] = v.z;
// =============================================================================
void EMat4::Scale(EVec3& v) {
    Id();
    m[0][0] = v.x;
    m[1][1] = v.y;
    m[2][2] = v.z;
}

// =============================================================================
// EMat4::GetScaleX - 0x802C97CC (48 bytes)
// Returns length of column 0 (local X axis scale).
// =============================================================================
float EMat4::GetScaleX() {
    EVec3 col;
    GetColumn(0, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::GetScaleY - 0x802C97FC (48 bytes)
// Returns length of column 1 (local Y axis scale).
// =============================================================================
float EMat4::GetScaleY() {
    EVec3 col;
    GetColumn(1, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::GetScaleZ - 0x802C982C (48 bytes)
// Returns length of column 2 (local Z axis scale).
// =============================================================================
float EMat4::GetScaleZ() {
    EVec3 col;
    GetColumn(2, col);
    return EVec3_Length(&col);
}

// =============================================================================
// EMat4::RotateX(float) - 0x802C985C (108 bytes)
// Creates X-axis rotation matrix: Id(), then sets the YZ submatrix.
//   m[1][1] =  cos(a)   m[1][2] = -sin(a)
//   m[2][1] =  sin(a)   m[2][2] =  cos(a)
// =============================================================================
void EMat4::RotateX(float angle) {
    Id();
    float s = sinf(angle);
    float c = cosf(angle);
    m[1][1] = c;
    m[2][1] = -s;
    m[1][2] = s;
    m[2][2] = c;
}

// =============================================================================
// EMat4::RotateY(float) - 0x802C98C8 (108 bytes)
// Creates Y-axis rotation matrix: Id(), then sets the XZ submatrix.
//   m[0][0] =  cos(a)   m[0][2] =  sin(a)
//   m[2][0] = -sin(a)   m[2][2] =  cos(a)
// =============================================================================
void EMat4::RotateY(float angle) {
    Id();
    float s = sinf(angle);
    float c = cosf(angle);
    m[0][0] = c;
    m[2][0] = -s;
    m[0][2] = s;
    m[2][2] = c;
}

// =============================================================================
// EMat4::RotateZ(float) - 0x802C9934 (108 bytes)
// Creates Z-axis rotation matrix: Id(), then sets the XY submatrix.
//   m[0][0] =  cos(a)   m[0][1] = -sin(a)
//   m[1][0] =  sin(a)   m[1][1] =  cos(a)
// =============================================================================
void EMat4::RotateZ(float angle) {
    Id();
    float s = sinf(angle);
    float c = cosf(angle);
    m[0][0] = c;
    m[1][0] = -s;
    m[0][1] = s;
    m[1][1] = c;
}

// =============================================================================
// EMat4::PostTranslate(EVec3&) - 0x802CA2D4 (56 bytes)
// Adds translation to row 3: m[3] += v
// =============================================================================
void EMat4::PostTranslate(EVec3& v) {
    m[3][0] += v.x;
    m[3][1] += v.y;
    m[3][2] += v.z;
}

// =============================================================================
// EMat4::PostScale(EVec3&) - 0x802CA30C (200 bytes)
// Scales each column of the full 4x4 by the corresponding component:
//   column 0 *= v.x, column 1 *= v.y, column 2 *= v.z
// Fully unrolled: 12 multiply-stores.
// =============================================================================
void EMat4::PostScale(EVec3& v) {
    // Column 0 *= v.x
    m[0][0] *= v.x; m[1][0] *= v.x; m[2][0] *= v.x; m[3][0] *= v.x;
    // Column 1 *= v.y
    m[0][1] *= v.y; m[1][1] *= v.y; m[2][1] *= v.y; m[3][1] *= v.y;
    // Column 2 *= v.z
    m[0][2] *= v.z; m[1][2] *= v.z; m[2][2] *= v.z; m[3][2] *= v.z;
}

// =============================================================================
// EMat4::PostScale(float) - 0x802CA3D4 (56 bytes)
// Scales all 16 elements by uniform scalar.
// NON_MATCHING: loop vs CTR
// =============================================================================
void EMat4::PostScale(float scale) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            m[row][col] *= scale;
        }
    }
}

// =============================================================================
// EMat4::Clamp - 0x802CA5DC (100 bytes)
// Clamps all 16 matrix elements to [-1.0, 1.0].
// Uses CTR-based nested loop (4 rows x 4 cols).
// =============================================================================
void EMat4::Clamp(void) {
    for (int row = 0; row <= 3; row++) {
        for (int col = 0; col < 4; col++) {
            float val = m[row][col];
            if (val < -1.0f) {
                m[row][col] = -1.0f;
            } else if (val > 1.0f) {
                m[row][col] = 1.0f;
            }
        }
    }
}

// =============================================================================
// EMat4::Print - 0x802CA640 (4 bytes)
// Empty stub in release build (blr only).
// =============================================================================
void EMat4::Print() const {
    // blr - empty in release
}

// =============================================================================
// EMat4::GetMaxScale - 0x802CA644 (88 bytes)
// Returns the maximum axis scale: max of sum-of-absolute-values of each column.
// For each column c (0..2), computes sum of |m[row][c]| for row 0..2,
// and returns the maximum such sum.
// =============================================================================
float EMat4::GetMaxScale() const {
    float maxScale = 0.0f;
    for (int col = 0; col <= 2; col++) {
        float sum = 0.0f;
        for (int row = 0; row < 3; row++) {
            sum += fabsf(m[row][col]);
        }
        if (sum > maxScale) {
            maxScale = sum;
        }
    }
    return maxScale;
}

// =============================================================================
// EMat4::GetHPR - 0x802CA69C (132 bytes)
// Extracts heading, pitch, roll (Euler angles) from the rotation matrix.
//   heading = atan2(m[2][2], m[2][0])  -- rotation around vertical
//   pitch   = -atan2(m[2][1], sqrt(m[2][0]^2 + m[2][2]^2))
//   roll    = -atan2(-m[0][1], m[1][1])
// Note: indices here reference the upper 3x3 (row 2 = Z basis row)
// =============================================================================
void EMat4::GetHPR(float& heading, float& pitch, float& roll) {
    // heading = atan2(m[2][2], m[2][0])
    heading = atan2f(m[2][2], m[2][0]);

    // pitch = -atan2(m[2][1], length(m[2][0], m[2][2]))
    float len = sqrtf(m[2][0] * m[2][0] + m[2][2] * m[2][2]);
    pitch = -atan2f(m[2][1], len);

    // roll = -atan2(-m[0][1], m[1][1])
    roll = -atan2f(-m[0][1], m[1][1]);
}

// =============================================================================
// EMat4::ExtractAxisRotation - 0x802CA720 (64 bytes)
// Converts matrix to quaternion, then extracts axis-angle.
// =============================================================================
void EMat4::ExtractAxisRotation(EVec3& axis) const {
    EQuat quat;
    EQuat_ToMat4(&quat, (EMat4*)this);
    EQuat_ExtractAxisAngle(&quat, &axis);
}

// =============================================================================
// EMat4::OrientPosNormal - 0x802CA590 (76 bytes)
// Builds a matrix oriented along a normal at a position.
// Calls LookAtDirect(normal, 1.0f), then PostTranslate(pos).
// =============================================================================
void EMat4::OrientPosNormal(EVec3& pos, EVec3& unused, EVec3& normal) {
    LookAtDirect(pos, normal, 1.0f);  // Note: arg order from asm
    PostTranslate(pos);
}

// =============================================================================
// EMat4::operator=(EMat4&) - 0x8039D348 (136 bytes)
// Copies all 16 floats (64 bytes) via unrolled lwz/stw pairs.
// =============================================================================
EMat4& EMat4::operator=(EMat4& other) {
    // 16 word copies (unrolled in pairs)
    m[0][0] = other.m[0][0]; m[0][1] = other.m[0][1];
    m[0][2] = other.m[0][2]; m[0][3] = other.m[0][3];
    m[1][0] = other.m[1][0]; m[1][1] = other.m[1][1];
    m[1][2] = other.m[1][2]; m[1][3] = other.m[1][3];
    m[2][0] = other.m[2][0]; m[2][1] = other.m[2][1];
    m[2][2] = other.m[2][2]; m[2][3] = other.m[2][3];
    m[3][0] = other.m[3][0]; m[3][1] = other.m[3][1];
    m[3][2] = other.m[3][2]; m[3][3] = other.m[3][3];
    return *this;
}

// =============================================================================
// EVec4::Print - 0x80361F34 (4 bytes)
// Empty stub (release build)
// =============================================================================
void EVec4::Print() {
    // blr - empty in release
}

// =============================================================================
// EQuat::Print - 0x802CCB00 (4 bytes)
// Empty stub (release build)
// =============================================================================
void EQuat::Print() {
    // blr - empty in release
}

// =============================================================================
// EVec3Decomp::GetBitCount - 0x802D6010 (20 bytes)
// Returns total bit count: numComponents * bitsPerComp + 227
// (227 = overhead bits for header/padding in compressed format)
// =============================================================================
int EVec3Decomp::GetBitCount() {
    return m_numComponents * m_bitsPerComp + 227;
}

// =============================================================================
// EEngine::ClearCurrentLevel - 0x802E37B8 (24 bytes)
// Clears m_currentLevel pointer if it matches the given level.
// =============================================================================
void EEngine::ClearCurrentLevel(ERLevel* level) {
    if (m_currentLevel == level) {
        m_currentLevel = NULL;
    }
}

// =============================================================================
// EEngine::SetCurrentLevel - 0x802E38C4 (8 bytes)
// Sets m_currentLevel pointer.
// =============================================================================
void EEngine::SetCurrentLevel(ERLevel* level) {
    m_currentLevel = level;
}


// ############################################################################
//
//  SECTION 3: CTilePt - Isometric Tile Coordinates
//
//  Layout: 3 bytes
//    offset 0x00: s8 m_x  - tile X coordinate (signed byte, range ~[-127,127])
//    offset 0x01: s8 m_y  - tile Y coordinate
//    offset 0x02: s8 m_level - floor level
//
//  Isometric mapping:
//    Row    = m_x + m_y   (diagonal axis)
//    Column = m_x - m_y   (perpendicular diagonal)
//    North: this.Row < other.Row
//    South: this.Row > other.Row
//    West:  this.Column < other.Column
//    East:  this.Column > other.Column
//
//  World coordinate conversion (FTilePt / GetEVec3):
//    world_x = tile_x * 16 + 8
//    world_z = tile_y * 16 + 8
//
// ############################################################################

class CTilePt {
public:
    s8 m_x;     // 0x00 - tile X
    s8 m_y;     // 0x01 - tile Y
    s8 m_level; // 0x02 - floor level

    // --- Constructors ---

    // CTilePt() - 0x800B45D0 (12 bytes)
    // Default constructor: sets level to 0, x and y are uninitialized.
    CTilePt(void) {
        m_level = 0;
    }

    // CTilePt(CTilePt&) - 0x800B45DC (32 bytes)
    // Copy constructor: copies all 3 bytes.
    CTilePt(CTilePt& other) {
        m_x = other.m_x;
        m_y = other.m_y;
        m_level = other.m_level;
    }

    // CTilePt(int, int, int) - 0x800B463C (60 bytes)
    // Constructs from x, y, level with signed byte overflow check.
    // If the value doesn't fit in a signed byte, it's clamped to 0.
    CTilePt(int x, int y, int level) {
        m_x = (s8)x;
        if ((s8)m_x != x) m_x = 0;  // overflow check

        m_y = (s8)y;
        if ((s8)m_y != y) m_y = 0;  // overflow check

        m_level = (s8)level;
    }

    // --- Destructor ---

    // ~CTilePt() - 0x800B4724 (40 bytes)
    // Destructor: conditionally frees memory if bit 0 of flags is set.
    // (Standard GC ABI delete-if-allocated pattern)

    // --- Assignment ---

    // operator=(CTilePt&) - 0x800B474C (32 bytes)
    // Copies all 3 bytes. Identical codegen to copy constructor.
    CTilePt& operator=(CTilePt& other) {
        m_x = other.m_x;
        m_y = other.m_y;
        m_level = other.m_level;
        return *this;
    }

    // --- Comparison ---

    // operator==(CTilePt&) - 0x800B476C (48 bytes)
    // Compares x and y bytes only (NOT level).
    bool operator==(CTilePt& other) const {
        if (m_x != other.m_x) return false;
        return m_y == other.m_y;
    }

    // operator!=(CTilePt&) - 0x800B479C (48 bytes)
    // Inverse of ==. Compares x and y only.
    bool operator!=(CTilePt& other) const {
        if (m_x != other.m_x) return true;
        return m_y != other.m_y;
    }

    // operator<(CTilePt&) - 0x800B47CC (68 bytes)
    // Lexicographic comparison: compares x first, then y.

    // --- Arithmetic ---

    // operator+=(CTilePt&) - 0x800B4810 (40 bytes)
    // Adds x and y components (level unchanged).
    CTilePt& operator+=(CTilePt& other) {
        m_x = m_x + other.m_x;
        m_y = m_y + other.m_y;
        return *this;
    }

    // operator-=(CTilePt&) - 0x800B4838 (40 bytes)
    // Subtracts x and y components (level unchanged).
    CTilePt& operator-=(CTilePt& other) {
        m_x = m_x - other.m_x;
        m_y = m_y - other.m_y;
        return *this;
    }

    // operator*=(int) - 0x800B4860 (40 bytes)
    // Multiplies x and y by scalar (level unchanged).
    CTilePt& operator*=(int s) {
        m_x = (s8)((s8)m_x * s);
        m_y = (s8)((s8)m_y * s);
        return *this;
    }

    // operator*(int) - 0x800B4888 (80 bytes)
    // Returns new CTilePt with x*s, y*s, preserving level.

    // operator+(CTilePt&) - 0x800B48D8 (96 bytes)
    // Returns new CTilePt(this->x + other.x, this->y + other.y, this->level)

    // operator-(CTilePt&) - 0x800B4938 (96 bytes)
    // Returns new CTilePt(this->x - other.x, this->y - other.y, this->level)

    // --- Accessors ---

    // GetX() - 0x800B4CA8 (12 bytes)
    int GetX() const { return (s8)m_x; }

    // GetY() - 0x800B4CB4 (12 bytes)
    int GetY() const { return (s8)m_y; }

    // GetLevel() - 0x800B4DDC (12 bytes)
    int GetLevel() const { return (s8)m_level; }

    // SetX(int) - 0x800B4D04 (12 bytes)
    // Stores byte, returns sign-extended value.
    void SetX(int x) { m_x = (s8)x; }

    // SetY(int) - 0x800B4D10 (12 bytes)
    void SetY(int y) { m_y = (s8)y; }

    // SetLevel(int) - 0x800B4DE8 (8 bytes)
    void SetLevel(int level) { m_level = (s8)level; }

    // SetLevel(CTilePt&) - 0x800B4DF0 (12 bytes)
    void SetLevel(CTilePt& other) { m_level = other.m_level; }

    // Set(int, int) - 0x800B4D1C (12 bytes)
    void Set(int x, int y) {
        m_y = (s8)y;
        m_x = (s8)x;
    }

    // Set(int, int, int) - 0x800B4D28 (16 bytes)
    void Set(int x, int y, int level) {
        m_level = (s8)level;
        m_x = (s8)x;
        m_y = (s8)y;
    }

    // Get(int*, int*) - 0x800B4CC0 (28 bytes)
    void Get(int* outX, int* outY) const {
        *outX = (s8)m_x;
        *outY = (s8)m_y;
    }

    // Get(int*, int*, int*) - 0x800B4CDC (40 bytes)
    void Get(int* outX, int* outY, int* outLevel) const {
        *outX = (s8)m_x;
        *outY = (s8)m_y;
        *outLevel = (s8)m_level;
    }

    // --- Isometric geometry ---

    // GetRow() - 0x800B49EC (24 bytes)
    // Returns x + y (isometric row index).
    int GetRow() const { return (s8)m_x + (s8)m_y; }

    // GetColumn() - 0x800B4A04 (24 bytes)
    // Returns x - y (isometric column index).
    int GetColumn() const { return (s8)m_x - (s8)m_y; }

    // IsNorthOf(CTilePt&) - 0x800B4A98 (68 bytes)
    // North = smaller row value: this.GetRow() < other.GetRow()
    bool IsNorthOf(CTilePt& other) const {
        return GetRow() < other.GetRow();
    }

    // IsSouthOf(CTilePt&) - 0x800B4ADC (68 bytes)
    // South = larger row value: this.GetRow() > other.GetRow()
    bool IsSouthOf(CTilePt& other) const {
        return GetRow() > other.GetRow();
    }

    // IsWestOf(CTilePt&) - 0x800B4B20 (68 bytes)
    // West = smaller column: this.GetColumn() < other.GetColumn()
    bool IsWestOf(CTilePt& other) const {
        return GetColumn() < other.GetColumn();
    }

    // IsEastOf(CTilePt&) - 0x800B4B64 (68 bytes)
    // East = larger column: this.GetColumn() > other.GetColumn()
    bool IsEastOf(CTilePt& other) const {
        return GetColumn() > other.GetColumn();
    }

    // IsoCompare(CTilePt&) - 0x800B4A1C (124 bytes)
    // If rows are different, compares rows (this < other).
    // If rows are same, compares columns (this < other).
    bool IsoCompare(CTilePt& other) const {
        int thisRow = GetRow();
        int otherRow = other.GetRow();
        if (thisRow != otherRow) {
            // Different rows: compare rows
            return thisRow < otherRow;
        }
        // Same row: compare columns
        int thisCol = GetColumn();
        int otherCol = other.GetColumn();
        return thisCol < otherCol;
    }

    // SameRowParity(CTilePt&) - 0x800B4BA8 (76 bytes)
    // Returns true if both points have the same row parity (even/odd).
    bool SameRowParity(CTilePt& other) const {
        return (GetRow() & 1) == (other.GetRow() & 1);
    }

    // SameColumnParity(CTilePt&) - 0x800B4BF4 (76 bytes)
    // Returns true if both points have the same column parity.
    bool SameColumnParity(CTilePt& other) const {
        return (GetColumn() & 1) == (other.GetColumn() & 1);
    }

    // --- Conversions ---

    // ToTilePt() - 0x800B4C40 (32 bytes)
    // Converts to TilePt struct (two ints, sign-extended from bytes).
    // Returns via hidden pointer (r3).
    TilePt ToTilePt() const {
        TilePt tp;
        tp.x = (s8)m_x;
        tp.y = (s8)m_y;
        return tp;
    }

    // ToFTilePt() - 0x800B4C60 (72 bytes)
    // Converts to fixed-point tile coords: value = tile * 16 + 8.
    // This gives the center of the tile in world units (tile size = 16).
    FTilePt ToFTilePt() const {
        FTilePt ftp;
        int ix = (s8)m_x;
        int iy = (s8)m_y;
        ftp.x = (ix << 4) | 8;  // ix * 16 + 8
        ftp.y = (iy << 4) | 8;  // iy * 16 + 8
        return ftp;
    }

    // GetXf() - 0x800B4560 (56 bytes)
    // Returns X as float (sign-extended byte -> int -> float conversion).
    // Uses the "magic number" int-to-float conversion trick (xoris 0x8000).
    float GetXf() const { return (float)(s8)m_x; }

    // GetYf() - 0x800B4598 (56 bytes)
    // Returns Y as float.
    float GetYf() const { return (float)(s8)m_y; }
};


// ############################################################################
//
//  SECTION 4: EController - Input Controller
//
//  Manages button states, analog sticks, vibration motors, input filters,
//  and command mapping for a single GameCube controller.
//
//  Layout (524 bytes / 0x20C):
//    0x000: u32 m_id         - controller ID
//    0x004: u32 m_status     - status flags (bit 1 = stable)
//    0x008-0x18B: filter/button state arrays
//    0x18C: int m_axesSwapped[4] - per-stick axis swap toggle
//    0x194: int m_dirModifier[2][2] - direction inversion per axis
//    0x1A4: EBtnToCmdAssoc* m_commandMap
//    0x1A8: int m_commandMapCount
//    0x1AC: u32 m_field_1AC
//    0x1B0: u32 m_field_1B0
//    0x1B4-0x1D9: auto-repeat state
//    0x1DC: float m_motorOneStrength
//    0x1E0: float m_motorTwoStrength
//    0x1E4: float m_motorOneDuration
//    0x1E8: float m_motorTwoDuration
//    0x1EC: float m_pausedMotorOne
//    0x1F0-0x1F8: paused motor states
//    0x1FC: u32 m_eventCount
//    0x200: u32 m_btnExcl
//    0x204: u32 m_flags
//    0x208: u32 m_pauseFlags
//
// ############################################################################

// =============================================================================
// EController::GetId - 0x8030588C (8 bytes)
// Returns controller ID from offset 0x00.
// =============================================================================
// unsigned int EController::GetId(void) {
//     return *(u32*)((u8*)this + 0x00);  // lwz r3,0(r3)
// }

// =============================================================================
// EController::GetStatus - 0x80305894 (8 bytes)
// Returns status word from offset 0x04.
// =============================================================================
// unsigned int EController::GetStatus(void) {
//     return *(u32*)((u8*)this + 0x04);  // lwz r3,4(r3)
// }

// =============================================================================
// EController::IsStable - 0x8030589C (12 bytes)
// Returns bit 1 of status (shifted right by 1, masked to 1 bit).
// =============================================================================
// bool EController::IsStable(void) {
//     return (*(u32*)((u8*)this + 0x04) >> 1) & 1;
// }

// =============================================================================
// EController::OverrideStatus - 0x80304294 (8 bytes)
// Directly sets the status word at offset 0x04.
// =============================================================================
// void EController::OverrideStatus(int status) {
//     *(u32*)((u8*)this + 0x04) = status;
// }

// =============================================================================
// EController::IsControlFake - 0x80304D10 (8 bytes)
// Returns fake-control flag at offset 0x1AC.
// =============================================================================
// bool EController::IsControlFake(void) {
//     return *(u32*)((u8*)this + 0x1AC);
// }

// =============================================================================
// EController::SetControlFake - 0x80304D18 (8 bytes)
// Sets fake-control flag at offset 0x1AC.
// =============================================================================
// void EController::SetControlFake(bool fake) {
//     *(u32*)((u8*)this + 0x1AC) = fake;
// }

// =============================================================================
// EController::SetFakeButtons - 0x80304D20 (8 bytes)
// Sets fake button mask at offset 0x1B0.
// =============================================================================
// void EController::SetFakeButtons(unsigned int mask) {
//     *(u32*)((u8*)this + 0x1B0) = mask;
// }

// =============================================================================
// EController::HasVibration - 0x80304434 (8 bytes)
// Always returns false on GameCube (NGC build).
// =============================================================================
// bool EController::HasVibration(void) const {
//     return false;
// }

// =============================================================================
// EController::SwapAxes - 0x8030429C (24 bytes)
// Toggles axis swap for the given stick: m_axesSwapped[stick] ^= 1.
// Offset 0x18C + stick*4.
// =============================================================================
// void EController::SwapAxes(int stick) {
//     u32* axes = (u32*)((u8*)this + 0x18C);
//     axes[stick] ^= 1;
// }

// =============================================================================
// EController::InvertAxis - 0x803042B4 (32 bytes)
// Negates direction modifier: m_dirModifier[stick][axis] = -m_dirModifier[stick][axis]
// Offset 0x194 + stick*8 + axis*4.
// =============================================================================
// void EController::InvertAxis(int axis, int stick) {
//     u32* dirs = (u32*)((u8*)this + 0x194);
//     int idx = axis + stick * 2;
//     dirs[idx] = -dirs[idx];
// }

// =============================================================================
// EController::AreAxesSwapped - 0x80305D58 (16 bytes)
// Returns axis swap state for given stick.
// =============================================================================
// int EController::AreAxesSwapped(int stick) {
//     u32* axes = (u32*)((u8*)this + 0x18C);
//     return axes[stick];
// }

// =============================================================================
// EController::GetDirectionModifier - 0x80305D68 (24 bytes)
// Returns direction modifier for given axis/stick.
// =============================================================================
// int EController::GetDirectionModifier(int axis, int stick) {
//     u32* dirs = (u32*)((u8*)this + 0x194);
//     return dirs[axis + stick * 2];
// }


// ############################################################################
//
//  SECTION 5: EControllerManager - Multi-Controller Management
//
//  Manages up to 4 controllers and player-to-controller mappings.
//
//  Layout:
//    0x000-0x00F: u32 m_controllerIndex[4] - which controller each player uses
//    0x010-0x01F: u32 m_playerMapped[4]    - is player mapped (0/1)
//    0x020+:      controller objects array
//    0x208:       u32 m_controllerCount
//
// ############################################################################

// =============================================================================
// EControllerManager::GetControllerCount - 0x80323AF0 (8 bytes)
// Always returns 4 (hardcoded for GameCube).
// =============================================================================
// int EControllerManager::GetControllerCount(void) {
//     return 4;
// }

// =============================================================================
// EControllerManager::Shutdown - 0x8032344C (4 bytes)
// Empty stub (blr only).
// =============================================================================
// void EControllerManager::Shutdown(void) {
//     // empty
// }

// =============================================================================
// EControllerManager::MapPlayerToController - 0x80323450 (24 bytes)
// Maps a player slot to a controller index:
//   m_controllerIndex[player] = controller
//   m_playerMapped[player] = 1
// =============================================================================
// void EControllerManager::MapPlayerToController(unsigned int player, unsigned int controller) {
//     u32* indices = (u32*)this;       // offset 0x00
//     u32* mapped  = indices + 4;      // offset 0x10
//     indices[player] = controller;
//     mapped[player] = 1;
// }

// =============================================================================
// EControllerManager::UnmapPlayer - 0x803235CC (20 bytes)
// Clears player mapping: m_playerMapped[player] = 0.
// =============================================================================
// void EControllerManager::UnmapPlayer(unsigned int player) {
//     u32* mapped = (u32*)((u8*)this + 0x10);
//     mapped[player] = 0;
// }

// =============================================================================
// EControllerManager::GetPlayerMapped - 0x803235E0 (16 bytes)
// Returns whether a player has a controller mapped.
// =============================================================================
// unsigned int EControllerManager::GetPlayerMapped(unsigned int player) {
//     u32* mapped = (u32*)((u8*)this + 0x10);
//     return mapped[player];
// }

// =============================================================================
// EControllerManager::GetPlayerControllerIndex - 0x80323610 (28 bytes)
// Returns the controller index for a player, or -1 if player > 3.
// =============================================================================
// int EControllerManager::GetPlayerControllerIndex(unsigned int player) {
//     if (player > 3) return -1;
//     u32* indices = (u32*)this;
//     return indices[player];
// }

// =============================================================================
// EControllerManager::IndexToBit - 0x80324534 (12 bytes)
// Converts index to bitmask: returns (1 << index).
// =============================================================================
// unsigned int EControllerManager::IndexToBit(int index) {
//     return 1 << index;
// }


// ############################################################################
//
//  SECTION 6: EWindow - 2D Window/Viewport System
//
//  Base class for the windowing system. Manages input/output coordinate
//  transforms, clipping, scissoring, and render surface binding.
//
//  Layout (2308 bytes / 0x904):
//    0x000: ERenderSurface* m_renderSurface
//    0x004-0x00C: f32 screenshot scale factors
//    0x040: TRect<float> m_inputCoords   - logical input rect
//    0x050: TRect<float> m_outputCoords  - screen output rect
//    0x060: TRect<float> m_clip          - clip rect
//    0x070: TRect<float> m_clipInv       - inverse clip rect
//    0x080-0x08C: f32 viewport transform cache
//    0x090: u32 m_renderSurfaceRef
//    0x094: u32 m_renderSurfaceRef2
//    0x098: u32 m_flags
//    0x09C: u32 m_windowMatFlags
//
//  Static members:
//    m_pCurrentWindow:  EWindow* - currently active window
//    m_pCurrent3DWindow: E3DWindow* - currently active 3D window
//    m_globalScale: EVec3 - global scale multiplier
//    m_globalOffset: EVec3 - global offset
//
// ############################################################################

// =============================================================================
// EWindow::GetCurrentWindow - 0x80300AE8 (8 bytes)
// Returns static pointer to current window (from SDA register r13).
// =============================================================================
// EWindow* EWindow::GetCurrentWindow(void) {
//     return m_pCurrentWindow;
// }

// =============================================================================
// EWindow::GetCurrent3DWindow - 0x80300AF0 (8 bytes)
// Returns static pointer to current 3D window.
// =============================================================================
// E3DWindow* EWindow::GetCurrent3DWindow(void) {
//     return m_pCurrent3DWindow;
// }

// =============================================================================
// EWindow::Cast3DWindow - 0x80300B04 (8 bytes)
// Base class returns NULL (not a 3D window).
// =============================================================================
// E3DWindow* EWindow::Cast3DWindow(void) {
//     return NULL;
// }

// =============================================================================
// EWindow::WindowMatrixChanged - 0x80300AF8 (4 bytes)
// Virtual empty stub. Subclasses override to respond to matrix changes.
// =============================================================================
// void EWindow::WindowMatrixChanged(void) {
//     // empty
// }

// =============================================================================
// EWindow::InputCoordinatesChanged - 0x80300AFC (4 bytes)
// Virtual empty stub.
// =============================================================================
// void EWindow::InputCoordinatesChanged(void) {
//     // empty
// }

// =============================================================================
// EWindow::OutputCoordinatesChanged - 0x80300B00 (4 bytes)
// Virtual empty stub.
// =============================================================================
// void EWindow::OutputCoordinatesChanged(void) {
//     // empty
// }


// ############################################################################
//
//  SECTION 7: E3DWindow - 3D Viewport/Camera Window
//
//  Extends EWindow with 3D projection, frustum culling, world transforms.
//
//  Layout (840+ bytes / 0x348+):
//    0x000-0x03F: projection parameters (near, far, fov, aspect etc.)
//    0x0A0: EMat4 m_lookAtMatrix (64 bytes)
//    0x0E0: EMat4 m_lookAtPosMatrix (64 bytes)
//    0x160: EMat4 m_projectionMatrix (64 bytes)
//    0x1A0: EMat4 m_combinedMatrix (64 bytes)
//    0x1E0: EMat4 m_normalizedProjection (64 bytes)
//    0x220: TRect<float> m_viewport (16 bytes)
//    0x230: TRect<float> m_viewportInv (16 bytes)
//    0x240+: viewport transform cache, frustum planes
//    0x280: EVec3 m_lookPos (12 bytes)
//    0x290: EVec3 m_lookDir (12 bytes)
//    0x2A0-0x2F8: frustum planes (6 planes x 4 floats)
//    0x2FC-0x319: frustum clip flags (bytes)
//    0x31C: u32 m_frustumType
//
// ############################################################################

// =============================================================================
// E3DWindow::Cast3DWindow - 0x802E76A4 (4 bytes)
// Override returns this (it IS a 3D window). Returns via r3 (this ptr).
// =============================================================================
// E3DWindow* E3DWindow::Cast3DWindow(void) {
//     return this;  // blr - just returns r3 which is already 'this'
// }

// =============================================================================
// E3DWindow::GetLookPos - 0x802E767C (8 bytes)
// Returns pointer to look position at offset 0x280.
// =============================================================================
// EVec3* E3DWindow::GetLookPos(void) {
//     return (EVec3*)((u8*)this + 0x280);
// }

// =============================================================================
// E3DWindow::GetLookDir - 0x802E7684 (8 bytes)
// Returns pointer to look direction at offset 0x290.
// =============================================================================
// EVec3* E3DWindow::GetLookDir(void) {
//     return (EVec3*)((u8*)this + 0x290);
// }

// =============================================================================
// E3DWindow::GetLookAt - 0x802E768C (8 bytes)
// Returns pointer to look-at matrix at offset 0x0A0.
// =============================================================================
// EMat4* E3DWindow::GetLookAt(void) {
//     return (EMat4*)((u8*)this + 0x0A0);
// }

// =============================================================================
// E3DWindow::GetProjection - 0x802E7694 (8 bytes)
// Returns pointer to projection matrix at offset 0x160.
// =============================================================================
// EMat4* E3DWindow::GetProjection(void) const {
//     return (EMat4*)((u8*)this + 0x160);
// }

// =============================================================================
// E3DWindow::GetNormalizedProjection - 0x802E769C (8 bytes)
// Returns pointer to normalized projection matrix at offset 0x1E0.
// =============================================================================
// EMat4* E3DWindow::GetNormalizedProjection(void) const {
//     return (EMat4*)((u8*)this + 0x1E0);
// }

// =============================================================================
// E3DWindow::GetViewport - 0x802E7650 (44 bytes)
// Copies viewport rect to output.
// =============================================================================


// ############################################################################
//
//  SECTION 8: EStream - Serialization Stream
//
//  Base class for reading/writing structured data. Wraps EFile with
//  EStorable object serialization support.
//
//  Layout (72 bytes / 0x48):
//    0x000: u32 m_structureNestCount - current nesting depth (0 = not streaming)
//    0x004-0x014: write state
//    0x018: vtable for read/write operations
//    0x01C-0x044: version/header info for read operations
//
// ############################################################################

// =============================================================================
// EStream::EStream - 0x802D27EC (28 bytes)
// Constructor: sets vtable pointer at offset 0x18, clears nest count.
// =============================================================================
// EStream::EStream(void) {
//     *(void**)((u8*)this + 0x18) = &EStream_vtable;
//     *(u32*)this = 0;  // m_structureNestCount = 0
// }

// =============================================================================
// EStream::GetFile - 0x802D21F8 (8 bytes)
// Base class returns NULL (no backing file).
// Subclasses (EMemoryReadStream, etc.) override to return their file.
// =============================================================================
// EFile* EStream::GetFile(void) {
//     return NULL;
// }

// =============================================================================
// EStream::IsStreamingStructure - 0x802D283C (8 bytes)
// Returns true if currently inside a WriteStructure/ReadStructure call.
// Checks m_structureNestCount at offset 0x00.
// =============================================================================
// bool EStream::IsStreamingStructure(void) {
//     return *(u32*)this != 0;
// }


// ############################################################################
//
//  SECTION 9: EFile - Abstract File I/O
//
//  Base class for file I/O. Provides device/access/mode management,
//  name handling, and virtual read/write/seek interface.
//
//  Layout (44 bytes / 0x2C):
//    0x000: u32 m_flags
//    0x004: u32 m_field_004
//    0x008: EFile::IOMode m_ioMode        - read/write/append
//    0x00C: EFile::AccessMode m_accessMode - sequential/random
//    0x010: EFile::DeviceType m_deviceType - dvd/memcard/etc
//    0x014: u32 m_length                   - file size
//    0x018: char m_drive[4]                - drive letter/prefix
//    0x01C: char* m_path                   - allocated path string
//    0x020: char* m_name                   - allocated name string
//    0x024: char m_ext[4]                  - file extension
//    0x028: void* m_vtable_or_handle       - vtable ptr / system handle
//
//  Enums:
//    IOMode: { Read, Write, Append, ... }
//    AccessMode: { Sequential, Random }
//    DeviceType: { DVD=0x80000000, MemCard, HostFS, ... }
//    SeekType: { SeekSet, SeekCur, SeekEnd }
//
//  Static: m_bSimulateError (at SDA offset)
//
// ############################################################################

// =============================================================================
// EFile::EFile - 0x802C6048 (68 bytes)
// Constructor: initializes all fields to zero/defaults.
//   m_deviceType = 0x80000000 (DVD default)
//   m_accessMode = 0x80000000
//   m_vtable = EFile_vtable
// =============================================================================
// (See disassembly above - stores vtable, zeros fields)

// =============================================================================
// EFile::SetErrorSimulation - 0x802C60FC (8 bytes)
// Static method: sets global error simulation flag via SDA register.
// =============================================================================
// void EFile::SetErrorSimulation(bool enable) {
//     m_bSimulateError = enable;
// }

// =============================================================================
// EFile::GetIOMode - 0x802C690C (8 bytes)
// =============================================================================
// EFile::IOMode EFile::GetIOMode(void) const { return m_ioMode; }        // offset 0x08

// =============================================================================
// EFile::GetAccessMode - 0x802C6914 (8 bytes)
// =============================================================================
// EFile::AccessMode EFile::GetAccessMode(void) const { return m_accessMode; }  // offset 0x0C

// =============================================================================
// EFile::GetDeviceType - 0x802C691C (8 bytes)
// =============================================================================
// EFile::DeviceType EFile::GetDeviceType(void) const { return m_deviceType; }  // offset 0x10

// =============================================================================
// EFile::GetDrive - 0x802C6924 (8 bytes)
// Returns pointer to inline drive string at offset 0x18.
// =============================================================================
// const char* EFile::GetDrive(void) const { return (const char*)((u8*)this + 0x18); }

// =============================================================================
// EFile::GetPath - 0x802C692C (8 bytes)
// Returns allocated path string pointer at offset 0x1C.
// =============================================================================
// const char* EFile::GetPath(void) const { return m_path; }  // offset 0x1C

// =============================================================================
// EFile::GetName - 0x802C6934 (8 bytes)
// Returns allocated name string pointer at offset 0x20.
// =============================================================================
// const char* EFile::GetName(void) const { return m_name; }  // offset 0x20

// =============================================================================
// EFile::GetExt - 0x802C693C (8 bytes)
// Returns pointer to inline extension at offset 0x24.
// =============================================================================
// const char* EFile::GetExt(void) const { return (const char*)((u8*)this + 0x24); }

// =============================================================================
// EFile::GetLength - 0x802C6944 (8 bytes)
// Returns file length at offset 0x14.
// =============================================================================
// unsigned int EFile::GetLength(void) const { return m_length; }  // offset 0x14

// =============================================================================
// EFile::SetDevice - 0x802C694C (8 bytes)
// =============================================================================
// void EFile::SetDevice(EFile::DeviceType type) { m_deviceType = type; }  // offset 0x10

// =============================================================================
// EFile::SetAccess - 0x802C6954 (8 bytes)
// =============================================================================
// void EFile::SetAccess(EFile::AccessMode mode) { m_accessMode = mode; }  // offset 0x0C

// =============================================================================
// EFile::SetMode - 0x802C695C (8 bytes)
// =============================================================================
// void EFile::SetMode(EFile::IOMode mode) { m_ioMode = mode; }  // offset 0x08

// =============================================================================
// EFile::Allocate - 0x802C6904 (8 bytes)
// Base class returns NULL (no allocation support).
// =============================================================================
// void* EFile::Allocate(unsigned int& size) { return NULL; }


// ############################################################################
//
//  SECTION 10: EDummyFile - Null/No-Op File Implementation
//
//  A dummy file that discards writes, returns the requested size for reads,
//  and tracks a virtual seek position. Used for size calculation passes
//  (write everything to /dev/null to measure output size).
//
//  Inherits from EFile.
//  Additional field at offset 0x2C: u32 m_position (virtual seek position)
//
// ############################################################################

// =============================================================================
// EDummyFile::Read - 0x80022684 (8 bytes)
// Returns the requested size (pretends all bytes were read).
// =============================================================================
// unsigned int EDummyFile::Read(void* buffer, unsigned int size) {
//     return size;  // mr r3,r5
// }

// =============================================================================
// EDummyFile::Write - 0x8002268C (8 bytes)
// Returns the requested size (pretends all bytes were written).
// Used for serialization size measurement.
// =============================================================================
// unsigned int EDummyFile::Write(void* buffer, unsigned int size) {
//     return size;  // mr r3,r5
// }

// =============================================================================
// EDummyFile::Seek - 0x80022694 (12 bytes)
// Stores position at offset 0x2C, returns new position.
// Note: ignores SeekType (always absolute seek).
// =============================================================================
// int EDummyFile::Seek(int position, EFile::SeekType type) {
//     m_position = position;
//     return position;
// }

// =============================================================================
// EDummyFile::Tell - 0x800226A0 (8 bytes)
// Returns current virtual position from offset 0x2C.
// =============================================================================
// int EDummyFile::Tell(void) const {
//     return m_position;
// }

// =============================================================================
// EDummyFile::Flush - 0x800226A8 (8 bytes)
// Always returns 1 (success).
// =============================================================================
// bool EDummyFile::Flush(void) {
//     return true;
// }

// =============================================================================
// EDummyFile::GetLastError - 0x800226B0 (8 bytes)
// Always returns 0 (no error).
// =============================================================================
// int EDummyFile::GetLastError(void) const {
//     return 0;
// }

// =============================================================================
// EDummyFile::GetSystemHandle - 0x800226B8 (8 bytes)
// Returns NULL (no real file handle).
// =============================================================================
// void* EDummyFile::GetSystemHandle(void) const {
//     return NULL;
// }

// =============================================================================
// EDummyFile::Destroy - 0x800226C0 (4 bytes)
// Empty stub (blr). The file has nothing to destroy.
// =============================================================================
// void EDummyFile::Destroy(void) {
//     // empty
// }


// ############################################################################
//
//  SECTION 11: Summary of Coordinate Systems and Conventions
//
// ############################################################################

/*
 * ============================================================================
 * EMat4 Coordinate System (Row-Major)
 * ============================================================================
 *
 * The matrix is stored as m[row][col] in row-major order:
 *
 *   | m[0][0]  m[0][1]  m[0][2]  m[0][3] |   | Xx  Xy  Xz  0  |
 *   | m[1][0]  m[1][1]  m[1][2]  m[1][3] | = | Yx  Yy  Yz  0  |
 *   | m[2][0]  m[2][1]  m[2][2]  m[2][3] |   | Zx  Zy  Zz  0  |
 *   | m[3][0]  m[3][1]  m[3][2]  m[3][3] |   | Tx  Ty  Tz  1  |
 *
 * Where:
 *   Column 0 = local X axis (right)
 *   Column 1 = local Y axis (up)
 *   Column 2 = local Z axis (forward/look)
 *   Row 3    = translation
 *
 * Matrix operations:
 *   PreScale:    scales the rotation part (rows 0-2)
 *   PostScale:   scales each column independently
 *   PreTranslate: translates in local space (through rotation)
 *   PostTranslate: translates in world space (adds to row 3)
 *
 * Euler angles (GetHPR):
 *   Heading: rotation around Y (vertical) axis
 *   Pitch:   rotation around X (lateral) axis
 *   Roll:    rotation around Z (forward) axis
 *   Convention: Y-up, Z-forward, right-handed
 *
 * ============================================================================
 * CTilePt Isometric Grid
 * ============================================================================
 *
 * The tile grid uses an isometric diamond layout:
 *
 *        North (row-)
 *          /\
 *   West / /\ \ East
 *  (col-)/ /  \ \(col+)
 *        \ \  / /
 *         \ \/ /
 *          \/
 *        South (row+)
 *
 * Tile coordinates (m_x, m_y) map to isometric axes:
 *   Row    = m_x + m_y  (NW-SE diagonal)
 *   Column = m_x - m_y  (NE-SW diagonal)
 *
 * World space conversion (tile -> world):
 *   world_x = tile_x * 16 + 8   (center of tile)
 *   world_z = tile_y * 16 + 8
 *   world_y = level * level_height
 *
 * ============================================================================
 * EFile Device Types
 * ============================================================================
 *
 * DeviceType constants (u32):
 *   0x80000000 = DVD / optical disc (default)
 *   Others TBD (memcard, host filesystem)
 *
 * IOMode: Read, Write, Append
 * AccessMode: Sequential, Random
 * SeekType: Set(0), Current(1), End(2)
 *
 * ============================================================================
 * EController Button/Command System
 * ============================================================================
 *
 * The controller uses a two-layer input system:
 *   1. Buttons: Physical buttons identified by bitmask
 *   2. Commands: Logical actions mapped from buttons via EBtnToCmdAssoc
 *
 * Button states: Down, Pressed (just pressed), Released, Up, Repeat
 * Commands: Same states but abstracted through command maps
 *
 * Filters: Named input filter stacks that can mask buttons/commands
 *   per UI layer (e.g., dialog blocks gameplay input).
 *
 * Sticks: 2 analog sticks, each with X/Y axes
 *   - m_axesSwapped[]: per-stick axis swap toggle
 *   - m_dirModifier[][]: per-axis direction inversion (-1/+1)
 *
 * Vibration: Two motors (one/two) with strength + duration
 *   - NGC build: HasVibration() returns false (no rumble on GC)
 *   - Motor state is tracked but not applied on this platform
 */
