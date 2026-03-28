/* PenaltyRect::PenaltyRect(int, int, int, int, int) - 0x80138998 - 28 bytes */
/* mr r9, r3; stw r4, 4(r9); stw r6, 0xC(r9); stw r5, 0(r9); stw r7, 8(r9); stw r8, 0x10(r9); blr */

class PenaltyRect {
public:
    int m_field0;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_penalty;

    PenaltyRect(int, int, int, int, int);
};

PenaltyRect::PenaltyRect(int a, int b, int c, int d, int penalty) {
    m_field4 = a;
    m_fieldC = c;
    m_field0 = b;
    m_field8 = d;
    m_penalty = penalty;
}
