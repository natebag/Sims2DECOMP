// 0x802B8F24 (8 bytes)
class AptScriptFunction2 {
public:
    int GetNumArguments();
};

int AptScriptFunction2::GetNumArguments() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0x4);
}
