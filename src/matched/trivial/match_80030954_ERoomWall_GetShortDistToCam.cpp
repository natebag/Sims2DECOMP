// 0x80030954 (16 bytes)
// ERoomWall::GetShortDistToCam(int)
class ERoomWall {
    char pad[52];
    float m_dist[1];
public:
    float GetShortDistToCam(int index);
};

float ERoomWall::GetShortDistToCam(int index) {
    return m_dist[index];
}
