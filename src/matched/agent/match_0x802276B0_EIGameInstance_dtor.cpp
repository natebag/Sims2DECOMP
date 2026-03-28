extern int EIGameInstance_vtable[];
extern void EIGameInstance_dtor_base(void* self);

void EIGameInstance_dtor(void* self) {
    *(int**)self = EIGameInstance_vtable;
    EIGameInstance_dtor_base(self);
}
