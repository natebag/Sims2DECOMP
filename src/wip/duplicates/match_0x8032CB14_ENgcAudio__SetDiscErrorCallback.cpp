struct ENgcAudio {
    char _pad[0x3c];
    void *m_cb;
    void SetDiscErrorCallback(void *v);
};
void ENgcAudio::SetDiscErrorCallback(void *v) { m_cb = v; }
