struct ELightGrid {
    char pad0[0x10];
    int m_portalRoomIdxA;
    int m_portalRoomIdxB;
    int m_pointRoomIdxA;
    int m_pointRoomIdxB;

    void EvaluatePointLights(int, int);
    void EvaluateAmbientAndDirectionalLights(void);
    void EvaluatePortalLights(int, int);
    void EvaluateOuterLotLights(void);
    void EvaluateLights(void);
};

void ELightGrid::EvaluateLights(void) {
    EvaluatePointLights(m_pointRoomIdxA, m_pointRoomIdxB);
    EvaluateAmbientAndDirectionalLights();
    EvaluatePortalLights(m_portalRoomIdxA, m_portalRoomIdxB);
    EvaluateOuterLotLights();
}
