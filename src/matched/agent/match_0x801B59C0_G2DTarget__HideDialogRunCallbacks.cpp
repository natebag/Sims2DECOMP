// 0x801B59C0 G2DTarget::HideDialogRunCallbacks() (68B)

extern "C" void G2DDummyPrintf(char* fmt, ...);
extern char fmt_HideDialog_803FD3C[];

class G2DTarget {
public:
    char pad[0x134];
    int m_state;
    void HideDialogRunCallbacks();
};

void G2DTarget::HideDialogRunCallbacks() {
    if (m_state == 3) goto set4;
    G2DDummyPrintf(fmt_HideDialog_803FD3C);
    return;
set4:
    m_state = 4;
}
