// 0x8000FC70 AptParagraph::GetPrintWidth(void) (8 B)
struct AptParagraph { char _pad[0x24]; float m_printWidth; float GetPrintWidth(); };
float AptParagraph::GetPrintWidth() { return m_printWidth; }
