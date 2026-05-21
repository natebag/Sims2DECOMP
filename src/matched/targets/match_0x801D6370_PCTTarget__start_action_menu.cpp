// 0x801D6370 PCTTarget::start_action_menu(void) (72B)
// TRIAGE

class HUDTarget;

class ActionMenu {
public:
    static int Start(HUDTarget* t, int p1, int p2);
};

extern struct GameData {
    char pad_00[68];
    int field68;  // at 0x80475BC8
} _gd;

class PCTTarget {
public:
    char pad_000[132];
    int  m_param;          // 132
    char pad_088[92];
    HUDTarget* m_target;   // 228
    int start_action_menu();
};

int PCTTarget::start_action_menu() {
    HUDTarget* t = m_target;
    if (t == 0) return 0;
    ActionMenu::Start(t, _gd.field68, m_param);
    return 1;
}
