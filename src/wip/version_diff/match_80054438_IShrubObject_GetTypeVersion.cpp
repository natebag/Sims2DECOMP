/* IShrubObject::GetTypeVersion(void) const - 0x80054438 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    short GetTypeVersion() const;
};

short IShrubObject::GetTypeVersion() const {
    return *(short*)((char*)&IShrubObject_typeInfo + 20);
}
