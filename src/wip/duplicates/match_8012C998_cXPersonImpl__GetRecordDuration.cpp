// 0x8012C998 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordDuration();
};

int cXPersonImpl::GetRecordDuration() {
    return *(int*)((char*)this + 0x434);
}
