// 0x802B9198 (8 bytes)
class AptScriptFunctionByteCodeBlock {
public:
    int GetByteCodeSize();
};

int AptScriptFunctionByteCodeBlock::GetByteCodeSize() {
    return *(int*)((char*)this + 0x38);
}
