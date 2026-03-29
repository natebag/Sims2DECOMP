/* EIDirLight::GetTypeInfoStatic(void) - 0x80227448 (12 bytes) */
// TU: e_idirlight

struct TypeInfo;

extern TypeInfo EIDirLight_typeInfo;

struct EIDirLight {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* EIDirLight::GetTypeInfoStatic() {
    return &EIDirLight_typeInfo;
}
