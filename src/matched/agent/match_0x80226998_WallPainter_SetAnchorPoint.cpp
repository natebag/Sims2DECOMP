struct EVec3 {
    float x, y, z;
};
struct WallPainter {
    char _pad[0x60];
    EVec3 m_SetAnchorPoint;
    void SetAnchorPoint(EVec3 *v);
};
void WallPainter::SetAnchorPoint(EVec3 *v) {
    m_SetAnchorPoint = *v;
}
