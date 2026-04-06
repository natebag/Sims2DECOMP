// FLAGS: -msdata=eabi -G 8
// 0x8004DFD4 ISimsObjectModel::KillAllAnimTracks (84b)
extern void StopAllTracks(void*);
extern void DelRefAsync(char*, unsigned int);
extern char g_resourceMgr[];

struct ISimsObjectModel {
    char pad[820];
    char animCtrl[180];
    int field_3E8;
    char pad2[200];
    unsigned int field_4B4;
};

void KillAllAnimTracks(ISimsObjectModel* self) {
    StopAllTracks(&self->animCtrl);
    self->field_3E8 = 0;
    unsigned int ref = self->field_4B4;
    if (ref != 0) {
        DelRefAsync(g_resourceMgr, ref);
    }
    self->field_4B4 = 0;
}
