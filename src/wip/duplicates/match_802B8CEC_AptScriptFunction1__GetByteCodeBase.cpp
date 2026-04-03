// 0x802B8CEC (8 bytes)
class AptScriptFunction1 {
public:
    int GetByteCodeBase();
};

int AptScriptFunction1::GetByteCodeBase() {
    return (int)((char*)(*(int*)((char*)this + 0x34)) + 0x18);
}
