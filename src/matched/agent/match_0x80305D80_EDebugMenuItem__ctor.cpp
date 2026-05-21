// 0x80305D80 EDebugMenuItem::EDebugMenuItem(void) (32B)
//
// Simple 3-field ctor: sets vtable + zeros m_0 + zeros m_4. DOL stores the
// two zeros in declared order (m_0 then m_4). GCC reorders to ascending
// offset by default. One adjacent-store swap fixes it.
//
// Recipe (1 directive, no new mutator):
//   swap_adj a=stw b=stw which=last - swaps the LAST adjacent stw pair so
//   GCC's (m_4, m_0) becomes DOL's (m_0, m_4) order. Cleaner than
//   volatile-store because the source structure stays plain C++.
//
// ASMPROC_swap_adj: a=stw b=stw which=last

extern char EDebugMenuItem_vt[];

class EDebugMenuItem {
public:
    int m_0;
    int m_4;
    void* m_8;
    EDebugMenuItem();
};

EDebugMenuItem::EDebugMenuItem() {
    m_8 = (void*)EDebugMenuItem_vt;
    m_0 = 0;
    m_4 = 0;
}
