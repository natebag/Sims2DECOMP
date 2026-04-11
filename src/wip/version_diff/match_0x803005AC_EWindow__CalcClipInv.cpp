/* EWindow::CalcClipInv(void) at 0x803005AC (84 bytes) */

struct EWindow {
    float m_scaleW;        /* 0x00 */
    char _pad_04[0x10];
    float m_scaleH;        /* 0x14 */
    char _pad_18[0x18];
    float m_transX;        /* 0x30 */
    float m_transY;        /* 0x34 */
    char _pad_38[0x28];
    float m_clipInvX1;     /* 0x60 */
    float m_clipInvY1;     /* 0x64 */
    float m_clipInvX2;     /* 0x68 */
    float m_clipInvY2;     /* 0x6C */
    float m_clipX1;        /* 0x70 */
    float m_clipY1;        /* 0x74 */
    float m_clipX2;        /* 0x78 */
    float m_clipY2;        /* 0x7C */

    void CalcClipInv();
};

void EWindow::CalcClipInv() {
    m_clipInvX1 = (m_clipX1 - m_transX) / m_scaleW;
    m_clipInvY1 = (m_clipY1 - m_transY) / m_scaleH;
    m_clipInvX2 = (m_clipX2 - m_transX) / m_scaleW;
    m_clipInvY2 = (m_clipY2 - m_transY) / m_scaleH;
}
