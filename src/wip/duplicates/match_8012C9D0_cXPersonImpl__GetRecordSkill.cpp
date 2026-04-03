// 0x8012C9D0 (8 bytes)
class cXPersonImpl {
public:
    int GetRecordSkill();
};

int cXPersonImpl::GetRecordSkill() {
    return *(int*)((char*)this + 0x448);
}
