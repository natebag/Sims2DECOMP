/* EIFloor::~EIFloor(void) at 0x800484B4 (88B) */

extern int EIFloor_vtable[];

void EIFloor_Cleanup(void *self);
void EInstance_dtor(void *self, int delFlag);
void EIFloor_opdelete(void *self);

void EIFloor_dtor(void *self, int delFlag) {
    *(int *)self = (int)EIFloor_vtable;
    EIFloor_Cleanup(self);
    EInstance_dtor(self, 0);
    if (delFlag & 1) {
        EIFloor_opdelete(self);
    }
}
