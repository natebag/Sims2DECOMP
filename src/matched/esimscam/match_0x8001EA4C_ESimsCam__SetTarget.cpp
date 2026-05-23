// ESimsCam::SetTarget(EVec3 &) @ 0x8001EA4C (32B)
// Copies 3-word vector from arg to offset 1084 of this.

struct UVec3 { unsigned int x, y, z; };

class ESimsCam_ST {
public:
    char _pad[1084];
    UVec3 m_target;
    void SetTarget(UVec3& target);
};

void ESimsCam_ST::SetTarget(UVec3& target) {
    m_target = target;
}
