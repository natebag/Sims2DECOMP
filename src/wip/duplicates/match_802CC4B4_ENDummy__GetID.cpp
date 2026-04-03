// 0x802CC4B4 (8 bytes)
class ENDummy {
public:
    int GetID();
};

int ENDummy::GetID() {
    return *(int*)((char*)this + 0x40);
}
