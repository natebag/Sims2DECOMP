// ISimInstance::GetObCenter(void)
// Address: 0x80056738 | Size: 36 bytes
// Returns EVec3 by value (hidden return ptr in r3, this in r4)
// lfs f13, 256(r4); or r9,r3,r3; addi r4,r4,256; stfs f13,0(r9); lfs f0,4(r4); stfs f0,4(r9); lfs f13,8(r4); stfs f13,8(r9); blr

struct EVec3 {
    float x;
    float y;
    float z;
    EVec3() {}
    EVec3(const EVec3 &o) : x(o.x), y(o.y), z(o.z) {}
};

class ISimInstance {
public:
    char _pad[0x100];
    EVec3 m_obCenter;  // offset 0x100 (3 floats = 12 bytes)

    EVec3 GetObCenter(void);
};

EVec3 ISimInstance::GetObCenter(void) {
    return m_obCenter;
}
