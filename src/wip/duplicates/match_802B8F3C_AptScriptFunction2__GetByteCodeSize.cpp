// 0x802B8F3C (8 bytes)
class AptScriptFunction2 {
public:
    int GetByteCodeSize();
};

int AptScriptFunction2::GetByteCodeSize() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0x10);
}
