// 0x80226A20 InteractorModule::WallPainter::SaveInHoldPos(EVec3&) (56B)
struct EVec3 {
    float x, y, z;
};

struct WallPainter {
    char pad[120];
    EVec3 m_holdPos;   // 120
    char pad2[4];      // 132-135
    int m_flags;       // 136
};

void WallPainter__SaveInHoldPos(WallPainter* self, EVec3& v) {
    if ((self->m_flags & 4096) != 0) return;
    self->m_holdPos = v;
    self->m_flags |= 4096;
}
