/* ISimsCounterTopObject::GetTypeName(void) const - 0x8005428C (12 bytes) */
// TU: iobject

extern char ISimsCounterTopObject_typeInfo_name;

struct ISimsCounterTopObject {
    const char* GetTypeName() const;
};

const char* ISimsCounterTopObject::GetTypeName() const {
    return &ISimsCounterTopObject_typeInfo_name;
}
