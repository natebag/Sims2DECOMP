// 0x80016990 (12 bytes) — lwz r9, 0(r3); lfs f1, 0x68(r9); blr
// Double-dereference: load pointer from offset 0, then float from offset 0x68

struct SimsCameraParameters {
    char _pad[0x68];
    float m_farPlane;
};

class ESimsCam {
public:
    SimsCameraParameters* m_params;  // 0x000

    float GetFarPlane();
};

float ESimsCam::GetFarPlane() {
    return m_params->m_farPlane;
}
