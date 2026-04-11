/* ISimsCounterTopObject::GetTypeName(void) const - 0x8005428C (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    const char* GetTypeName() const;
};

const char* ISimsCounterTopObject::GetTypeName() const {
    return *(const char**)((char*)&ISimsCounterTopObject_typeInfo + 12);
}
