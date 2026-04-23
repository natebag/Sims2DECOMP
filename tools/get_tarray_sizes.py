import json

with open('tools/symbols.json') as f:
    symbols = {s.get('name',''): s for s in json.load(f)['symbols']}

funcs = [
    'TArray<int, TArrayDefaultAllocator>::Copy(int *, int *, int)',
    'TArray<unsigned char *, TArrayDefaultAllocator>::Copy(unsigned char **, unsigned char **, int)',
    'TArray<unsigned char *, TArrayDefaultAllocator>::CopyReverse(unsigned char **, unsigned char **, int)',
    'TArray<unsigned int, TArrayDefaultAllocator>::Copy(unsigned int *, unsigned int *, int)',
    'TArray<EFontPage *, TArrayDefaultAllocator>::Copy(EFontPage **, EFontPage **, int)',
    'TArray<EAnimNodeDataPos, TArrayERAnimAllocator>::Construct(EAnimNodeDataPos *, int)',
    'TArray<float, TArrayERAnimAllocator>::Copy(float *, float *, int)',
    'TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Construct(SndEvtHitPatch *, int)',
    'TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Copy(SndEvtHitPatch *, SndEvtHitPatch *, int)',
]

for f in funcs:
    s = symbols.get(f, {})
    print(f"{s.get('size', 0):3d}  {f}")
