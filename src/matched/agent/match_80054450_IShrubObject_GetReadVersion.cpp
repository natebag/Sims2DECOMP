/* IShrubObject::GetReadVersion(void) - 0x80054450 (12 bytes) */
// TU: iobject

extern unsigned int IShrubObject_readVersion;

struct IShrubObject {
    static unsigned int GetReadVersion();
};

unsigned int IShrubObject::GetReadVersion() {
    return IShrubObject_readVersion;
}
