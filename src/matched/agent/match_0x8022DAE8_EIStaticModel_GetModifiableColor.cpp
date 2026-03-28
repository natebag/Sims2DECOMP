struct EIStaticModel {
    char _pad[0x114];
    int m_GetModifiableColor;
    int GetModifiableColor();
};
int EIStaticModel::GetModifiableColor() { return m_GetModifiableColor; }
