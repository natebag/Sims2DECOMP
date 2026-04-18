// 0x8034C404 (32B) ENgcRenderSurface::SetBackgroundColor(EVec3 &)

struct ENgcRS_V3 { unsigned int x, y, z; };

struct ENgcRS_BC {
    char pad[0xC];
    ENgcRS_V3 m_color;
    void SetBackgroundColor(ENgcRS_V3* col);
};

void ENgcRS_BC::SetBackgroundColor(ENgcRS_V3* col) {
    m_color = *col;
}
