// 0x800B5F20 EdithDialogPrimitive::GetModalDialogResult(void) (8 B)
struct EdithDialogPrimitive { char _pad[0x88]; unsigned m_modalDialogResult; unsigned GetModalDialogResult(); };
unsigned EdithDialogPrimitive::GetModalDialogResult() { return m_modalDialogResult; }
