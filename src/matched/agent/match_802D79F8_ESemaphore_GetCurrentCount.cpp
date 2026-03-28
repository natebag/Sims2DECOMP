struct ESemaphore_GCC {
    char pad[0x0C];
    int m_currentCount;
    int GetCurrentCount();
};

int ESemaphore_GCC::GetCurrentCount() {
    return m_currentCount;
}
