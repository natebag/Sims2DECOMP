"""Generate corrected C++ files for all remaining Wrapper/passthru thunk files."""
import os

BASE = "src/matched/agent"

def addref_uint(addr, cls):
    return f"""/* {cls}::AddRef(unsigned int, EFile*, int) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class EFile;
class EResourceManager {{
public:
    void AddRef(unsigned int, EFile*, int);
}};
class {cls} : public EResourceManager {{
public:
    void AddRef(unsigned int id, EFile* file, int flag);
}};
void {cls}::AddRef(unsigned int id, EFile* file, int flag) {{
    EResourceManager::AddRef(id, file, flag);
}}
"""

def addref_char(addr, cls):
    return f"""/* {cls}::AddRef(char*, EFile*, int) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class EFile;
class EResourceManager {{
public:
    void AddRef(char*, EFile*, int);
}};
class {cls} : public EResourceManager {{
public:
    void AddRef(char* name, EFile* file, int flag);
}};
void {cls}::AddRef(char* name, EFile* file, int flag) {{
    EResourceManager::AddRef(name, file, flag);
}}
"""

def getheap(addr, cls, heap_fn):
    return f"""/* {cls}::GetHeap(void) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class EAHeap;
extern EAHeap* {heap_fn}();
class {cls} {{
public:
    EAHeap* GetHeap();
}};
EAHeap* {cls}::GetHeap() {{
    return {heap_fn}();
}}
"""

def createcopy(addr, cls):
    return f"""/* {cls}::CreateCopy(void) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class EStorable {{
public:
    EStorable* CreateCopy() const;
}};
class {cls} : public EStorable {{
public:
    {cls}* CreateCopy() const;
}};
{cls}* {cls}::CreateCopy() const {{
    return ({cls}*)EStorable::CreateCopy();
}}
"""

def op_stream(addr, cls):
    return f"""/* operator<<(EStream&, {cls}*) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class EStream;
class EStorable {{}};
class {cls} : public EStorable {{}};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, {cls}* obj) {{
    return operator<<(s, (EStorable*)obj);
}}
"""

def construct(addr, cls):
    return f"""/* {cls}::Construct({cls}*) at 0x{addr:08X} (32B) */
// 0x{addr:08X} (32 bytes)
class {cls} {{
public:
    {cls}();
    void Construct({cls}* other);
}};
static inline void* operator new(unsigned sz, void* p) {{ return p; }}
void {cls}::Construct({cls}*) {{
    new(this) {cls};
}}
"""

files = {}

# === AddRef(uint) thunks ===
addref_uint_list = [
    (0x80322C84, "EAmbientScoreManager"),
    (0x80322E08, "EAnimManager"),
    (0x8032318C, "EBinaryManager"),
    (0x803232FC, "ECharacterManager"),
    (0x80324954, "EDatasetManager"),
    (0x80324B34, "EEdithTreeSetMan"),
    (0x80324CC0, "EFlashManager"),
    (0x80324E3C, "EFontManager"),
    (0x80324FB8, "EModelManager"),
    (0x80325188, "EMovieMan"),
    (0x803254F8, "EQuickdataManager"),
    (0x803282D4, "EShaderManager"),
    (0x80328750, "ETextureManager"),
    (0x8032B6D4, "ParticleManager"),
]
for addr, cls in addref_uint_list:
    fname = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    files[fname] = addref_uint(addr, cls)

# === AddRef(char*) thunks ===
addref_char_list = [
    (0x80322CA4, "EAmbientScoreManager"),
    (0x80322E28, "EAnimManager"),
    (0x803231AC, "EBinaryManager"),
    (0x8032331C, "ECharacterManager"),
    (0x80324B54, "EEdithTreeSetMan"),
    (0x80324CE0, "EFlashManager"),
    (0x80324E5C, "EFontManager"),
    (0x80324FD8, "EModelManager"),
    (0x803251A8, "EMovieMan"),
    (0x80325518, "EQuickdataManager"),
    (0x803282F4, "EShaderManager"),
    (0x80328770, "ETextureManager"),
    (0x8032B6F4, "ParticleManager"),
]
for addr, cls in addref_char_list:
    fname = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    files[fname] = addref_char(addr, cls)

# === GetHeap thunks ===
getheap_list = [
    (0x80322BA0, "EAmbientScoreManager", "VMHeap"),
    (0x80322D24, "EAnimManager", "VMHeap"),
    (0x803230A4, "EBinaryManager", "VMHeap"),
    (0x80324A4C, "EEdithTreeSetMan", "VMHeap"),
    (0x80324BD4, "EFlashManager", "VMHeap"),
    (0x80324ED4, "EModelManager", "ModelHeap"),
    (0x8032526C, "EQuickdataManager", "VMHeap"),
    (0x803281DC, "EShaderManager", "VMHeap"),
    (0x80328658, "ETextureManager", "TextureHeap"),
    (0x8036C33C, "EAudioSampleManager", "VMHeap"),
    (0x8032758C, "EResourceManager", "ResourceHeap"),
]
for addr, cls, heap in getheap_list:
    fname = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    files[fname] = getheap(addr, cls, heap)

# === EDatasetManager non-standard variants ===
files["match_0x80324974_Wrapper_80324974.cpp"] = """/* EDatasetManager::AddRefAsync(unsigned int) at 0x80324974 (32B) */
// 0x80324974 (32 bytes)
class EResourceManager {
public:
    void AddRefAsync(unsigned int id);
};
class EDatasetManager : public EResourceManager {
public:
    void AddRefAsync(unsigned int id);
};
void EDatasetManager::AddRefAsync(unsigned int id) {
    EResourceManager::AddRefAsync(id);
}
"""

files["match_0x80324994_Wrapper_80324994.cpp"] = """/* EDatasetManager::PreloadResource(unsigned int) at 0x80324994 (32B) */
// 0x80324994 (32 bytes)
class EResourceManager {
public:
    void PreloadResource(unsigned int id);
};
class EDatasetManager : public EResourceManager {
public:
    void PreloadResource(unsigned int id);
};
void EDatasetManager::PreloadResource(unsigned int id) {
    EResourceManager::PreloadResource(id);
}
"""

files["match_0x803249B4_Wrapper_803249B4.cpp"] = """/* EDatasetManager::DelRef(unsigned int, EResourceManager::DelRefMode) at 0x803249B4 (32B) */
// 0x803249B4 (32 bytes)
class EResourceManager {
public:
    enum DelRefMode { kDelRefDefault };
    void DelRef(unsigned int id, DelRefMode mode);
};
class EDatasetManager : public EResourceManager {
public:
    void DelRef(unsigned int id, DelRefMode mode);
};
void EDatasetManager::DelRef(unsigned int id, EResourceManager::DelRefMode mode) {
    EResourceManager::DelRef(id, mode);
}
"""

files["match_0x803249D4_Wrapper_803249D4.cpp"] = """/* EDatasetManager::DelRef(char*, EResourceManager::DelRefMode) at 0x803249D4 (32B) */
// 0x803249D4 (32 bytes)
class EResourceManager {
public:
    enum DelRefMode { kDelRefDefault };
    void DelRef(char* name, DelRefMode mode);
};
class EDatasetManager : public EResourceManager {
public:
    void DelRef(char* name, DelRefMode mode);
};
void EDatasetManager::DelRef(char* name, EResourceManager::DelRefMode mode) {
    EResourceManager::DelRef(name, mode);
}
"""

# === CreateCopy thunks ===
createcopy_list = [
    (0x803205D0, "ERShader"),
    (0x80321344, "ERTexture"),
    (0x80322B54, "REffectsAttachment"),
    (0x803672C0, "ERAmbientScore"),
    (0x80368128, "ERAnim"),
    (0x803685EC, "ERBinary"),
    (0x80368CE0, "ERCharacter"),
    (0x803698D0, "ERDataset"),
    (0x8036A6A4, "ERSoundTrackData"),
    (0x8036ACCC, "REffectsEmitter"),
    (0x8036B1FC, "REffectsSequencer"),
    (0x8036C284, "RParticle"),
    (0x80364BD8, "EFontData"),
]
for addr, cls in createcopy_list:
    # Some have Wrapper filename, some have passthru
    w_name = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    p_name = f"match_0x{addr:08X}_passthru.cpp"
    fname = p_name if os.path.exists(os.path.join(BASE, p_name)) else w_name
    files[fname] = createcopy(addr, cls)

# === op<< thunks ===
opstream_list = [
    (0x80320A88, "ERTexture"),
    (0x80322360, "REffectsAttachment"),
    (0x803637A4, "EFontPage"),
    (0x80363A88, "EFontSize"),
    (0x80363F84, "EFontData"),
    (0x803668F8, "ERAmbientScore"),
    (0x8036730C, "ERAnim"),
    (0x803681D8, "ERBinary"),
    (0x80368648, "ERCharacter"),
    (0x80368DA0, "ERDataset"),
    (0x8036A0A4, "ERSoundTrackData"),
    (0x8036A714, "REffectsEmitter"),
    (0x8036ADD0, "REffectsSequencer"),
    (0x8036B248, "RParticle"),
    (0x8036C97C, "EAnimNodeDataPos"),
]
for addr, cls in opstream_list:
    w_name = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    p_name = f"match_0x{addr:08X}_passthru.cpp"
    fname = p_name if os.path.exists(os.path.join(BASE, p_name)) else w_name
    files[fname] = op_stream(addr, cls)

# === Construct thunks ===
construct_list = [
    (0x80322A34, "REffectsAttachment"),
    (0x803671A0, "ERAmbientScore"),
    (0x803684CC, "ERBinary"),
    (0x803697B0, "ERDataset"),
    (0x8036A584, "ERSoundTrackData"),
    (0x8036ABAC, "REffectsEmitter"),
    (0x8036B0DC, "REffectsSequencer"),
    (0x80364950, "EFontSize"),
    (0x80364AB8, "EFontData"),
    (0x803CA8AC, "EAnimNodeDataPos"),
]
for addr, cls in construct_list:
    w_name = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    p_name = f"match_0x{addr:08X}_passthru.cpp"
    fname = p_name if os.path.exists(os.path.join(BASE, p_name)) else w_name
    files[fname] = construct(addr, cls)

# === Simple misc 32B thunks ===
files["match_0x803383A0_Wrapper_803383A0.cpp"] = """/* ENgcRC::Init(RCMode) at 0x803383A0 (32B) */
// 0x803383A0 (32 bytes)
typedef int RCMode;
class ERC {
public:
    void Init(RCMode mode);
};
class ENgcRC : public ERC {
public:
    void Init(RCMode mode);
};
void ENgcRC::Init(RCMode mode) {
    ERC::Init(mode);
}
"""

files["match_0x8033ECB8_Wrapper_8033ECB8.cpp"] = """/* ENgcRenderer::Flush(ENgcRendCommand*) at 0x8033ECB8 (32B) */
// 0x8033ECB8 (32 bytes)
extern void GXDrawDone();
class ENgcRendCommand;
class ENgcRenderer {
public:
    void Flush(ENgcRendCommand* cmd);
};
void ENgcRenderer::Flush(ENgcRendCommand*) {
    GXDrawDone();
}
"""

files["match_0x803477AC_passthru.cpp"] = """/* ENgcRenderer::NgcTexInvalidateAll(EDLEntry*) at 0x803477AC (32B) */
// 0x803477AC (32 bytes)
extern void GXInvalidateTexAll();
class EDLEntry;
class ENgcRenderer {
public:
    void NgcTexInvalidateAll(EDLEntry* entry);
};
void ENgcRenderer::NgcTexInvalidateAll(EDLEntry*) {
    GXInvalidateTexAll();
}
"""

files["match_0x8034C3E4_passthru.cpp"] = """/* ENgcRenderSurface::GetOutputRect(TRect<float>&) at 0x8034C3E4 (32B) */
// 0x8034C3E4 (32 bytes)
template<class T> struct TRect { T x, y, w, h; };
class ERenderSurface {
public:
    void GetOutputRect(TRect<float>& r);
};
class ENgcRenderSurface : public ERenderSurface {
public:
    void GetOutputRect(TRect<float>& r);
};
void ENgcRenderSurface::GetOutputRect(TRect<float>& r) {
    ERenderSurface::GetOutputRect(r);
}
"""

files["match_0x8034DF80_passthru.cpp"] = """/* ENgcShader::ChangeMaterial(EMaterial&) at 0x8034DF80 (32B) */
// 0x8034DF80 (32 bytes)
class EMaterial;
class EShader {
public:
    void ChangeMaterial(EMaterial& mat);
};
class ENgcShader : public EShader {
public:
    void ChangeMaterial(EMaterial& mat);
};
void ENgcShader::ChangeMaterial(EMaterial& mat) {
    EShader::ChangeMaterial(mat);
}
"""

files["match_0x80363380_passthru.cpp"] = """/* EDL::Alloc(unsigned int, int) at 0x80363380 (32B) */
// 0x80363380 (32 bytes)
class EAllocGroup {
public:
    void Alloc(unsigned int size, int flags);
};
class EDL : public EAllocGroup {
public:
    void Alloc(unsigned int size, int flags);
};
void EDL::Alloc(unsigned int size, int flags) {
    EAllocGroup::Alloc(size, flags);
}
"""

files["match_0x803633A0_passthru.cpp"] = """/* EDL::AllocExternal(void*, int) at 0x803633A0 (32B) */
// 0x803633A0 (32 bytes)
class ENodeList {
public:
    void AddHead(unsigned int data);
};
class EDL : public ENodeList {
public:
    void AllocExternal(void* data, int flags);
};
void EDL::AllocExternal(void* data, int) {
    ENodeList::AddHead((unsigned int)data);
}
"""

files["match_0x803665C4_passthru.cpp"] = """/* BIG_locateentry at 0x803665C4 (32B) */
// 0x803665C4 (32 bytes)
extern int BIG_locateentryz(void*, char*, int*, int*, int*);
int BIG_locateentry(void* p, char* name, int* a, int* b, int* c) {
    return BIG_locateentryz(p, name, a, b, c);
}
"""

files["match_0x8036CE04_passthru.cpp"] = """/* write at 0x8036CE04 (32B) */
// 0x8036CE04 (32 bytes)
extern int _write(int fd, const void* buf, unsigned int n);
int write(int fd, const void* buf, unsigned int n) {
    return _write(fd, buf, n);
}
"""

files["match_0x8036CE24_passthru.cpp"] = """/* close at 0x8036CE24 (32B) */
// 0x8036CE24 (32 bytes)
extern int PCclose(int fd);
int close(int fd) {
    return PCclose(fd);
}
"""

files["match_0x8036CE54_passthru.cpp"] = """/* lseek at 0x8036CE54 (32B) */
// 0x8036CE54 (32 bytes)
extern long PClseek(int fd, long offset, int whence);
long lseek(int fd, long offset, int whence) {
    return PClseek(fd, offset, whence);
}
"""

files["match_0x8036CE74_passthru.cpp"] = """/* read at 0x8036CE74 (32B) */
// 0x8036CE74 (32 bytes)
extern int PCread(int fd, void* buf, unsigned int n);
int read(int fd, void* buf, unsigned int n) {
    return PCread(fd, buf, n);
}
"""

files["match_0x8036E900_passthru.cpp"] = """/* strtodf at 0x8036E900 (32B) */
// 0x8036E900 (32 bytes)
extern double strtod(const char* s, char** end);
double strtodf(const char* s, char** end) {
    return strtod(s, end);
}
"""

files["match_0x80327F10_Wrapper_80327F10.cpp"] = """/* EResourceManager::LookupId(EResourceManager*, unsigned int, unsigned int&, unsigned int&) at 0x80327F10 (32B) */
// 0x80327F10 (32 bytes)
class EResourceManager {
public:
    void LookupId(unsigned int id, unsigned int& outA, unsigned int& outB);
    static void LookupId(EResourceManager* mgr, unsigned int id, unsigned int& outA, unsigned int& outB);
};
void EResourceManager::LookupId(EResourceManager* mgr, unsigned int id, unsigned int& outA, unsigned int& outB) {
    mgr->LookupId(id, outA, outB);
}
"""

files["match_0x803C7234_passthru.cpp"] = """/* ENgcController::IsMotorOneActive(void) at 0x803C7234 (32B) */
// 0x803C7234 (32 bytes)
class EController {
public:
    bool IsMotorOneActive() const;
};
class ENgcController : public EController {
public:
    bool IsMotorOneActive() const;
};
bool ENgcController::IsMotorOneActive() const {
    return EController::IsMotorOneActive();
}
"""

files["match_0x803C7254_passthru.cpp"] = """/* ENgcController::IsMotorTwoActive(void) at 0x803C7254 (32B) */
// 0x803C7254 (32 bytes)
class EController {
public:
    bool IsMotorTwoActive() const;
};
class ENgcController : public EController {
public:
    bool IsMotorTwoActive() const;
};
bool ENgcController::IsMotorTwoActive() const {
    return EController::IsMotorTwoActive();
}
"""

# === 36B thunks ===
files["match_0x8033EDC8_Wrapper_8033EDC8.cpp"] = """/* ENgcRenderer::RestoreViewport(void) at 0x8033EDC8 (36B) */
// 0x8033EDC8 (36 bytes)
class ENgcRenderStateCache {
public:
    void RestoreViewportState();
};
struct ENgcRendererProxy {
    int _pad[310];  // 0x4D8 bytes
    ENgcRenderStateCache* m_stateCache;
};
class ENgcRenderer {
public:
    void RestoreViewport();
};
void ENgcRenderer::RestoreViewport() {
    ((ENgcRendererProxy*)this)->m_stateCache->RestoreViewportState();
}
"""

# SimpleReconObject<T>::DoStream thunks (36B)
simple_recon_list = [
    (0x8039E30C, "ObjectSaveTypeTable2"),
    (0x8039F5BC, "ObjectSaveIDTable"),
    (0x8039F5E8, "ObjectSaveTypeTable3"),
    (0x803A4BE0, "IFFResMap"),
    (0x803A8260, "ObjectSaveTypeTable"),
    (0x803A828C, "ThumbnailLoader"),
]
for addr, T in simple_recon_list:
    w_name = f"match_0x{addr:08X}_Wrapper_{addr:08X}.cpp"
    p_name = f"match_0x{addr:08X}_passthru.cpp"
    fname = p_name if os.path.exists(os.path.join(BASE, p_name)) else w_name
    files[fname] = f"""/* SimpleReconObject<{T}>::DoStream(ReconBuffer*, int) at 0x{addr:08X} (36B) */
// 0x{addr:08X} (36 bytes)
class ReconBuffer;
class {T} {{
public:
    void DoStream(ReconBuffer* rb, int flags);
}};
struct SimpleReconProxy_{T} {{
    void* unused;  // offset 0
    {T}* m_obj;    // offset 4
    void DoStream(ReconBuffer* rb, int flags);
}};
void SimpleReconProxy_{T}::DoStream(ReconBuffer* rb, int flags) {{
    m_obj->DoStream(rb, flags);
}}
"""

# Write all files
count = 0
for fname, content in files.items():
    path = os.path.join(BASE, fname)
    # Check file exists (all should, since these are overwrites of Wrapper/passthru files)
    if os.path.exists(path):
        with open(path, 'w') as f:
            f.write(content)
        count += 1
    else:
        print(f"SKIP (not found): {fname}")

print(f"Wrote {count} files")
