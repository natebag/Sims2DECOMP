struct EVec3 { float x, y, z; };

struct CasTweakTool {
    char pad[0xF8];
    EVec3 m_eye;
    EVec3 m_at;

    void SetCamera(EVec3& eye, EVec3& at);
};

void CasTweakTool::SetCamera(EVec3& eye, EVec3& at) {
    m_eye = eye;
    m_at = at;
}
