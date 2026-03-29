/* IShrubObject::GetTypeInfoStatic(void) - 0x80054444 (12 bytes) */
// TU: iobject

struct TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* IShrubObject::GetTypeInfoStatic() {
    return &IShrubObject_typeInfo;
}
