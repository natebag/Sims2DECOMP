struct PaneItem {
    char _pad[0x10];
    float m_posY;
    void SetPosY(float val);
};
void PaneItem::SetPosY(float val) { m_posY = val; }
