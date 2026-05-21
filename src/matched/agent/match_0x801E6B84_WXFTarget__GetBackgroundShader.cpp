// 0x801E6B84 WXFTarget::GetBackgroundShader(tWantType) (84B)

typedef int tWantType;

class WXFTarget {
public:
    unsigned int GetBackgroundShader(tWantType type);
};

unsigned int WXFTarget::GetBackgroundShader(tWantType type) {
    unsigned int r = 0;
    if (type == 0) { r = 0xA0D97DCF; goto end; }
    if (type == 0x80) { r = 0x8CA1C6A6; goto end; }
    if (type == 4) { r = 0x4364EFB7; goto end; }
    if (type != 1) goto end;
    r = 0x087B35FB;
end:
    return r;
}
