// 0x8012CA4C cXPersonImpl::IsFirstPlayerInSocialMode (8B)

struct cXPerson_IsFirstPlayerInSocialMode {
    char pad[0x544];
    int m_val;
    int IsFirstPlayerInSocialMode();
};

int cXPerson_IsFirstPlayerInSocialMode::IsFirstPlayerInSocialMode() {
    return m_val;
}
