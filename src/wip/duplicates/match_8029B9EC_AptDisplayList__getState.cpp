// 0x8029B9EC (8 bytes)
class AptDisplayList {
public:
    int getState();
};

int AptDisplayList::getState() {
    return *(int*)((char*)this + 0x0);
}
