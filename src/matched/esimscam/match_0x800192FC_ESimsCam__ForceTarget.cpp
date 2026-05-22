// 0x800192FC (104B) ESimsCam::ForceTarget(EVec3&)

struct EVec3 {
    float x;
    float y;
    float z;
};

class ESimsCam {
public:
    char m_pad[1060];
    EVec3 m_424;
    EVec3 m_430;
    EVec3 m_43C_targetCopy;
    void ForceTarget(EVec3& target);
    void CalcEyePosition(EVec3& outEye, EVec3& target);
    void ForcePosition(EVec3& a, EVec3& b, EVec3& c);
};

void ESimsCam::ForceTarget(EVec3& target) {
    m_43C_targetCopy = target;
    EVec3 local;
    CalcEyePosition(local, m_43C_targetCopy);
    ForcePosition(local, target, m_424);
}
