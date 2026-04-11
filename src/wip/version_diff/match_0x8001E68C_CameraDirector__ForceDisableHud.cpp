extern int gCameraHudFlag;

struct CameraDirector {
    char pad[0x16C];
    int m_disableHud;
};

void CameraDirector__ForceDisableHud(CameraDirector* self, int disable) {
    if (disable == 1 && gCameraHudFlag) {
        self->m_disableHud = disable;
    } else {
        self->m_disableHud = 0;
    }
}
