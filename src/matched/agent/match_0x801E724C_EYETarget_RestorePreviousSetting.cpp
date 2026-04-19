// 0x801E724C (64B) EYETarget::RestorePreviousSetting(void)
// Direct function-pointer member callback. If the callback is non-null,
// decrement the counter and invoke the callback with the stored float arg.

class EYETarget {
public:
    char pad_000[0x88];
    int m_counter;
    char pad_08C[0xA4 - 0x8C];
    float m_arg;
    void (*m_callback)(float);
    void RestorePreviousSetting(void);
};

void EYETarget::RestorePreviousSetting(void) {
    if (m_callback == 0) return;
    m_counter = m_counter - 1;
    m_callback(m_arg);
}
