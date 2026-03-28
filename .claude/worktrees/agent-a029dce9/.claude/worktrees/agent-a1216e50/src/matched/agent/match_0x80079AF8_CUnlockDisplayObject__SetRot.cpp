/* 0x80079AF8 (32 bytes) - CUnlockDisplayObject::SetRot(EVec3 &) */
struct EVec3 { int x, y, z; };

class CUnlockDisplayObject {
public:
    char pad[0x48];
    EVec3 m_rot;
    void SetRot(EVec3 &v);
};

void CUnlockDisplayObject::SetRot(EVec3 &v) {
    m_rot = v;
}
