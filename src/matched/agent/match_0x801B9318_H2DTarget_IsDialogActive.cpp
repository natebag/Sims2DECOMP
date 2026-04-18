// 0x801B9318 (116B) H2DTarget::IsDialogActive(void)
class MDITarget {
public:
    int IsModelessDialogActive();
};

class G2DTarget {
public:
    int IsG2DActive();
};

extern char g_G2DTarget_mem[16];

struct H2DTarget {
    char pad[200];
    MDITarget* m_mdi;      // 200 (0xC8)
    int m_reward;          // 204 (0xCC)
    int IsDialogActive();
};

int H2DTarget::IsDialogActive() {
    int active = 0;
    if ((m_mdi != 0 && m_mdi->IsModelessDialogActive()) ||
        (*((G2DTarget**)g_G2DTarget_mem) != 0 && (*((G2DTarget**)g_G2DTarget_mem))->IsG2DActive()) ||
        m_reward != 0) {
        active = 1;
    }
    return active;
}
