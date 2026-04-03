// 0x80228044 (12 bytes)
class EILight {
public:
    short GetReadVersion() const;
};

extern char gEILightData[];

short EILight::GetReadVersion() const {
    return *(short*)(gEILightData + 0);
}
