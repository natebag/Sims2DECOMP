import subprocess
import os

base = '''// FLAGS: -msdata=eabi -G 8
// 0x800B4214 Commander::Commander(void) (60b)

// SDA globals — small types for r13-relative addressing
{decls}

// VTable extern
extern int Commander_vtable[];

class Commander {{
public:
    Commander* m_next;
    int m_field4;
    Commander* m_prev;
    int* m_vtable;
    Commander();
}};

Commander::Commander() {{
{body}
}}
'''

decls_options = [
    'extern void* g_CommanderHead;\nextern int g_CommanderCount;',
    'extern char g_CommanderHead[4];\nextern int g_CommanderCount;',
    'extern char g_CommanderHead[4];\nextern char g_CommanderCount[4];',
]

body_options = [
    '''    Commander* head = (Commander*)g_CommanderHead;
    m_vtable = Commander_vtable;
    m_field4 = 0;
    m_next = head;
    m_prev = head;
    g_CommanderHead = this;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    Commander* head = (Commander*)g_CommanderHead;
    m_next = head;
    m_prev = head;
    g_CommanderHead = this;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    m_next = (Commander*)g_CommanderHead;
    m_prev = (Commander*)g_CommanderHead;
    g_CommanderHead = this;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    m_next = (Commander*)g_CommanderHead;
    g_CommanderHead = this;
    m_prev = (Commander*)g_CommanderHead;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    void** hp = (void**)&g_CommanderHead;
    m_next = (Commander*)*hp;
    m_prev = (Commander*)*hp;
    *hp = this;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    Commander* head = (Commander*)g_CommanderHead;
    m_next = head;
    m_prev = 0;
    g_CommanderHead = this;
    g_CommanderCount++;''',
    '''    m_vtable = Commander_vtable;
    m_field4 = 0;
    m_next = (Commander*)g_CommanderHead;
    m_prev = 0;
    g_CommanderHead = this;
    g_CommanderCount++;''',
]

for di, decls in enumerate(decls_options):
    for bi, body in enumerate(body_options):
        src = base.format(decls=decls, body=body)
        path = 'build/verify_test/commander_v%d_%d.cpp' % (di, bi)
        with open(path, 'w') as f:
            f.write(src)
        result = subprocess.run(
            ['bash', 'tools/verify_match.sh', '--outdir', 'build/verify_test', path, '0x800B4214', '60'],
            capture_output=True, text=True
        )
        if 'MATCH' in result.stdout:
            print('MATCH! decls=%d body=%d' % (di, bi))
            print(path)
            print(result.stdout)
            break
        else:
            print('No match decls=%d body=%d (%s)' % (di, bi, result.stdout.strip().split('\n')[-1]))
    else:
        continue
    break
else:
    print('No match found')
