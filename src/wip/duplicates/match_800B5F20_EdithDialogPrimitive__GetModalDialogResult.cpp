// 0x800B5F20 (8 bytes)
class EdithDialogPrimitive {
public:
    int GetModalDialogResult();
};

int EdithDialogPrimitive::GetModalDialogResult() {
    return *(int*)((char*)this + 0x88);
}
