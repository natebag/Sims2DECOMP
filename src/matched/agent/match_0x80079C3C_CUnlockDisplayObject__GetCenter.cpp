// 0x80079C3C CUnlockDisplayObject::GetCenter(void) (36 B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class CUnlockDisplayObject {
    char pad[0x60];
    EVec3 m_center;
public:
    EVec3 GetCenter(void);
};

EVec3 CUnlockDisplayObject::GetCenter(void) {
    return m_center;
}
