// FLAGS: -fno-schedule-insns
// 0x802092D8 InteractorModule::Interactor::SetExtents (20b)

struct InteractorInfo {
    float x, y;
    float extentX, extentY;
};

struct Interactor {
    char pad[80];
    float m_extentX;     // 80
    float m_extentY;     // 84

    void SetExtents(InteractorInfo *info);
};

void Interactor::SetExtents(InteractorInfo *info) {
    m_extentX = info->extentX;
    m_extentY = info->extentY;
}
