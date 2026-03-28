// 0x801C3CA0 (8 bytes)
class MDITarget {
public:
    int IsModelessDialogActive();
};

int MDITarget::IsModelessDialogActive() {
    return *(int*)((char*)this + 0x94);
}
