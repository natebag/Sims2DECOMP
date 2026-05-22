// 0x801C81E0 MMUTarget::GetNumberOfChoicesInState() (72B)
// DOL: li r3,0 preloaded; beqlr for case2+3; bnelr for catch-all
// state==0->2, state==1->3, state==2->0, state==3->0, state==4->2, other->0

struct MMUTarget {
    char _pad[0xB0];
    int m_stateKind;
    int GetNumberOfChoicesInState() const;
};

int MMUTarget::GetNumberOfChoicesInState() const {
    int kind = m_stateKind;
    int result = 0;
    switch (kind) {
        case 1: return 3;
        case 2: return result;
        case 3: return result;
        case 4: return 2;
        case 0: return 2;
    }
    return result;
}
