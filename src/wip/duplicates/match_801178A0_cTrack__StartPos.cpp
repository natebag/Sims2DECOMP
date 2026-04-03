// 0x801178A0 (8 bytes)
class cTrack {
public:
    int StartPos();
};

int cTrack::StartPos() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0x30);
}
