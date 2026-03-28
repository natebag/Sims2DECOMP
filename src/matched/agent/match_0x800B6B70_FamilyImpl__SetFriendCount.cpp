/* FamilyImpl::SetFriendCount(int) at 0x800B6B70 (16B) */

struct FamilyImpl {
    char pad[0x1C];
    int m_friendCount;
    int m_field20;

    void SetFriendCount(int count);
};

void FamilyImpl::SetFriendCount(int count) {
    m_friendCount = count;
    m_field20 = 0;
}
