// 0x80119DB4 (8 bytes)
class cTrack {
public:
    int SetInstanceId(int p);
};

int cTrack::SetInstanceId(int p) {
    *(int*)((char*)this + 0x4) = p; return 1;
}
