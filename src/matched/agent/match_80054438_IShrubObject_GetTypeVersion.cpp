/* IShrubObject::GetTypeVersion(void) const - 0x80054438 (12 bytes) */
// TU: iobject

extern unsigned int IShrubObject_typeInfo_version;

struct IShrubObject {
    unsigned int GetTypeVersion() const;
};

unsigned int IShrubObject::GetTypeVersion() const {
    return IShrubObject_typeInfo_version;
}
