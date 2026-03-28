struct EVec3 {
    float x, y, z;
};
struct WallPainter {
    char _pad[0x6C];
    EVec3 m_SetAnchorPointDrawPos;
    void SetAnchorPointDrawPos(EVec3 *v);
};
void WallPainter::SetAnchorPointDrawPos(EVec3 *v) {
    m_SetAnchorPointDrawPos = *v;
}
