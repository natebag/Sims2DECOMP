struct ETypeInfo;
struct EStorable;

typedef EStorable* (*NewFunc)();
typedef void (*ConstructFunc)(void*);
typedef void (*DestructFunc)(void*);

void ETypeInfo_Register(ETypeInfo*, NewFunc, ConstructFunc, DestructFunc, unsigned short, char*, ETypeInfo*);

extern ETypeInfo EIDirLight_typeInfo;
extern ETypeInfo EILight_typeInfo;
extern char EIDirLight_typeName[];

EStorable* EIDirLight_New();
void EIDirLight_Construct(void*);
void EIDirLight_Destruct(void*);

void EIDirLight_RegisterType(unsigned short typeID)
{
    ETypeInfo_Register(&EIDirLight_typeInfo, EIDirLight_New, EIDirLight_Construct, EIDirLight_Destruct, typeID, EIDirLight_typeName, &EILight_typeInfo);
}
