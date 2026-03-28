class INVTarget {
public:
    char pad[0x108];
    int m_shaderLoaded[12];
    int SetIsShaderLoadedByIndex(int index, int value);
};

int INVTarget::SetIsShaderLoadedByIndex(int index, int value) {
    if ((unsigned int)index > 11) return 0;
    m_shaderLoaded[index] = value;
    return 1;
}
