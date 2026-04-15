// 0x8021CD90 InteractorModule::GrabManipulator::~GrabManipulator (56B)
// FLAGS: -fno-schedule-insns

extern int VT_GrabManipulator_92[];
extern int VT_GrabManipulator_188[];
extern void ObjectManipulator_dtor(void*, int);

void d_GrabManipulator(void* self, int __in_chrg) {
    *(int**)((char*)self + 92) = VT_GrabManipulator_92;
    *(int**)((char*)self + 188) = VT_GrabManipulator_188;
    ObjectManipulator_dtor(self, __in_chrg);
}
