struct PaneItem {
    char _pad[0x10];
    float m_posY;
    float GetPosY() const;
};
float PaneItem::GetPosY() const { return m_posY; }
