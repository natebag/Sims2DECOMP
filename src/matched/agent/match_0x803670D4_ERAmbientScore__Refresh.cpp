extern "C" void refreshScore(void*, void*, int);
void ERAmbientScore_Refresh(void* self, void* file) {
    if (file) {
        refreshScore(self, file, 0);
    }
}
