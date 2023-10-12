from random import randint
import pickle

mode = ('L', 'R', 'B')

def strToDat(filePath:str) -> bool:
    try:
        with open(filePath, 'wb') as file:
            data = ""
            m = randint(0, 2)
            data += mode[m]
            pos1 = randint(0, 180)
            # ! DAC TO DO PLIKU JAKO FUNKCJA BO JEST DIVERSE
            if pos1 < 10:     data += f'00{pos1}'
            elif pos1 < 100:  data += f'0{pos1}'
            elif pos1 >= 100: data += f'{pos1}'
            
            if mode[m] == 'B': 
                pos2 = randint(0, 180)
                if pos2 < 10:     data += f'00{pos2}'
                elif pos2 < 100:  data += f'0{pos2}'
                elif pos2 >= 100: data += f'{pos2}'
            pickle.dump(data, file)
            return True
    except FileNotFoundError:
        print(f'File {filePath} does not exist')

def datToStr(filePath:str) -> str:
    try:
        with open(filePath, 'rb') as file:
            try:    
                data = pickle.load(file)
                return data
            except EOFError:
                pass
    except FileNotFoundError:
        print(f'File {filePath} does not exist')