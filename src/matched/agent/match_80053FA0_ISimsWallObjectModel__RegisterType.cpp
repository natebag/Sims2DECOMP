/* ISimsWallObjectModel::RegisterType(unsigned short) at 0x80053FA0 (84B) */

struct ETypeInfo;
struct EStorable;

void ETypeInfo_Register(ETypeInfo *info, EStorable *(*newFn)(void), void (*delFn)(void *), void (*dtorFn)(void *), unsigned short typeId, char *name, ETypeInfo *parent);

extern ETypeInfo ISimsWallObjectModel_TypeInfo;
extern "C" EStorable *ISimsWallObjectModel_NewFunc(void);
extern "C" void ISimsWallObjectModel_DeleteFunc(void *);
extern "C" void ISimsWallObjectModel_DtorFunc(void *);
extern char ISimsWallObjectModel_TypeName[];
extern ETypeInfo ISimsWallObjectModel_ParentTypeInfo;

void ISimsWallObjectModel__RegisterType(unsigned short typeId) {
    ETypeInfo_Register(
        &ISimsWallObjectModel_TypeInfo,
        ISimsWallObjectModel_NewFunc,
        ISimsWallObjectModel_DeleteFunc,
        ISimsWallObjectModel_DtorFunc,
        typeId,
        ISimsWallObjectModel_TypeName,
        &ISimsWallObjectModel_ParentTypeInfo
    );
}
