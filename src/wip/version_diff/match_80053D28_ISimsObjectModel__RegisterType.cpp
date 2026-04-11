/* ISimsObjectModel::RegisterType(unsigned short) at 0x80053D28 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo ISimsObjectModel_TypeInfo;
extern "C" EStorable *ISimsObjectModel_NewFunc(void);
extern "C" void ISimsObjectModel_DeleteFunc(void *);
extern "C" void ISimsObjectModel_DtorFunc(void *);
extern char ISimsObjectModel_TypeName[];
extern ETypeInfo ISimsObjectModel_ParentTypeInfo;

void ISimsObjectModel__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &ISimsObjectModel_TypeInfo,
        ISimsObjectModel_NewFunc,
        ISimsObjectModel_DeleteFunc,
        ISimsObjectModel_DtorFunc,
        typeId,
        ISimsObjectModel_TypeName,
        &ISimsObjectModel_ParentTypeInfo
    );
}
