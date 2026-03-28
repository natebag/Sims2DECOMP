struct ETypeInfo;
struct EStorable;

typedef EStorable* (*NewFunc)();
typedef void (*ConstructFunc)(void*);
typedef void (*DestructFunc)(void*);

void ETypeInfo_Register(ETypeInfo*, NewFunc, ConstructFunc, DestructFunc, unsigned short, char*, ETypeInfo*);

extern ETypeInfo EIAmbLight_typeInfo;
extern ETypeInfo EILight_typeInfo;
extern char EIAmbLight_typeName[];

EStorable* EIAmbLight_New();
void EIAmbLight_Construct(void*);
void EIAmbLight_Destruct(void*);

void EIAmbLight_RegisterType(unsigned short typeID)
{
    ETypeInfo_Register(&EIAmbLight_typeInfo, EIAmbLight_New, EIAmbLight_Construct, EIAmbLight_Destruct, typeID, EIAmbLight_typeName, &EILight_typeInfo);
}
