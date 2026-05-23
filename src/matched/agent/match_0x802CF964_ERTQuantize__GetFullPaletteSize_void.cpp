// 0x802CF964 ERTQuantize::GetFullPaletteSize(void) (8 B)
struct ERTQuantize { char _pad[0x1098]; unsigned m_field; unsigned GetFullPaletteSize(); };
unsigned ERTQuantize::GetFullPaletteSize() { return m_field; }
