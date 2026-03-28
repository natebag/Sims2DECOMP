// 0x80035314 (8 bytes)
class ESim {
public:
    int GetPerson();
};

int ESim::GetPerson() {
    return *(int*)((char*)this + 0x3D0);
}
