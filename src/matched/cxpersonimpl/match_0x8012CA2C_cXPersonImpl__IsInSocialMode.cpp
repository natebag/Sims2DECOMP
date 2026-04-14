// 0x8012CA2C cXPersonImpl::IsInSocialMode (24B)

struct cXPerson_IsInSocialMode {
    char pad[0x58];
    short m_val;
    int IsInSocialMode();
};

int cXPerson_IsInSocialMode::IsInSocialMode() {
    short v = m_val;
    int result = 1;
    if (v == 0) result = 0;
    return result;
}
