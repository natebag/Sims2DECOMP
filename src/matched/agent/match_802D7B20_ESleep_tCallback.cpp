struct Inner_tCB {
    void callback();
};
struct ESleep_tCB {
    char pad[0x04];
    Inner_tCB* m_inner;
};
void ESleep_tCallback(ESleep_tCB* alarm, void* ctx) {
    alarm->m_inner->callback();
}
