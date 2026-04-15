// 0x8021CDC8 InteractorModule::PlaceManipulator::~PlaceManipulator (56B)
// FLAGS: -fno-schedule-insns

extern int VT_PlaceManipulator_92[];
extern int VT_PlaceManipulator_188[];
extern void ObjectManipulator_dtor(void*, int);

void d_PlaceManipulator(void* self, int __in_chrg) {
    *(int**)((char*)self + 92) = VT_PlaceManipulator_92;
    *(int**)((char*)self + 188) = VT_PlaceManipulator_188;
    ObjectManipulator_dtor(self, __in_chrg);
}
