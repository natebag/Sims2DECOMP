/* EQuat::RemoveAxisFlip(EQuat &) - 0x802CD054 (100 bytes) */

struct EQuat {
    float x, y, z, w;

    void RemoveAxisFlip(EQuat &other);
};

void EQuat::RemoveAxisFlip(EQuat &other)
{
    float dot = x * other.x + y * other.y + z * other.z + w * other.w;
    if (dot < 0.0f) {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
}
