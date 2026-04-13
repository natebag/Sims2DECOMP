// FLAGS: -fno-schedule-insns
// 0x800B6B40 FamilyImpl::SetFunds (32B - includes adjacent getter)

struct FamilyImpl {
    char pad[20];
    int m_funds;     // offset 0x14
    int m_unknown;   // offset 0x18

    void SetFunds(int funds);
    int GetSomething();
};

void FamilyImpl::SetFunds(int funds) {
    int max = 999999;
    if (funds > max) {
        m_funds = max;
        return;
    }
    m_funds = funds;
}

int FamilyImpl::GetSomething() {
    return m_unknown;
}
