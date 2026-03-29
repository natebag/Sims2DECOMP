/* ISimsCounterTopObject::GetTypeInfoStatic(void) - 0x800542B0 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ISimsCounterTopObject::GetTypeInfoStatic() {
    return &ISimsCounterTopObject_typeInfo;
}
