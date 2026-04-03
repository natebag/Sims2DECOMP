// 0x80068A40 (8 bytes)
class SAnimator2 {
public:
    int GetAwareOfObject();
};

int SAnimator2::GetAwareOfObject() {
    return *(int*)((char*)this + 0x63C);
}
