// 0x8012C9A0 (8 bytes)
class cXPersonImpl {
public:
    void SetRecordDuration(int p);
};

void cXPersonImpl::SetRecordDuration(int p) {
    *(int*)((char*)this + 0x434) = p;
}
