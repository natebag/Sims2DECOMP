// 0x80307D74 (32B) EVibrate::IsControllerOn(unsigned char)

class EVibrate {
public:
    int IsControllerOn(unsigned char idx);
};

int EVibrate::IsControllerOn(unsigned char idx) {
    if (idx > 1)
        return 0;
    int offset = idx * 68;
    int* base = (int*)((char*)this + 56);
    return *(int*)((char*)base + offset);
}
