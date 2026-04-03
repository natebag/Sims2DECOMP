// 0x8001EA34 (8 bytes) — addi r3, r3, 0x43C; blr

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    char _pad[0x43C];
    EVec3 m_target;

    EVec3* GetTarget() const;
};

EVec3* ESimsCam::GetTarget() const {
    return (EVec3*)&m_target;
}
