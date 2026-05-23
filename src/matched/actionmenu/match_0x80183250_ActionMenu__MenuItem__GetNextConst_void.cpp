// 0x80183250 ActionMenu::MenuItem::GetNextConst(void) (8 B)
namespace ActionMenu { struct MenuItem { char _pad[0x60]; unsigned m_next; unsigned GetNextConst(); }; }
unsigned ActionMenu::MenuItem::GetNextConst() { return m_next; }
