// 0x802B9190 (8 bytes)
class AptScriptFunctionByteCodeBlock {
public:
    int GetByteCodeBase();
};

int AptScriptFunctionByteCodeBlock::GetByteCodeBase() {
    return *(int*)((char*)this + 0x34);
}
