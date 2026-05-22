// 0x80196378 CASTarget::IsViewingMirror(void) (84B)
// ASMPROC_replace_insn: match="cmpwi 0,3,1" replacement="cmpwi 0,3,2"
// ASMPROC_replace_insn: match="bc 12,1,.L8" replacement="bc 4,0,.L8"

struct CASScene {
    char _pad[0x1C];
    struct CASTarget* m_target;
};

struct CASTarget {
    char _pad1[0x84];
    CASScene* m_scene;
    char _pad2[0x7C];
    int m_mode;

    int GetCurrentUIFocus();
    int IsViewingMirror();
};

int CASTarget::IsViewingMirror() {
    if (m_mode == 3) return 0;
    int v = m_scene->m_target->GetCurrentUIFocus();
    if (v > 8) goto is_viewing;
    if (v >= 2) return 0;
is_viewing:
    return 1;
}
