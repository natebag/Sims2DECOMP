// EIWallPart::Construct(EIWallPart *)
// Address: 0x800304D0 | Size: 44 bytes

struct EIWallPart;

// External functions
extern "C" void* operator_new(unsigned int size);
extern "C" void EIWallPart__ctor(EIWallPart* self);

EIWallPart* EIWallPart__Construct(EIWallPart* self) {
    EIWallPart* obj = (EIWallPart*)operator_new(952);
    EIWallPart__ctor(obj);
    return obj;
}
