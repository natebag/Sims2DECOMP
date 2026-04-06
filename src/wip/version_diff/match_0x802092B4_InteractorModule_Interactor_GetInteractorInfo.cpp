// InteractorModule::Interactor::GetInteractorInfo - 0x802092B4 (36 bytes)

struct InteractorInfo {
    float x, y;
    float extentX, extentY;
};

struct Interactor {
    char pad[8];
    float m_posX;        // 8
    float m_posY;        // 12
    char pad2[64];
    float m_extentX;     // 80
    float m_extentY;     // 84

    void GetInteractorInfo(InteractorInfo *info);
};

void Interactor::GetInteractorInfo(InteractorInfo *info) {
    info->x = m_posX;
    info->y = m_posY;
    info->extentX = m_extentX;
    info->extentY = m_extentY;
}
