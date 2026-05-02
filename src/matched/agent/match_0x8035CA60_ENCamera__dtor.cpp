// 0x8035CA60 (84B) ENCamera::~ENCamera(void)
// Vtable-at-+0x54 SI deleting-dtor + sub-Cleanup(2) at +0x48 + standard __builtin_delete.

class SubObj {
public:
    void Cleanup(int);
};

class ENCameraBase {
public:
    char data[0x54];
};

class ENCamera : public ENCameraBase {
public:
    virtual ~ENCamera();
    SubObj& sub_at_48();
};

inline SubObj& ENCamera::sub_at_48() {
    return *(SubObj*)((char*)this + 0x48);
}

ENCamera::~ENCamera() {
    sub_at_48().Cleanup(2);
}
