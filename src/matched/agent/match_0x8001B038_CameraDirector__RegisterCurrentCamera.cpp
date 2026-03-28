struct CameraDirector {
    char pad[0x170];
    void* m_currentCamera;
};

void CameraDirector_OnCameraChange(CameraDirector* self);

void CameraDirector_RegisterCurrentCamera(CameraDirector* self, void* cam, int force) {
    if (cam) {
        if (self->m_currentCamera == cam) {
            return;
        }
    }
    if (force != 0) {
        self->m_currentCamera = cam;
        CameraDirector_OnCameraChange(self);
    }
}
