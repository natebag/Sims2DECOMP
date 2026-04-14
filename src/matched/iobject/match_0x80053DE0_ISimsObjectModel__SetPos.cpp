/* 0x80053DE0 (32 bytes) - ISimsObjectModel::SetPos(EVec3 &) */
struct EVec3 { int x, y, z; };

class ISimsObjectModel {
public:
    char pad[0x404];
    EVec3 m_pos;
    void SetPos(EVec3 &v);
};

void ISimsObjectModel::SetPos(EVec3 &v) {
    m_pos = v;
}
