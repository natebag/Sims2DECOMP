/* LogInteraction::SameInteraction(LogPersonTracker *) - 0x8013EF1C (48 bytes) */

struct LogPersonTracker {
    char pad0[8];
    int m_field_8;
    char pad1[4];
    int m_field_10;
};

class LogInteraction {
public:
    int m_field_0;
    int m_field_4;

    int SameInteraction(LogPersonTracker* p);
};

int LogInteraction::SameInteraction(LogPersonTracker* p) {
    int pf8 = p->m_field_8;
    int result = 0;
    int tf0 = m_field_0;
    int pf10 = p->m_field_10;
    if (pf8 == tf0) {
        result = (pf10 == m_field_4) ? 1 : 0;
    }
    return result;
}
