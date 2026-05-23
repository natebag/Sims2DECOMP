// 0x800304D0 (44B) EIWallPart::Construct(EIWallPart *)
// In-place reconstruction: placement-new(src) runs default ctor on src and returns src.

typedef unsigned int size_t;

class EIWallPart {
public:
    char data[952];
    EIWallPart();
    static void* operator new(size_t, void* p);
    static EIWallPart* Construct(EIWallPart* src);
};

EIWallPart* EIWallPart::Construct(EIWallPart* src) {
    return new (src) EIWallPart();
}
