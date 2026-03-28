struct EIStaticSubModel {
    char _pad[0x94];
    int m_ModifyColor;
    void ModifyColor(int val);
};
void EIStaticSubModel::ModifyColor(int val) { m_ModifyColor = val; }
