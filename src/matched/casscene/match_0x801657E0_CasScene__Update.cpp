// 0x801657E0 CasScene::Update(float) (68B)

extern void func_800A81D8(void* p);
extern int func_802343A0(void* p);

class CasScene {
public:
    char pad[0xA80];
    void* m_A80;
    char padA84[0x3C];
    void* m_AC0;
    void Update(float t);
    void UpdateCamera(float t);
};

void CasScene::Update(float t) {
    UpdateCamera(t);
    func_800A81D8(m_AC0);
    if (m_A80 != 0) {
        func_802343A0(m_A80);
    }
}
