// 0x8012C9C8 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordTicksElapsed();
};

int cXPersonImpl::GetRecordTicksElapsed() {
    return *(int*)((char*)this + 0x444);
}
