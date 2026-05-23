// 0x802CF95C ERTQuantize::GetPaletteSize(void) (8 B)
struct ERTQuantize { char _pad[0x10a8]; unsigned m_field; unsigned GetPaletteSize(); };
unsigned ERTQuantize::GetPaletteSize() { return m_field; }
