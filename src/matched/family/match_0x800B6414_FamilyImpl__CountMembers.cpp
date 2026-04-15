/* FamilyImpl::CountMembers(void) - 0x800B6414 (20 bytes) */

struct MemberPtr { char data[4]; };
class FamilyImpl {
public:
    char pad0[36];
    MemberPtr* m_begin;  // +36
    MemberPtr* m_end;    // +40

    int CountMembers(void);
};

int FamilyImpl::CountMembers(void) {
    return m_end - m_begin;
}
