struct EVec3 { float x, y, z; };

struct CasTweakTool {
    char pad[0xF8];
    EVec3 m_eye;
    EVec3 m_at;

    void GetCamera(EVec3& eye, EVec3& at);
};

void CasTweakTool::GetCamera(EVec3& eye, EVec3& at) {
    eye = m_eye;
    at = m_at;
}
