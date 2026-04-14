// 0x8026B7A4 Apt_atoff (36b)
extern "C" double atof(const char*);

float Apt_atoff(const char* str) {
    return (float)atof(str);
}
