// 0x801F04DC INVTarget::GetIsShaderLoadedByIndex(int) const (32B)

struct INVTarget {
    char pad000[0x108];
    void* m_shaderLoaded[12];   // 0x108
    void* GetIsShaderLoadedByIndex(int idx) const;
};

void* INVTarget::GetIsShaderLoadedByIndex(int idx) const {
    if ((unsigned int)idx > 11) return 0;
    return m_shaderLoaded[idx];
}
