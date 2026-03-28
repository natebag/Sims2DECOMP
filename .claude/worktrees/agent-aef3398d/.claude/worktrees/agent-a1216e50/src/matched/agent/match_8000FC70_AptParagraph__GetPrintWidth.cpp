// 0x8000FC70 (8 bytes) — lfs f1, 0x24(r3); blr

class AptParagraph {
public:
    char _pad[0x24];
    float m_printWidth;

    float GetPrintWidth();
};

float AptParagraph::GetPrintWidth() {
    return m_printWidth;
}
