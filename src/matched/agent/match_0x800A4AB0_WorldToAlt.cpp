void IsoToAlt(float &value);
extern float gCoordConversionScales[];

void WorldToAlt(float &value) {
    float temp = value * gCoordConversionScales[6];
    IsoToAlt(temp);
}
