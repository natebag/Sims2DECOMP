// 0x801A0934 (8 bytes)
class CASRoommateTarget {
public:
    int GetSelectedSlot();
};

int CASRoommateTarget::GetSelectedSlot() {
    return *(int*)((char*)this + 0x90);
}
