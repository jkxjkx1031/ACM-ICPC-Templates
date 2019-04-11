import os

pdf_path = 'pdf/'
txt_path = 'txt/'

f_tex = open(pdf_path + 'template.tex', 'r')
if not os.path.exists(txt_path):
    os.makedirs(txt_path)
lines = f_tex.readlines()
state = 0
for line in lines:
    if line.find('subsection') != -1:
        l = line.find('{')
        r = line.find('}')
        filename = line[l + 1 : r] + '.txt'
    elif line.find('begin{lstlisting}') != -1:
        print('Rewriting ' + filename + '...')
        f_txt = open(txt_path + filename, 'w')
        state = 1
    elif line.find('end{lstlisting}') != -1:
        f_txt.close()
        print(filename + ' rewritten.')
        state = 0
    elif state == 1:
        f_txt.write(line)