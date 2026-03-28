/* 0x80053E08 (32 bytes) - ISimsObjectModel::SetDir(EVec3 &) */
struct EVec3 { int x, y, z; };

class ISimsObjectModel {
public:
    char pad[0x410];
    EVec3 m_dir;
    void SetDir(EVec3 &v);
};

void ISimsObjectModel::SetDir(EVec3 &v) {
    m_dir = v;
}
