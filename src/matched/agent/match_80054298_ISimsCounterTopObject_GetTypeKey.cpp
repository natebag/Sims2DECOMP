/* ISimsCounterTopObject::GetTypeKey(void) const - 0x80054298 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo ISimsCounterTopObject_typeInfo;

struct ISimsCounterTopObject {
    const char* GetTypeKey() const;
};

const char* ISimsCounterTopObject::GetTypeKey() const {
    return *(const char**)((char*)&ISimsCounterTopObject_typeInfo + 16);
}
