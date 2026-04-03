// 0x802CC4BC (8 bytes)
class ENDummy {
public:
    int GetKeys();
};

int ENDummy::GetKeys() {
    return *(int*)((char*)this + 0x44);
}
