/* ISimsCounterTopObject::GetReadVersion(void) const - 0x800542BC (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    short GetReadVersion() const;
};

short ISimsCounterTopObject::GetReadVersion() const {
    return *(short*)((char*)&ISimsCounterTopObject_typeInfo + 22);
}
