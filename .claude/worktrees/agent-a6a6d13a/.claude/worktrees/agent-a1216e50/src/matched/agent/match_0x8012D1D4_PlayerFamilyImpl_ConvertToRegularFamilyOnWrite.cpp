/* PlayerFamilyImpl::ConvertToRegularFamilyOnWrite(void) - 0x8012D1D4 - 12 bytes */
/* li r0, 1; stw r0, 0xD64(r3); blr */

class PlayerFamilyImpl {
public:
    char _pad[0xD64];
    int m_convertToRegularFamilyOnWrite;

    void ConvertToRegularFamilyOnWrite(void);
};

void PlayerFamilyImpl::ConvertToRegularFamilyOnWrite(void) {
    m_convertToRegularFamilyOnWrite = 1;
}
