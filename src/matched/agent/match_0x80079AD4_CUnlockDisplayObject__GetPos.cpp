// 0x80079AD4 CUnlockDisplayObject::GetPos(void) (36 B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class CUnlockDisplayObject {
    char pad[0x3c];
    EVec3 m_pos;
public:
    EVec3 GetPos(void);
};

EVec3 CUnlockDisplayObject::GetPos(void) {
    return m_pos;
}
