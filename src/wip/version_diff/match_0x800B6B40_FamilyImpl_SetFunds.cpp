// 0x800B6B40 FamilyImpl::SetFunds (40B - includes adjacent getter)
// DOL:
//   lis r0,15; ori r0,r0,16959   ; r0 = 999999
//   cmpw r4, r0
//   bgt fwd                       ; if funds > max, fwd
//   stw r4, 20(r3)                ; INLINE: m_funds = funds
//   blr
// fwd:
//   stw r0, 20(r3)                ; m_funds = max
//   blr
//   lwz r3, 24(r3)                ; getter at +32
//   blr

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
