// 0x800690D8 (8 bytes)
class SAnimator2 {
public:
    int GetPerson();
};

int SAnimator2::GetPerson() {
    return *(int*)((char*)this + 0x4);
}
