extern void EIGameInstance_static_init(int a, unsigned int b);

void global_ctor_EIGameInstance() {
    EIGameInstance_static_init(1, 0xFFFF);
}
