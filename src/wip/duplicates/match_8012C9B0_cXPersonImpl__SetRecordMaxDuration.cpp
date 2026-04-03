// 0x8012C9B0 (8 bytes)
class cXPersonImpl {
public:
    void SetRecordMaxDuration(int p);
};

void cXPersonImpl::SetRecordMaxDuration(int p) {
    *(int*)((char*)this + 0x438) = p;
}
