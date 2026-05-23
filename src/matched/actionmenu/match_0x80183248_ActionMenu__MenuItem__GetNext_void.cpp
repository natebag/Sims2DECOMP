// 0x80183248 ActionMenu::MenuItem::GetNext(void) (8 B)
namespace ActionMenu { struct MenuItem { char _pad[0x60]; unsigned m_next; unsigned GetNext(); }; }
unsigned ActionMenu::MenuItem::GetNext() { return m_next; }
