import re
with open('extracted/files/u2_ngc_release_dvd.map') as f:
    content = f.read()
pattern = re.compile(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+(?:\s+.*)?\n([^\n]+)', re.MULTILINE)
matches = list(pattern.finditer(content))
print('Total regex matches:', len(matches))
for m in matches[:10]:
    print('ADDR=', m.group(1), 'SIZE=', m.group(2), 'SYM="', m.group(3).strip(), '"')
