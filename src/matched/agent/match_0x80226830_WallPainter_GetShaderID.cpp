struct ShaderObj {
    char _pad[0x08];
    int m_id;
};
struct WallPainter {
    char _pad[0x90];
    ShaderObj *m_shader;
    int GetShaderID();
};
int WallPainter::GetShaderID() { return m_shader->m_id; }
