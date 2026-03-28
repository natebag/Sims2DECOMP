struct EIStaticModel {
    char _pad[0x114];
    int m_ModifyColor;
    void ModifyColor(int val);
};
void EIStaticModel::ModifyColor(int val) { m_ModifyColor = val; }
