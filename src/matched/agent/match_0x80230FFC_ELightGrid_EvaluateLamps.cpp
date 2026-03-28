struct ELightGrid {
    char pad0[0x10];
    int m_portalRoomIdxA;
    int m_portalRoomIdxB;
    int m_pointRoomIdxA;
    int m_pointRoomIdxB;

    void EvaluatePointLights(int, int);
    void EvaluatePortalLights(int, int);
    void EvaluateLamps(void);
};

void ELightGrid::EvaluateLamps(void) {
    EvaluatePointLights(m_pointRoomIdxA, m_pointRoomIdxB);
    EvaluatePortalLights(m_portalRoomIdxA, m_portalRoomIdxB);
}
