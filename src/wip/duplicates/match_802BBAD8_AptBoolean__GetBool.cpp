// 0x802BBAD8 (8 bytes)
class AptBoolean {
public:
    int GetBool();
};

int AptBoolean::GetBool() {
    return *(int*)((char*)this + 0xC);
}
