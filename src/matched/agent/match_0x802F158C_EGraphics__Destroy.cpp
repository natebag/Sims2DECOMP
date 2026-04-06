extern "C" void destroyDL(void*, void*, int);
void EGraphics_Destroy(void* self, void* dl) {
    if (dl) { destroyDL(self, dl, 1); }
}
