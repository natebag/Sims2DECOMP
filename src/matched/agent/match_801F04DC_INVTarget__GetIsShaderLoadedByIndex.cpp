class INVTarget {
public:
    char pad[0x108];
    int m_shaderLoaded[12];
    int GetIsShaderLoadedByIndex(int index) const;
};

int INVTarget::GetIsShaderLoadedByIndex(int index) const {
    if ((unsigned int)index > 11) return 0;
    return m_shaderLoaded[index];
}
