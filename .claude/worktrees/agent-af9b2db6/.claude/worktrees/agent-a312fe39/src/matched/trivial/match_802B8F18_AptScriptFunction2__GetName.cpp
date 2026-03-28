// 0x802B8F18 (8 bytes)
class AptScriptFunction2 {
public:
    int GetName();
};

int AptScriptFunction2::GetName() {
    return *(int*)((char*)(*(int*)((char*)this + 0x34)) + 0x0);
}
