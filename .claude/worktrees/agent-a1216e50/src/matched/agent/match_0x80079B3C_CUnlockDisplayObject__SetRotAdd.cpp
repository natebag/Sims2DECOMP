/* 0x80079B3C (32 bytes) - CUnlockDisplayObject::SetRotAdd(EVec3 &) */
struct EVec3 { int x, y, z; };

class CUnlockDisplayObject {
public:
    char pad[0x54];
    EVec3 m_rotAdd;
    void SetRotAdd(EVec3 &v);
};

void CUnlockDisplayObject::SetRotAdd(EVec3 &v) {
    m_rotAdd = v;
}
