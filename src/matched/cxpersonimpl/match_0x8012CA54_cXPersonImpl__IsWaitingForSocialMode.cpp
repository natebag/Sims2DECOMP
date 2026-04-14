// 0x8012CA54 cXPersonImpl::IsWaitingForSocialMode (8B)

struct cXPerson_IsWaitingForSocialMode {
    char pad[0x54C];
    int m_val;
    int IsWaitingForSocialMode();
};

int cXPerson_IsWaitingForSocialMode::IsWaitingForSocialMode() {
    return m_val;
}
