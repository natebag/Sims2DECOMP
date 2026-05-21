// 0x801B7040 G2DTarget::CheckPlayerInput(char*) (76B)
// TRIAGE

class G2DTarget {
public:
    char pad_00[156];
    int  m_state;
    char pad_A0[4];
    int  m_enabled;
    int CheckPlayerInput(char* input);
};

int G2DTarget::CheckPlayerInput(char* input) {
    if (m_enabled == 0) return 0;
    int c = (unsigned char)*input;
    if ((unsigned int)(c - 48) > 1u) return 0;
    int v = (int)(signed char)c - 48;
    int state = m_state;
    int r;
    if (v == state) goto match;
    r = 0;
    if (state != 2) goto end;
match:
    r = 1;
end:
    return r;
}
