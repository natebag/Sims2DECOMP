// 0x80079B18 CUnlockDisplayObject::GetRot(void) (36 B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class CUnlockDisplayObject {
    char pad[0x48];
    EVec3 m_rot;
public:
    EVec3 GetRot(void);
};

EVec3 CUnlockDisplayObject::GetRot(void) {
    return m_rot;
}
