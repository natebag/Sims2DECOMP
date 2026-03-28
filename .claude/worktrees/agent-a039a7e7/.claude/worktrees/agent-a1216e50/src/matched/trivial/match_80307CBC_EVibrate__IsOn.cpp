// 0x80307CBC (8 bytes)
class EVibrate {
public:
    int IsOn();
};

int EVibrate::IsOn() {
    return *(int*)((char*)this + 0x0);
}
