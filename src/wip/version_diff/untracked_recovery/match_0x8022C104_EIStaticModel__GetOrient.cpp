// 0x8022C104 EIStaticModel::GetOrient (136B)
// FLAGS: -fno-builtin

class EMat4 {
public:
    float m[4][4];
};

class EIStaticModel {
    char pad[192];
    EMat4 m_orient;
public:
    void GetOrient(EMat4& m);
};

void EIStaticModel::GetOrient(EMat4& m) {
    __builtin_memcpy(&m, &m_orient, sizeof(EMat4));
}
