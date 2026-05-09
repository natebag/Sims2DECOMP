// 0x80228100 (60B) EILight::GetPosition(EVec3&)
// Returns (0, 0, 0) via stack-staged zero float.

struct EVec3 {
    float x, y, z;
};

class EILight {
public:
    void GetPosition(EVec3& out);
};

void EILight::GetPosition(EVec3& out)
{
    EVec3 v;
    EVec3* p = &v;
    p->z = 0.0f;
    p->y = 0.0f;
    v.x = 0.0f;
    out = v;
}
