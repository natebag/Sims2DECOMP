// 0x80152FE8 (8 bytes)
class XRoute {
public:
    void SetCurrentGoal(int p);
};

void XRoute::SetCurrentGoal(int p) {
    *(int*)((char*)this + 0x54) = p;
}
