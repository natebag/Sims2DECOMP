// 0x802B8CE0 (8 bytes)
class AptScriptFunction1 {
public:
    int GetNumArguments();
};

int AptScriptFunction1::GetNumArguments() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0x4);
}
