// FLAGS: -fno-schedule-insns
// 0x801C8720 MMUTarget::OnDialogClose(int) (104B)

struct G_B_struct {
    char pad[0x84];
    int m_84;
    char pad88[0x68];
    int m_F0;
};
extern G_B_struct g_b;  // at 0x80475B84

struct G_D_struct {
    char pad[0x448];
    int m_448;
    int m_44C;
};
extern G_D_struct g_d;  // at 0x80475DCC

extern void SetupCAS();

class MMUTarget {
public:
    void OnStartGameComplete(bool b);
    void OnDialogClose(int code);
};

void MMUTarget::OnDialogClose(int code) {
    if (code != 1) return;
    g_b.m_84 = code;
    g_b.m_F0 = 0;
    SetupCAS();
    g_d.m_44C = 0;
    g_d.m_448 = code;
    OnStartGameComplete(true);
}
