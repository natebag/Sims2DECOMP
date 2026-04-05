typedef unsigned char u8;
extern int VT_ESimsDataMgr[];
void base_dtor_sdm(u8*);
void d_ESimsDataManager(u8* self) {
    *(int**)(self + 0xD1C) = VT_ESimsDataMgr;
    *(int*)(self + 0x48) = 0;
    base_dtor_sdm(self);
}
