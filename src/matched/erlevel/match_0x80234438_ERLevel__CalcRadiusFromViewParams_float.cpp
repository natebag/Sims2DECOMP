// 0x80234438 ERLevel::CalcRadiusFromViewParams(float, float, float) (120 B)

extern char lbl_803FF4D8[];
extern char lbl_803FF4DC[];
extern float tanf(float);
struct Vec3 { float x, y, z; };
extern float PSVECMag(Vec3* v);
struct ERLevel { float CalcRadiusFromViewParams(float a, float b, float c); };

float ERLevel::CalcRadiusFromViewParams(float a, float b, float c) {
    float k0 = *(float*)lbl_803FF4D8;
    float fb = b;
    float k1 = *(float*)lbl_803FF4DC;
    Vec3 v;
    Vec3* p = &v;
    float x = a * k0;
    float fc = c;
    float t = tanf(x * k1);
    float y = t * fb;
    v.y = y;
    v.x = y * fc;
    p->z = fb;
    return PSVECMag(p);
}
