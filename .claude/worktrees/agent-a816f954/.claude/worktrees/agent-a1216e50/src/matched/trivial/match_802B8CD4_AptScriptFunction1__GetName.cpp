// 0x802B8CD4 (8 bytes)
class AptScriptFunction1 {
public:
    int GetName();
};

int AptScriptFunction1::GetName() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0x0);
}
