// 0x8012C9C0 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordCurTicks();
};

int cXPersonImpl::GetRecordCurTicks() {
    return *(int*)((char*)this + 0x43C);
}
