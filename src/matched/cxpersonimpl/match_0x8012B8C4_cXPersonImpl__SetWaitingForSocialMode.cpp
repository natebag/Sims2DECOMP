// 0x8012B8C4 cXPersonImpl::SetWaitingForSocialMode (8B)

struct cXPerson_SetWaitingForSocialMode {
    char pad[0x54C];
    int m_val;
    void SetWaitingForSocialMode(int v);
};

void cXPerson_SetWaitingForSocialMode::SetWaitingForSocialMode(int v) {
    m_val = v;
}
