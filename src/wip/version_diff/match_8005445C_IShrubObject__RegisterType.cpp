/* IShrubObject::RegisterType(unsigned short) at 0x8005445C (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo IShrubObject_TypeInfo;
extern "C" EStorable *IShrubObject_NewFunc(void);
extern "C" void IShrubObject_DeleteFunc(void *);
extern "C" void IShrubObject_DtorFunc(void *);
extern char IShrubObject_TypeName[];
extern ETypeInfo IShrubObject_ParentTypeInfo;

void IShrubObject__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &IShrubObject_TypeInfo,
        IShrubObject_NewFunc,
        IShrubObject_DeleteFunc,
        IShrubObject_DtorFunc,
        typeId,
        IShrubObject_TypeName,
        &IShrubObject_ParentTypeInfo
    );
}
