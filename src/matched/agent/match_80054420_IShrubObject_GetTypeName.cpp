/* IShrubObject::GetTypeName(void) const - 0x80054420 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    const char* GetTypeName() const;
};

const char* IShrubObject::GetTypeName() const {
    return *(const char**)((char*)&IShrubObject_typeInfo + 12);
}
