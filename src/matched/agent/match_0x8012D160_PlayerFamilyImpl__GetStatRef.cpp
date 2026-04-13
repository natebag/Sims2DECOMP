// 0x8012D160 PlayerFamilyImpl::GetStatRef(int, short**) (68B)

struct PlayerFamilyImpl {
    int GetStatRef(int index, short** outPtr);
};

int PlayerFamilyImpl::GetStatRef(int index, short** outPtr) {
    if (!outPtr) return 0;
    if ((unsigned)index > 24) {
        *outPtr = 0;
        return 0;
    }
    int off = index * 2 + 0xCA8;
    *outPtr = (short*)((char*)this + off);
    return 1;
}
