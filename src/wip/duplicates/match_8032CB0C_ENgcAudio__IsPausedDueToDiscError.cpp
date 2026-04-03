// 0x8032CB0C (8 bytes)
class ENgcAudio {
public:
    int IsPausedDueToDiscError();
};

int ENgcAudio::IsPausedDueToDiscError() {
    return *(int*)((char*)this + 0x38);
}
