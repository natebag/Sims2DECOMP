/* FamilyImpl::SetFunds(int) - 0x800B6B40 (32 bytes) */

class FamilyImpl {
public:
    char pad[20];
    int m_funds;

    void SetFunds(int amount);
};

void FamilyImpl::SetFunds(int amount) {
    if (amount <= 999999) {
        m_funds = amount;
        return;
    }
    m_funds = 999999;
}
