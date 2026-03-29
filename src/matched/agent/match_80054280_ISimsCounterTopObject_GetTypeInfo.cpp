/* ISimsCounterTopObject::GetTypeInfo(void) const - 0x80054280 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* ISimsCounterTopObject::GetTypeInfo() const {
    return &ISimsCounterTopObject_typeInfo;
}
