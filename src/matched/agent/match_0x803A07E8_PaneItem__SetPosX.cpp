struct PaneItem {
    char _pad[0x0c];
    float m_posX;
    void SetPosX(float val);
};
void PaneItem::SetPosX(float val) { m_posX = val; }
