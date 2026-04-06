extern "C" void EFixedString_Convert_float(void* self, float f);
void EFixedString_Convert_double(void* self, double d) {
    EFixedString_Convert_float(self, (float)d);
}
