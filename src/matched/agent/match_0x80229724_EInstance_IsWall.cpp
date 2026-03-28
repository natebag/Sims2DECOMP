struct EInstance {
    char _pad[0x10];
    int m_IsWall;
    int IsWall();
};
int EInstance::IsWall() { return m_IsWall; }
