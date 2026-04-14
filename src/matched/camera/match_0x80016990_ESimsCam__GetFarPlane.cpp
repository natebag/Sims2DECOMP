/* ESimsCam::GetFarPlane(void) at 0x80016990 (12B) */

struct SimsCameraParameters {
    char pad[0x68];
    float m_farPlane;
};

struct ESimsCam {
    SimsCameraParameters* m_params;

    float GetFarPlane(void);
};

float ESimsCam::GetFarPlane(void) {
    return m_params->m_farPlane;
}
