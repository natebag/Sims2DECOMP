// 0x803C13E0 EStorable::SafeDelete(EStorable*) (64B)

struct EStorable {
    virtual void v4();
    virtual ~EStorable();
    static void SafeDelete(EStorable* p);
};

void EStorable::SafeDelete(EStorable* p) {
    if (p) {
        delete p;
    }
}
