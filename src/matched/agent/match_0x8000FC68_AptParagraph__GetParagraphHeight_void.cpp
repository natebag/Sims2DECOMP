// 0x8000FC68 AptParagraph::GetParagraphHeight(void) (8 B)
struct AptParagraph { char _pad[0x30]; float m_paragraphHeight; float GetParagraphHeight(); };
float AptParagraph::GetParagraphHeight() { return m_paragraphHeight; }
