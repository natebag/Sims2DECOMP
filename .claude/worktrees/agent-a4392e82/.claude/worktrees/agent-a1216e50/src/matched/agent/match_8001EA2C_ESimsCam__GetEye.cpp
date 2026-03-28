// 0x8001EA2C (8 bytes) — addi r3, r3, 0x418; blr
// Returns pointer to eye position (EVec3 at offset 0x418)

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    char _pad[0x418];
    EVec3 m_eye;

    EVec3* GetEye() const;
};

EVec3* ESimsCam::GetEye() const {
    return (EVec3*)&m_eye;
}
