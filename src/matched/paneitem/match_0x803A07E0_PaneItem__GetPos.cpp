struct PaneItem {
    char _pad[0x0c];
    float m_pos;
    float *GetPos();
};
float *PaneItem::GetPos() { return &m_pos; }
