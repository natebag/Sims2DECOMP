// 0x801C81E0 MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE) (72B)
// DOL: preloads li r3,0 before first cmpwi; beqlr for case2+3; bnelr for !0 default
// state==0→2, state==1→3, state==2→0, state==3→0, state==4→2, other→0

struct MMUTarget {
    char _pad[0xB0];
    int m_stateKind;
    int GetNumberOfChoicesInState() const;
};

int MMUTarget::GetNumberOfChoicesInState() const {
    int kind = m_stateKind;
    int result = 0;
    if (kind == 1) return 3;
    if (kind == 2) return result;
    if (kind == 3) return result;
    if (kind == 4) return 2;
    if (kind != 0) return result;
    return 2;
}
