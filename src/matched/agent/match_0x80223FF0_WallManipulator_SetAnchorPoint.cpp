struct EVec3 {
    float x, y, z;
};
struct WallManipulator {
    char _pad[0x60];
    EVec3 m_anchorPoint;
    void SetAnchorPoint(EVec3 *v);
};
void WallManipulator::SetAnchorPoint(EVec3 *v) {
    m_anchorPoint = *v;
}
