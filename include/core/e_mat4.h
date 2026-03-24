#ifndef E_MAT4_H
#define E_MAT4_H

#include "types.h"

// Forward declarations
class EVec3;
class EVec4;
class EQuat;

// EMat4 - 4x4 matrix (64 bytes, row-major: m[row][col])
// Layout: 4 rows of 4 floats = 16 floats
// Row 0: m[0x00..0x0C]
// Row 1: m[0x10..0x1C]
// Row 2: m[0x20..0x2C]
// Row 3: m[0x30..0x3C] (translation in last row)
class EMat4 {
public:
    float m[4][4]; // 0x00 - 64 bytes

    void Mult4x4(EMat4& a, EMat4& b);
    void PreScale(float scale);
    void PreScale(EVec3& v);
    void PostScale(float scale);
    void PostScale(EVec3& v);
    void PostTranslate(EVec3& v);
    void PostTranslate(float x, float y, float z);
    void PreTranslate(EVec3& v);
    void PreTranslate(float x, float y, float z);

    void GetColumn(int col, EVec3& out);
    void GetColumn(int col, EVec4& out);
    void SetColumn(int col, EVec3& in);
    void SetColumn(int col, EVec4& in);

    float GetScaleX();
    float GetScaleY();
    float GetScaleZ();
    float GetMaxScale() const;

    EMat4& operator=(EMat4& other);
    EMat4& operator=(float val);

    void Normalize(void);
    void Transpose(EMat4& src);
    void Transpose(void);
    void Id(void);
    void Translate(EVec3& v);
    void Translate(float x, float y, float z);
    void Scale(EVec3& v);
    void Scale(float scale);
    void Scale(float x, float y, float z);
    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void Clamp(void);
    void GetHPR(float& heading, float& pitch, float& roll);
    void OrientPosNormal(EVec3& pos, EVec3& unused, EVec3& normal);
    void LookAtDirect(EVec3& target, EVec3& up, float scale);

    void ExtractAxisRotation(EVec3& axis) const;
    void Print() const;
};

// EVec4 - 4D vector (16 bytes)
struct EVec4 {
    float x, y, z, w;
    void Print();
};

// EQuat - quaternion (16 bytes)
class EQuat {
public:
    float x, y, z, w;
    void Print();
};

// EVec3Decomp
class EBitArray;
class EVec3Decomp {
public:
    u8 pad00[0x18];     // 0x00
    int m_numComponents; // 0x18
    s16 m_bitsPerComp;  // 0x1C

    static void Init(EBitArray* arr, int bits);
    int GetBitCount();
};

// EEngine
class ERLevel;
class EEngine {
public:
    u8 pad00[0x30];     // 0x00
    ERLevel* m_currentLevel; // 0x30

    void ClearCurrentLevel(ERLevel* level);
    void SetCurrentLevel(ERLevel* level);
};

// EGraphics extensions from e_quat.obj
class EGraphics;
void EGraphics_SetBackgroundColor(EGraphics* g, EVec3& color, int idx, bool flag);
void EGraphics_GetBackgroundColor(EGraphics* g, EVec3& color, int& outIdx);
void EGraphics_SetTint(EGraphics* g, EVec3& a, EVec3& b);
void EGraphics_GetTint(EGraphics* g, EVec3& a, EVec3& b);

#endif // E_MAT4_H
