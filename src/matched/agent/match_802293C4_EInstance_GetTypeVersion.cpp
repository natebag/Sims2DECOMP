/* EInstance::GetTypeVersion(void) const - 0x802293C4 (12 bytes) */
// TU: e_instance

struct TypeInfo;

extern unsigned int EInstance_typeInfo_version;

struct EInstance {
    unsigned int GetTypeVersion() const;
};

unsigned int EInstance::GetTypeVersion() const {
    return EInstance_typeInfo_version;
}
