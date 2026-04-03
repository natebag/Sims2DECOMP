// 0x8033832C (8 bytes)
class ERSampledata {
public:
    int GetSampleHeader2();
};

int ERSampledata::GetSampleHeader2() {
    return *(int*)((char*)this + 0x18);
}
