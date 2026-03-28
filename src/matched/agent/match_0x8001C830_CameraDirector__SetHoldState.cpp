struct CameraDirector2 {
    char pad[0x160];
    int m_holdState;
    char pad2[4];
    float m_holdDuration;
};

void CameraDirector_SetHoldState(CameraDirector2* self, float duration) {
    self->m_holdState = 2;
    self->m_holdDuration = duration;
}
