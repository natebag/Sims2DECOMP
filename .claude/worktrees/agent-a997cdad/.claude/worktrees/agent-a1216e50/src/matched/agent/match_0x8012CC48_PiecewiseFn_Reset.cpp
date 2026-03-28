/* PiecewiseFn::Reset(void) - 0x8012CC48 - 12 bytes */
/* li r0, 0; stw r0, 8(r3); blr */

class PiecewiseFn {
public:
    char _pad[0x8];
    int m_numPoints;

    void Reset(void);
};

void PiecewiseFn::Reset(void) {
    m_numPoints = 0;
}
