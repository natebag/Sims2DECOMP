/* SimLog::BeginLogging(void) - 0x8013FADC - 12 bytes */
/* li r0, 1; stw r0, 0(r3); blr */

class SimLog {
public:
    int m_isLogging;

    void BeginLogging(void);
};

void SimLog::BeginLogging(void) {
    m_isLogging = 1;
}
