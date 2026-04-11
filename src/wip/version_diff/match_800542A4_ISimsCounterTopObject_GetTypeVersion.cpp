/* ISimsCounterTopObject::GetTypeVersion(void) const - 0x800542A4 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    short GetTypeVersion() const;
};

short ISimsCounterTopObject::GetTypeVersion() const {
    return *(short*)((char*)&ISimsCounterTopObject_typeInfo + 20);
}
