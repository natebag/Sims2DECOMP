// 0x80119DC8 (8 bytes)
class cTrack {
public:
    int IsPlaying();
};

int cTrack::IsPlaying() {
    return *(int*)((char*)this + 0x34);
}
