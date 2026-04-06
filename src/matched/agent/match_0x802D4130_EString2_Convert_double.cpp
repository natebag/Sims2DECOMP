extern "C" void EString2_Convert_float(void* self, float f);
void EString2_Convert_double(void* self, double d) {
    EString2_Convert_float(self, (float)d);
}
