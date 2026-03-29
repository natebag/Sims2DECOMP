/* EInstance::GetTypeKey(void) const - 0x802293B8 (12 bytes) */
// TU: e_instance

struct TypeInfo;

extern unsigned int EInstance_typeInfo_key;

struct EInstance {
    unsigned int GetTypeKey() const;
};

unsigned int EInstance::GetTypeKey() const {
    return EInstance_typeInfo_key;
}
