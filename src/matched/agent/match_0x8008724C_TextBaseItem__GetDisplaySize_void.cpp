// 0x8008724C TextBaseItem::GetDisplaySize(void) (8 B)
struct TextBaseItem { char _pad[0x2c]; float m_displaySize[2]; float* GetDisplaySize(); };
float* TextBaseItem::GetDisplaySize() { return m_displaySize; }
