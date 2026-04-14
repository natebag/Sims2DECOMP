// 0x80035338 ESim::GetSimModel (8B)

struct ESim_GetSimModel {
    char pad[0x63C];
    int m_val;
    int GetSimModel();
};

int ESim_GetSimModel::GetSimModel() {
    return m_val;
}
