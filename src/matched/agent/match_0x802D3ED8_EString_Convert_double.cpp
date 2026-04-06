extern "C" void EString_Convert_float(void* self, float f);
void EString_Convert_double(void* self, double d) {
    EString_Convert_float(self, (float)d);
}
