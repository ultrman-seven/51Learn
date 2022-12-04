import os

def setFile(name):
    with open(name,'r',encoding='gb2312') as f:
        data = f.readlines()
        l = len(data)
        for i in range(l):
            d = data[i]
            if 'sbit' in d:
                d = d.split(';')[0]
                s = d.split('=')
                
                obj = s[-1]
                r,n = obj.split('^')
                s[-1] = f'= def_s_bit({r}, {n});\n'
                data[i] = ' '.join(s)
                # print(data[i])
    with open(name,'w',encoding='gb2312') as f:
        f.writelines(data)




if __name__ == '__main__':
    files = os.listdir('.')
    for fname in files:
        if '.H' in fname:
            print(fname)
            setFile('./' + fname)
    # setFile('./STC8.H')
