/* IShrubObject::GetTypeInfo(void) const - 0x80054414 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* IShrubObject::GetTypeInfo() const {
    return &IShrubObject_typeInfo;
}
