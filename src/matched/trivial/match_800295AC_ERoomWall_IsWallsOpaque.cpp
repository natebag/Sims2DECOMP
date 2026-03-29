// 0x800295AC (16 bytes)
// ERoomWall::IsWallsOpaque(int)
class ERoomWall {
    char pad[44];
    bool m_opaque[1];
public:
    bool IsWallsOpaque(int index);
};

bool ERoomWall::IsWallsOpaque(int index) {
    return m_opaque[index];
}
