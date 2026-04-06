// FLAGS: -msdata=eabi -G 8
// 0x80335460 ENgcMovie::Stop (60b)
extern void ENgcMovie_PlayerStop(void*);
extern void ENgcMovie_PlayerClose(void*);
extern void EAllocGroup_DeallocateAll(void*);

struct ENgcMovie {
    char pad[68];
    char allocGroup[4];
};

void ENgcMovie_Stop(ENgcMovie* self) {
    ENgcMovie_PlayerStop(self);
    ENgcMovie_PlayerClose(self);
    EAllocGroup_DeallocateAll(&self->allocGroup);
}
