struct EVec3 { float x, y, z; };
class EMirrorPortal {
public:
    int m_pad;
    EVec3 m_corners[4];
    void SetCorner(int index, EVec3 &corner);
};
void EMirrorPortal::SetCorner(int index, EVec3 &corner) {
    m_corners[index] = corner;
}
