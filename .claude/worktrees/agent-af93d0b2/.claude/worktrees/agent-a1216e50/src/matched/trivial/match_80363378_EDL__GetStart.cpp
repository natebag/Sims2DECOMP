// 0x80363378 (8 bytes)
class EDL {
public:
    int GetStart();
};

int EDL::GetStart() {
    return *(int*)((char*)this + 0x48);
}
