struct EIStaticSubModel {
    char _pad[0x94];
    int m_GetModifiableColor;
    int GetModifiableColor();
};
int EIStaticSubModel::GetModifiableColor() { return m_GetModifiableColor; }
