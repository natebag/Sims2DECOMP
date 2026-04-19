/* cXMTObjectImpl::GetFirstMultiTileObject(void) at 0x800C7D14 (48B) */
/* VERSION_DIFF: DOL is 48B, GCC produces 40B.
 * SN ProDG saves m_root load in cr7 and reuses that comparison for the second
 * branch, plus inserts an intermediate r0 scheduling fill. GCC elides both
 * artifacts. Unfixable without inline asm.
 */

struct cXMTObj_GFMT {
    int _pad0;            // 0
    cXMTObj_GFMT* m_first;  // 4
    int _pad2;            // 8
    cXMTObj_GFMT* m_root;   // 12
    cXMTObj_GFMT* GetFirstMultiTileObject();
};

cXMTObj_GFMT* cXMTObj_GFMT::GetFirstMultiTileObject() {
    cXMTObj_GFMT* p = m_root;
    if (!p) {
        if (!this) return 0;
        p = this;
    }
    return p->m_first;
}
