import PIL


def getZM(i):
    pass


if __name__ == '__main__':

    with open('./font.c', 'w')as f:
        f.write('#include "stcint.h"\r\n')
        f.write('code uint8_t ascii_char16_8[107][16] = {\r\n')

        for i in range(0x20, 127):
            print('0x'+hex(i), chr(i))
            data = getZM(i)
            print(data)
        f.write('};\r\n')
