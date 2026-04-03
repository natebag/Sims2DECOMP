// 0x8012C9B8 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordStartTicks();
};

int cXPersonImpl::GetRecordStartTicks() {
    return *(int*)((char*)this + 0x440);
}
