// 0x8012CA44 cXPersonImpl::IsSecondPlayerInSocialMode (8B)

struct cXPerson_IsSecondPlayerInSocialMode {
    char pad[0x548];
    int m_val;
    int IsSecondPlayerInSocialMode();
};

int cXPerson_IsSecondPlayerInSocialMode::IsSecondPlayerInSocialMode() {
    return m_val;
}
