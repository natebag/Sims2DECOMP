import struct, subprocess, os, tempfile

DOL = 'extracted/sys/main.dol'

# Find text section offset
with open(DOL, 'rb') as f:
    dol = f.read()

text_offsets = struct.unpack('>18I', dol[0x00:0x48])
text_addresses = struct.unpack('>18I', dol[0x48:0x90])

def get_dol_offset(vaddr):
    for i in range(7):
        if text_addresses[i] <= vaddr < text_addresses[i] + int.from_bytes(dol[0x90+i*4:0x94+i*4], 'big'):
            return text_offsets[i] + (vaddr - text_addresses[i])
    return None

targets = [
    (0x8008FF18, 24, "LiveModeInitState::DatasetPendingAddRefAsync"),
    (0x8009018C, 24, "ChangeHouseLoadHouse::DatasetPendingAddRefAsync"),
    (0x80090BB8, 24, "LoadingScreenStateMachine::IsReadyToLoad"),
    (0x800922DC, 24, "MUStatesSaveNewGame::Reset"),
    (0x800EAA68, 24, "cXObjectImpl::GetMiscFlag"),
    (0x800EB218, 24, "cXObjectImpl::CountObjectSlots"),
    (0x80146998, 24, "TileWalls::HasWall"),
    (0x8017BF2C, 24, "UIHDTV::IsFoundNumberNegative"),
    (0x80183120, 24, "ActionMenu::MenuItem::GetNthItem"),
    (0x80190DF4, 24, "InteractionHelper::GetNext"),
    (0x801C1144, 24, "M2MTarget::GetMemCardPort"),
    (0x8021CEF0, 24, "FadeSquare::StopDraw"),
]

for addr, size, name in targets:
    offset = get_dol_offset(addr)
    if offset is None:
        print(f"Could not find {name} in DOL")
        continue
    with open(DOL, 'rb') as f:
        f.seek(offset)
        data = f.read(size)
    
    print(f"=== {name} @ 0x{addr:08X} ({size}B) ===")
    # Create ELF with just this code section for disassembly
    with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as tmp:
        tmp.write(data)
        tmpname = tmp.name
    
    # Use powerpc-eabi-objdump if available
    objdump = os.environ.get('OBJDUMP', 'powerpc-eabi-objdump')
    try:
        result = subprocess.run([objdump, '-b', 'binary', '-m', 'powerpc', '-D', tmpname], capture_output=True, text=True)
        lines = result.stdout.splitlines()
        for line in lines[7:]:
            print(line)
    except Exception as e:
        print(f"objdump failed: {e}")
        # fallback: print hex
        print(' '.join(f'{b:02x}' for b in data))
    os.unlink(tmpname)
    print()
