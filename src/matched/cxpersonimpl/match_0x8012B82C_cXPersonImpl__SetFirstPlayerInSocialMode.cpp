// 0x8012B82C cXPersonImpl::SetFirstPlayerInSocialMode (8B)

struct cXPerson_SetFirstPlayerInSocialMode {
    char pad[0x544];
    int m_val;
    void SetFirstPlayerInSocialMode(int v);
};

void cXPerson_SetFirstPlayerInSocialMode::SetFirstPlayerInSocialMode(int v) {
    m_val = v;
}
