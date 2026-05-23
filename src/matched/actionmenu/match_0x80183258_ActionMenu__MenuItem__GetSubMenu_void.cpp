// 0x80183258 ActionMenu::MenuItem::GetSubMenu(void) (8 B)
namespace ActionMenu { struct MenuItem { char _pad[0x5c]; unsigned m_subMenu; unsigned GetSubMenu(); }; }
unsigned ActionMenu::MenuItem::GetSubMenu() { return m_subMenu; }
