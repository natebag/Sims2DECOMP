// 0x80306F64 (12 bytes) - CalcDeterminant(float, float, float, float)
// fmuls f3, f2, f3; fmsubs f1, f1, f4, f3; blr

float CalcDeterminant(float a, float b, float c, float d) {
    return a * d - b * c;
}
