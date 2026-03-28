// 0x80119DC0 (8 bytes)
class cTrack {
public:
    int InstanceId();
};

int cTrack::InstanceId() {
    return *(int*)((char*)this + 0x4);
}
