// 0x80338324 (8 bytes)
class ERSampledata {
public:
    int GetSampleHeader();
};

int ERSampledata::GetSampleHeader() {
    return *(int*)((char*)this + 0x14);
}
