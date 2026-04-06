// FLAGS: -msdata=eabi -G 8
// 0x8006D2FC ESims3DHead::ESims3DHead (96b)
extern int ESims3DHead_VTable[];
extern void E3DWindow_ctor(void*);
extern void ESims3DHead_InitHead(void*, void*);
extern void EMat4_Id(void*);

struct cXPerson { char pad[976]; void* field_976; };

struct ESims3DHead {
    char pad0[848];
    int field_848;
    void* field_852;
    char matrix[64];
    char pad2[24];
    int* vtable_944;
};

ESims3DHead* ESims3DHead_ESims3DHead(ESims3DHead* self, cXPerson* person) {
    self->vtable_944 = ESims3DHead_VTable;
    E3DWindow_ctor(self);
    self->field_848 = 0;
    self->field_852 = person;
    ESims3DHead_InitHead(self, person->field_976);
    EMat4_Id(&self->matrix);
    return self;
}
