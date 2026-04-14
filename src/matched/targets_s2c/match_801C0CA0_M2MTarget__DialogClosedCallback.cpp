/* M2MTarget::DialogClosedCallback(void) at 0x801C0CA0 (104B) */

struct UIDB {
    static void UIDBSetInt(char*, int);
};

extern char s_newGameStr[];

struct M2MTarget {
    char pad_000[0x11C];
    int m_field11C;
    char pad_120[0x168 - 0x120];
    int m_field168;

    void DialogClosedCallback();
    void HideWidget();
    void ReturnFailureDestination();
};

void M2MTarget::DialogClosedCallback() {
    if (m_field11C != 1) {
        if (m_field11C == 5) {
            UIDB::UIDBSetInt(s_newGameStr, 7);
            HideWidget();
            m_field168 = 3;
        }
    } else {
        ReturnFailureDestination();
    }
}
