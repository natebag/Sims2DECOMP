// 0x802B9180 (8 bytes)
class AptScriptFunctionByteCodeBlock {
public:
    int GetName();
};

int AptScriptFunctionByteCodeBlock::GetName() {
    return *(int*)((char*)this + 0x3C);
}
