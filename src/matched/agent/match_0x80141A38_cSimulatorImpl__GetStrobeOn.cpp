// 0x80141A38 cSimulatorImpl::GetStrobeOn(void) (12B)
struct cSimulatorImpl {
    char pad[104];
    unsigned short m_unused : 6;
    unsigned short m_strobeOn : 1;
    unsigned short m_lightingIntensity : 9;
};

int cSimulatorImpl__GetStrobeOn(cSimulatorImpl* self) {
    return self->m_strobeOn;
}
