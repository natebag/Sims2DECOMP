int _ActionConditionFlagToActionEventFlags(int flags)
{
    int result = 0;
    if (flags & 0x08) result = 0x0800;
    if (flags & 0x04) result |= 0x0400;
    if (flags & 0x40) result |= 0x1000;
    if (flags & 0x01) result |= 0x2000;
    if (flags & 0x02) result |= 0x4000;
    if (flags & 0x20) result |= 0x8000;
    if (flags & 0x10) result |= 0x10000;
    return result;
}
