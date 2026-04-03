// 0x802B8F30 (8 bytes)
class AptScriptFunction2 {
public:
    int GetByteCodeBase();
};

int AptScriptFunction2::GetByteCodeBase() {
    return (int)((char*)(*(int*)((char*)this + 0x34)) + 0x1C);
}
