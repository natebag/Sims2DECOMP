struct EVec3 { float x, y, z; };

struct CasScene {
    char pad[0xA90];
    EVec3 m_camEye;
    EVec3 m_camAt;

    void GetCameraAngle(EVec3* eye, EVec3* at);
};

void CasScene::GetCameraAngle(EVec3* eye, EVec3* at) {
    *eye = m_camEye;
    *at = m_camAt;
}
