// 0x8001EA44 (8 bytes) — addi r3, r3, 0x424; blr

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    char _pad[0x424];
    EVec3 m_forward;

    EVec3* GetForward() const;
};

EVec3* ESimsCam::GetForward() const {
    return (EVec3*)&m_forward;
}
