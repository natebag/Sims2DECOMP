// 0x8012C778 (8 bytes)
class cXPersonImpl {
public:
    int GetPersonDataArray();
};

int cXPersonImpl::GetPersonDataArray() {
    return (int)((char*)this + 0x8);
}
