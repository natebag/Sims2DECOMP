// 0x801C81E0 MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE) (72B)

class MMUTarget {
public:
    enum MMU_MENU_STATE { kS0 };
    char pad[0xB0];
    int m_B0;
    int GetNumberOfChoicesInState(MMU_MENU_STATE state);
};

int MMUTarget::GetNumberOfChoicesInState(MMU_MENU_STATE state) {
    int s = m_B0;
    int r = 0;
    if (s == 1) { r = 3; goto end; }
    if (s == 2) goto end;
    if (s == 3) goto end;
    if (s == 4) { r = 2; goto end; }
    if (s != 0) goto end;
    r = 2;
end:
    return r;
}
