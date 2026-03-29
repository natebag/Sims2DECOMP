/* EILight::GetTypeInfoStatic(void) - 0x80228038 (12 bytes) */
// TU: e_ilight

struct TypeInfo;

extern TypeInfo EILight_typeInfo;

struct EILight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EILight::GetTypeInfoStatic() {
    return &EILight_typeInfo;
}
