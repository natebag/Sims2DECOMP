struct LightArray {
    char _pad[0xD00];
    int m_initialized;
    void Init();
};
void LightArray::Init() { m_initialized = 0; }
