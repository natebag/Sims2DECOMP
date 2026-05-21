// 0x800CAAC8 Neighbor::InitWantFearIcons(void) (88B)

struct GameData {
    char pad[0x48];
    void* m_wantFearHUD;
};
extern GameData _gd;

class Neighbor {
    void UpdateUIifNeeded(unsigned int slot, int val);
public:
    void InitWantFearIcons();
};

void Neighbor::InitWantFearIcons() {
    if (_gd.m_wantFearHUD != 0) {
        for (unsigned int i = 0; i <= 6; i++) {
            UpdateUIifNeeded(i, 3);
        }
    }
}
