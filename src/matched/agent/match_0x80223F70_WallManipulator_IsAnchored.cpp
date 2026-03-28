struct WallManipulator {
    char _pad[0xC4];
    int m_flags;
    int IsAnchored();
};
int WallManipulator::IsAnchored() {
    int f = m_flags;
    if ((f & 1) == 0) {
        return 0;
    }
    return 1;
}
