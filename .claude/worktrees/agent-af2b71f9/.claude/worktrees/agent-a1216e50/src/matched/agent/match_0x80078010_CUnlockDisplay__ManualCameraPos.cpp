/* 0x80078010 (16 bytes) - CUnlockDisplay::ManualCameraPos(float, float, float) */
class CUnlockDisplay {
public:
    char pad[0x49C];
    float m_camPosX;
    float m_camPosY;
    float m_camPosZ;
    void ManualCameraPos(float x, float y, float z);
};

void CUnlockDisplay::ManualCameraPos(float x, float y, float z) {
    m_camPosX = x;
    m_camPosY = y;
    m_camPosZ = z;
}
