/* InteractorModule::DirectInteractor::ParseControls(void) at 0x8020415C (112B) */
/* [VERSION_DIFF] v3.93 emits cror+bsolr where DOL uses bgelr cr0 */
/* C++ logic is correct — will match with v1.76 compiler */

extern float gControlDeadZone[];

struct DirectInteractor_PC {
    char _pad0[0x34];
    float m_leftX;
    float m_leftY;
    float m_rightX;
    float m_rightY;
    int m_leftActive;
    int m_rightActive;

    void ParseControls(void);
};

void DirectInteractor_PC::ParseControls(void) {
    m_leftActive = 0;
    m_rightActive = 0;
    float threshold = gControlDeadZone[0];
    if (__builtin_fabs(m_leftX) < threshold) {
        if (__builtin_fabs(m_leftY) < threshold) {
            m_leftActive = 1;
        }
    }
    float threshold2 = gControlDeadZone[0];
    if (__builtin_fabs(m_rightX) >= threshold2) return;
    if (__builtin_fabs(m_rightY) >= threshold2) return;
    m_rightActive = 1;
}
