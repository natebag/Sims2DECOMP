// FLAGS: -fno-schedule-insns
// LoadGameTarget::ZeroInputCallback(void) @ 0x8018A6BC (76B)

struct LGT_ZIC {
    char _pad[300];
    int m_state;
    int m_flag;
    void ZeroInputCallback();
};

void LGT_ZIC::ZeroInputCallback() {
    int state = m_state;
    if (state == 4) goto set_flag;
    else if (state > 4) goto check_large;
    if (state == 0) goto set_both;
    return;
check_large:
    if (state == 19) goto set_flag;
    if (state == 24) goto set_flag;
    return;
set_both:
    m_flag = 1;
    m_state = 1;
    return;
set_flag:
    m_flag = 1;
}
