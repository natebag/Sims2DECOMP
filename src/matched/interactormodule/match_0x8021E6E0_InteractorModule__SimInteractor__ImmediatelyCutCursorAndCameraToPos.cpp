// 0x8021E6E0 InteractorModule::SimInteractor::ImmediatelyCutCursorAndCameraToPos (76B)

struct EVec3 {
    int x;
    int y;
    int z;
};

struct ESimsCam {
    void ForceTarget(EVec3&);
};

struct SimInteractor {
    char pad[4];
    ESimsCam* m_cam;
    EVec3 m_pos;
    char pad2[0x18C - 0x14];
    int m_field18C;
    void ImmediatelyCutCursorAndCameraToPos(EVec3& pos);
};

void SimInteractor::ImmediatelyCutCursorAndCameraToPos(EVec3& pos) {
    m_field18C = 1;
    m_pos = pos;
    m_cam->ForceTarget(pos);
}
