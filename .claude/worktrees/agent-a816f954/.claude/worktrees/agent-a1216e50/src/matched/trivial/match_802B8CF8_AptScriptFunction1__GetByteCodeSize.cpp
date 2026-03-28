// 0x802B8CF8 (8 bytes)
class AptScriptFunction1 {
public:
    int GetByteCodeSize();
};

int AptScriptFunction1::GetByteCodeSize() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0xC);
}
