// 0x8001EA3C (8 bytes) — addi r3, r3, 0x424; blr

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    char _pad[0x424];
    EVec3 m_up;

    EVec3* GetUp() const;
};

EVec3* ESimsCam::GetUp() const {
    return (EVec3*)&m_up;
}
