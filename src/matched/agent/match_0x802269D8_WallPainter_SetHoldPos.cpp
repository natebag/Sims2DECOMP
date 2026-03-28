struct EVec3 {
    float x, y, z;
};
struct WallPainter {
    char _pad[0x78];
    EVec3 m_SetHoldPos;
    void SetHoldPos(EVec3 *v);
};
void WallPainter::SetHoldPos(EVec3 *v) {
    m_SetHoldPos = *v;
}
