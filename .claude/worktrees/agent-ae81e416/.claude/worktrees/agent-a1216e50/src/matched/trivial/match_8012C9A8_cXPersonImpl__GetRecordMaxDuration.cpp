// 0x8012C9A8 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordMaxDuration();
};

int cXPersonImpl::GetRecordMaxDuration() {
    return *(int*)((char*)this + 0x438);
}
