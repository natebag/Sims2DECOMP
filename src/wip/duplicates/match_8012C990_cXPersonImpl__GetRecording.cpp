// 0x8012C990 (8 bytes)
class cXPersonImpl {
public:
    int GetRecording();
};

int cXPersonImpl::GetRecording() {
    return *(int*)((char*)this + 0x430);
}
