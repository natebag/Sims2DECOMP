// 0x8000FC68 (8 bytes) — lfs f1, 0x30(r3); blr

class AptParagraph {
public:
    char _pad[0x30];
    float m_paragraphHeight;

    float GetParagraphHeight();
};

float AptParagraph::GetParagraphHeight() {
    return m_paragraphHeight;
}
