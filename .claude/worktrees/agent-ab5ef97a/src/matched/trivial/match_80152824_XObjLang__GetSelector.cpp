// 0x80152824 (8 bytes)
class XObjLang {
public:
    int GetSelector();
};

int XObjLang::GetSelector() {
    return *(int*)((char*)this + 0x4);
}
