struct EFenceWall {
    char _p[0x2c];
    int m_wallsOpaque[4];
    int CalWallsOpaque(int i);
};
int EFenceWall::CalWallsOpaque(int i) { return m_wallsOpaque[i]; }
