// 0x80034AF0 (36 bytes)
/* ESim::UpdatePlumbBob(void) */

extern float _dt;

struct ESim_UpdatePlumbBob {
    char pad_3EC[0x3EC];
    unsigned int m_plumbBobState;   /* 0x3EC */
    char pad_3F0[4];
    float m_plumbBobFloat;          /* 0x3F4 */

    void UpdatePlumbBob(void);
};

void ESim_UpdatePlumbBob::UpdatePlumbBob(void) {
    unsigned int state = m_plumbBobState;
    if ((unsigned int)(state - 3) > 6u) {
        return;
    }
    m_plumbBobFloat = m_plumbBobFloat * _dt;
}
