// 0x802119C0 InteractorModule::GetPlumbBob(int) (40B)
extern void* g_plumbBobTable[1];  // SDA

void* InteractorModule__GetPlumbBob(int id) {
    void* result = 0;
    if ((unsigned int)id <= 1) {
        void* entry = g_plumbBobTable[id];
        if (entry != 0) result = entry;
    }
    return result;
}
