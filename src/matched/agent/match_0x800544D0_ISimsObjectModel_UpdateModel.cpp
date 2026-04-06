// FLAGS: -fno-schedule-insns
// 0x800544D0 ISimsObjectModel::UpdateModel (60b)
void obj_model_refresh(void*);

void UpdateModel_test(char* self, int* param) {
    int newval = *param;
    if (*(int*)(self + 1056) != newval) {
        *(int*)(self + 1056) = newval;
        if (newval != 0) {
            obj_model_refresh(self);
        }
    }
}
