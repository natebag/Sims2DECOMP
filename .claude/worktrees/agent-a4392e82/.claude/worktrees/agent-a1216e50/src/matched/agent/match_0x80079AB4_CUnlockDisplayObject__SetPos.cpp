/* 0x80079AB4 (32 bytes) - CUnlockDisplayObject::SetPos(EVec3 &) */
struct EVec3 { int x, y, z; };

class CUnlockDisplayObject {
public:
    char pad[0x3C];
    EVec3 m_pos;
    void SetPos(EVec3 &v);
};

void CUnlockDisplayObject::SetPos(EVec3 &v) {
    m_pos = v;
}
