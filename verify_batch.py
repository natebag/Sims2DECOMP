import subprocess, re, os

files = [
    "src/matched/agent/match_0x8003919C_EyeToyClient_GetRepShaderGUID.cpp",
    "src/matched/agent/match_0x8003932C_EyeToyClient_GetSaturation.cpp",
    "src/matched/agent/match_0x80039434_EyeToyClient_GetBrightness.cpp",
    "src/matched/agent/match_0x80039480_EyeToyClient_GetTierRepShaderCount.cpp",
    "src/matched/agent/match_80189AB0_HUDTarget__IsPlayerHUDVisible.cpp",
    "src/matched/agent/match_800D9430_ObjDefinition__GetMultiTileOffsets.cpp",
]

for f in files:
    m = re.search(r'0x([0-9a-fA-F]{8})', f)
    if not m:
        print(f"SKIP {f}")
        continue
    addr = f"0x{m.group(1)}"
    size = "?"
    with open(f, 'r') as fp:
        for line in fp:
            sz = re.search(r'Size:\s*(\d+)', line)
            if sz:
                size = sz.group(1)
                break
    print(f"=== {f} ({addr}, {size}) ===")
    result = subprocess.run(["bash", "tools/verify_match.sh", f, addr, size], capture_output=True, text=True)
    lines = result.stdout.splitlines() + result.stderr.splitlines()
    print("\n".join(lines[-5:]))
    print()
