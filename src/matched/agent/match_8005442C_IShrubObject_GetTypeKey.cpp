/* IShrubObject::GetTypeKey(void) const - 0x8005442C (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    const char* GetTypeKey() const;
};

const char* IShrubObject::GetTypeKey() const {
    return *(const char**)((char*)&IShrubObject_typeInfo + 16);
}
