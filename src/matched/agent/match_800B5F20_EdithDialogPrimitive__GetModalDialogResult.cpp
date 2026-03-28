class EdithDialogPrimitive {
public:
    char pad[0x88];
    int m_modalDialogResult;

    int GetModalDialogResult(void) const;
};

int EdithDialogPrimitive::GetModalDialogResult(void) const {
    return m_modalDialogResult;
}
