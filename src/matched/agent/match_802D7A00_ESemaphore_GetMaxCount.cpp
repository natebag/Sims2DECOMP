struct ESemaphore_GMC {
    char pad[0x08];
    int m_maxCount;
    int GetMaxCount();
};

int ESemaphore_GMC::GetMaxCount() {
    return m_maxCount;
}
