/* IShrubObject::GetTypeName(void) const - 0x80054420 (12 bytes) */
// TU: iobject

extern char IShrubObject_typeInfo_name;

struct IShrubObject {
    const char* GetTypeName() const;
};

const char* IShrubObject::GetTypeName() const {
    return &IShrubObject_typeInfo_name;
}
