// 0x80229528 (76B) EInstance::GetLocationId(short &, short &)

class EInstance {
public:
    void GetLocationId(short& a, short& b);
};

void EInstance::GetLocationId(short& a, short& b) {
    typedef void (*fn_t)(void*, int, short&, short&);
    fn_t fn = *(fn_t*)((char*)this + 28);
    if (fn != 0) {
        void* data = *(void**)((char*)this + 40);
        fn(data, 0, a, b);
    } else {
        b = 0;
        a = 0;
    }
}
