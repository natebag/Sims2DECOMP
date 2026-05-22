// 0x803c1de0 operator*(float, EQuat&) (56B)
// FLAGS: -fno-schedule-insns
// DOL loads: w,x,y,z; multiplies; stores: x,y,z,w
// No -fno-elide-constructors: DOL writes directly to hidden return ptr (RVO)
struct EQuat {
    float x, y, z, w;
};

EQuat operator*(float s, const EQuat& q) {
    EQuat result;
    result.x = s * q.x;
    result.y = s * q.y;
    result.z = s * q.z;
    result.w = s * q.w;
    return result;
}
