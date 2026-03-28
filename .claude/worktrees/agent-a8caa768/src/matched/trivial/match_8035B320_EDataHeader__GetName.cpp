// 0x8035B320 (8 bytes)
class EDataHeader {
public:
    int GetName();
};

int EDataHeader::GetName() {
    return *(int*)((char*)this + 0x0);
}
