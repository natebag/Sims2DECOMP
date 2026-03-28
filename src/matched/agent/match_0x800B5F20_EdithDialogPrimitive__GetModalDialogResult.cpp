/* EdithDialogPrimitive::GetModalDialogResult(void) const at 0x800B5F20 (8B) */

struct EdithDialogPrimitive {
    char pad[0x88];
    int m_modalDialogResult;

    int GetModalDialogResult(void) const;
};

int EdithDialogPrimitive::GetModalDialogResult(void) const {
    return m_modalDialogResult;
}
