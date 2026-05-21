// 0x80306CC8 (24B) blendFloat(float, float, float)

extern float blendFloat_one[3];  // 0x8041FACC

float blendFloat(float a, float b, float t) {
    return b * t + (blendFloat_one[0] - t) * a;
}
