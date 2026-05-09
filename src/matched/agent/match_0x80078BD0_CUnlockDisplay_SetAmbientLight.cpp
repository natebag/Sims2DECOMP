// 0x80078BD0 (56B) CUnlockDisplay::SetAmbientLight(float, float, float)
// Stage 3 floats on stack, read back as ints, store to this+848,852,856.

struct Color3 {
    float r, g, b;
};

class CUnlockDisplay {
public:
    char _pad[848];
    Color3 m_ambient;  // +848
    void SetAmbientLight(float r, float g, float b);
};

void CUnlockDisplay::SetAmbientLight(float r, float g, float b)
{
    Color3 c;
    c.r = r;
    c.g = g;
    Color3* p = &c;
    p->b = b;
    m_ambient = c;
}
