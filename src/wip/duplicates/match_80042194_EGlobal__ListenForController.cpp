// 0x80042194 (8 bytes)
class EGlobal {
public:
    int ListenForController();
};

int EGlobal::ListenForController() {
    return *(int*)((char*)this + 0x478);
}
