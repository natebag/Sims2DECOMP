// 0x8008729C TextBaseItem::GetDisplayPadSize(void) (8 B)
struct TextBaseItem { char _pad[0x34]; float m_displayPadSize[2]; float* GetDisplayPadSize(); };
float* TextBaseItem::GetDisplayPadSize() { return m_displayPadSize; }
