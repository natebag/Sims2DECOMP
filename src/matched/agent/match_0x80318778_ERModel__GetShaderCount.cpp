/* ERModel::GetShaderCount(void) at 0x80318778 (52B) */

struct ERModel_ShaderEntry {
    int pad0;
    int count;
    int pad2[4];
};

struct ERModel_GSC {
    char _pad[60];
    ERModel_ShaderEntry* m_shaders;
    int m_count;
    int GetShaderCount();
};

int ERModel_GSC::GetShaderCount() {
    int total = 0;
    for (int i = 0; i < m_count; i++) {
        total += m_shaders[i].count;
    }
    return total;
}
