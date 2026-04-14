struct WallManip {
    char pad[196]; int m_flags;
    char pad2[16]; int* m_shaderPtr;
    int GetFenceShaderID();
};
int WallManip::GetFenceShaderID() {
    if (!(m_flags & 256)) return 0;
    return *m_shaderPtr;
}
