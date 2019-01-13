def getPalette(i):
    if i == 32:
        return [0, 0, 0]
    elif i < 32:
        return [255 - i*8, 0, i*8]
    else:
        return [255, 255, 0]

length = 33
print('#include <stdint.h>')
print('#include <graphx.h>')
print()
print('const uint16_t palette[] = {')
for i in range(length):
    r, g, b = getPalette(i)
    print(f'    gfx_RGBTo1555({r}, {g}, {b}), // {i}')
print('};')