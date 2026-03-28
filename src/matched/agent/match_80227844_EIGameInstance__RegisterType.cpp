struct ETypeInfo;
struct EStorable;

typedef EStorable* (*NewFunc)();
typedef void (*ConstructFunc)(void*);
typedef void (*DestructFunc)(void*);

void ETypeInfo_Register(ETypeInfo*, NewFunc, ConstructFunc, DestructFunc, unsigned short, char*, ETypeInfo*);

extern ETypeInfo EIGameInstance_typeInfo;
extern ETypeInfo EStorable_typeInfo;
extern char EIGameInstance_typeName[];

EStorable* EIGameInstance_New();
void EIGameInstance_Construct(void*);
void EIGameInstance_Destruct(void*);

void EIGameInstance_RegisterType(unsigned short typeID)
{
    ETypeInfo_Register(&EIGameInstance_typeInfo, EIGameInstance_New, EIGameInstance_Construct, EIGameInstance_Destruct, typeID, EIGameInstance_typeName, &EStorable_typeInfo);
}
