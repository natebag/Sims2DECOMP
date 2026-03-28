struct EVec3_SP {
    int x;
    int y;
    int z;
};

struct Interactor_SP {
    char pad[0x20];
    EVec3_SP m_snapPos;
    int m_snapped;

    void SnapToPos(EVec3_SP *pos);
};

void Interactor_SP::SnapToPos(EVec3_SP *pos) {
    m_snapPos = *pos;
    m_snapped = 1;
}
