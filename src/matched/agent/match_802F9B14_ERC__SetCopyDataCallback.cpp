class ERC {
public:
    char m_pad[84];
    void (*m_copyDataCallback)(void *, void *);
    void *m_copyDataUserData;
    void SetCopyDataCallback(void (*)(void *, void *), void *);
};
void ERC::SetCopyDataCallback(void (*callback)(void *, void *), void *userData) {
    m_copyDataCallback = callback;
    m_copyDataUserData = userData;
}
