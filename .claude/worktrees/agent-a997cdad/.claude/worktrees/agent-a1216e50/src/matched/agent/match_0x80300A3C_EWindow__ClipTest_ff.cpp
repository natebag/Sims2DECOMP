/* EWindow::ClipTest(float, float) at 0x80300A3C (72 bytes) */

struct EWindow {
    char _pad_00[0x60];
    float m_clipInvX1;     /* 0x60 */
    float m_clipInvY1;     /* 0x64 */
    float m_clipInvX2;     /* 0x68 */
    float m_clipInvY2;     /* 0x6C */

    int ClipTest(float x, float y);
};

int EWindow::ClipTest(float x, float y) {
    int result = 0;
    if (x >= m_clipInvX1 && x < m_clipInvX2 &&
        y >= m_clipInvY1 && y < m_clipInvY2) {
        result = 1;
    }
    return result;
}
