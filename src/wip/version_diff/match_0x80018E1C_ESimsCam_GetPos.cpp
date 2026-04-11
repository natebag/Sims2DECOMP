struct EVec3 {
    float x, y, z;
};

struct ESimsCam {
    char pad[0x418];
    EVec3 m_pos;
    EVec3 m_target;
    char pad2[0x0C];
    EVec3 m_up;

    void GetPos(EVec3& p, EVec3& t, EVec3& u);
};

void ESimsCam::GetPos(EVec3& p, EVec3& t, EVec3& u) {
    p = m_pos;
    t = m_up;
    u = m_target;
}
