// 0x8022BE08 EIStaticModel::SetModel(unsigned int, bool, EInstance*, EAnimController*) (60B)

struct EInstance {};
struct EAnimController {};

class EIStaticModel {
    char _pad14[0x14];
    int m_field14;
    char _pad15[0xf8];
    unsigned int m_field110;
    char _padx[0x10];
    bool m_field124;
public:
    void Setup(EInstance* inst, EAnimController* anim);
    void SetModel(unsigned int id, bool flag, EInstance* inst, EAnimController* anim);
};

void EIStaticModel::SetModel(unsigned int id, bool flag, EInstance* inst, EAnimController* anim) {
    m_field110 = id;
    m_field124 = flag;
    m_field14 = 0;
    Setup(inst, anim);
}
