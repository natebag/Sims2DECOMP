// 0x801C81E0 MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMUState) (72B)
// FLAGS: -fno-schedule-insns
// DOL: li r3,0 appears immediately after lwz (before first cmpwi) — scheduler must be suppressed
// chain: kind==1→3, kind==2→0, kind==3→0, kind==4→2, kind==0→0, default→2
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
    if (kind == 0) return result;
    return 2;
}
