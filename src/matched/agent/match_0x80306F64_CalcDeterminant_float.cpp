// 0x80306F64 CalcDeterminant(float, float, float, float) (12 B)
// DOL: fmuls f3,f2,f3; fmsubs f1,f1,f4,f3
// Pattern: 2x2 determinant via fmul+fmsub; a*d - b*c
float CalcDeterminant(float a, float b, float c, float d) {
    return a * d - b * c;
}
