// 0x80229574 (80B) EInstance::GetOtherSide(short &, short &)
// Near-twin of GetLocationId — different offsets (32/36), fallback value -1

class EInstance {
public:
    void GetOtherSide(short& a, short& b);
};

void EInstance::GetOtherSide(short& a, short& b) {
    typedef void (*fn_t)(void*, int, short&, short&);
    fn_t fn = *(fn_t*)((char*)this + 32);
    if (fn != 0) {
        void* data = *(void**)((char*)this + 36);
        fn(data, 0, a, b);
    } else {
        b = -1;
        a = -1;
    }
}
