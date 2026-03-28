struct PaneItem {
    char _pad[0x0c];
    float m_posX;
    float GetPosX() const;
};
float PaneItem::GetPosX() const { return m_posX; }
