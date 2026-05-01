// 0x80079B5C CUnlockDisplayObject::GetRotAdd(void) (36 B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class CUnlockDisplayObject {
    char pad[0x54];
    EVec3 m_rotAdd;
public:
    EVec3 GetRotAdd(void);
};

EVec3 CUnlockDisplayObject::GetRotAdd(void) {
    return m_rotAdd;
}
