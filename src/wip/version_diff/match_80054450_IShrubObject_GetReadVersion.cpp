/* IShrubObject::GetReadVersion(void) const - 0x80054450 (12 bytes) */
// TU: iobject

typedef struct TypeInfo TypeInfo;

extern TypeInfo IShrubObject_typeInfo;

struct IShrubObject {
    short GetReadVersion() const;
};

short IShrubObject::GetReadVersion() const {
    return *(short*)((char*)&IShrubObject_typeInfo + 22);
}
