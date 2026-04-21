import os

addrs = [
    "801b8db0", "801b8ddc", "801b8e08", "801b8ec8", "801b8f04",
    "801b8fd8", "801b9014", "801b9050", "801b9088", "801b91e4",
    "801b9220", "801b9260", "801b928c", "801b92b8", "801b92e8",
    "801acc34", "801acfc8", "801ad004", "801ad568",
    "801ad820", "801ad860", "801ae1e4",
    "801dcd88", "801dcdb4", "801dce00",
]

for addr in addrs:
    found = 0
    for root, dirs, files in os.walk('src/matched'):
        for f in files:
            if addr.lower() in f.lower():
                found += 1
    print(f"0x{addr}: {found}")
