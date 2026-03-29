/* IShrubObject::GetTypeKey(void) const - 0x8005442C (12 bytes) */
// TU: iobject

extern unsigned int IShrubObject_typeInfo_key;

struct IShrubObject {
    unsigned int GetTypeKey() const;
};

unsigned int IShrubObject::GetTypeKey() const {
    return IShrubObject_typeInfo_key;
}
