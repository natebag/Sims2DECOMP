// 0x80209534 InteractorModule::Interactor::SnapToPos(EVec3&) (40B)
struct EVec3 {
    float x, y, z;
};

struct Interactor {
    char pad[32];
    EVec3 m_pos;
    char pad2[0];
    int m_snapFlag;  // 44
};

void Interactor__SnapToPos(Interactor* self, EVec3& v) {
    self->m_pos = v;
    self->m_snapFlag = 1;
}
