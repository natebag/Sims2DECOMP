struct ESemaphore_D {
    char pad[0x04];
    int m_handle;
    void Destroy();
};
void ESemaphore_D::Destroy() {
    m_handle = 0;
}
