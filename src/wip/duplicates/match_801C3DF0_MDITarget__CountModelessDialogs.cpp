// 0x801C3DF0 (8 bytes)
class MDITarget {
public:
    int CountModelessDialogs();
};

int MDITarget::CountModelessDialogs() {
    return *(int*)((char*)this + 0x88);
}
