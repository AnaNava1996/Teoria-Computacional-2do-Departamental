#una lista es una clase... si creo una lista fruta[], es un objeto que pertenece a la clase lista... y hay metodos
from random import randint

def Balanceo(xi,ROB):
    k=1
    ROBaux=[]
    ROBaux2=[]
    C=True
    while(C):
        for j in range(len(ROB)):
            if(ROB[j]=='B'):
                if(xi=='('):
                    ROB.append('(')
                    ROB.append('R')
                    ROB.append('B')
                    del (ROB[j])
                    C=False
                    break
                elif(xi!=')'):
                    ROBaux=ROB[0:j]
                    ROBaux2=ROB[j:len(ROB)]
                    ROB=ROBaux+[xi]+ROBaux2
                    C=False
                    break
                else:
                    #print("Truena")
                    C=False
                    break
            elif(ROB[j]=='R'):
                if(xi=='('):
                    ROBaux=ROB[0:j]
                    ROBaux2=ROB[j+1:len(ROB)]
                    ROB=ROBaux+['(','R','R']+ROBaux2
                    C=False
                    break
                elif(xi==')'):
                    ROBaux=ROB[0:j]
                    ROBaux2=ROB[j+1:len(ROB)]
                    ROB=ROBaux+[')']+ROBaux2
                    C=False
                    break
                else:
                    ROBaux=ROB[0:j]
                    ROBaux2=ROB[j:len(ROB)]
                    ROB=ROBaux+[xi]+ROBaux2
                    C=False
                    break   
            else:
                pass
    return ROB

def Doesitwork(ROB,x):
    f=open('grammar.txt','a+')
    f.write("\n")
    b=len(ROB)
    aux=""
    if(ROB[b-1]=='B'):#and(ROB[b-2]==')')
        del(ROB[b-1])
        print("\nLos parentesis")
        f.write("\nLos parentesis\n")
        print(ROB)
        for item in ROB:
            aux=aux+item
        f.write(aux)
        print("estan balanceados")
        f.write("\nestan balanceados")
    else:
        print(x)
        f.write("\n")
        for item in x:
            aux=aux+item
        fm.write(aux)
        print("  no estan balanceados")
        f.write("\n  no estan balanceados")
    f.close()



op=input("\n\nm- Manual\na-Automatico\ns-Salir:    ")
while(op!='s'):
    if(op=='m'):
        paren=str(input("Introduzca la cadena: "))
        x=[]
        fm=open('grammar.txt','a+')
        fm.write("\n\nMODO MANUAL: "+paren+"\n")
        for p in paren:
            x.append(p)
        ROB=['B']
        fm.write("B")
        for i in range(len(x)):
            ROB=Balanceo(x[i],ROB)
            print(ROB)
            fm.write("\n")
            for item in ROB:
                fm.write("%s" % item)
        h=ROB.count('R')
        fm.close()
        if(len(ROB)>len(x)and h==0):
            Doesitwork(ROB,x)
        else:
            print("Los parentesis no estan balanceados")
            fm2=open('grammar.txt','a+')
            fm2.write("\nLos parentesis no estan balanceados")
            fm2.close()
        op=input("\n\nm- Manual\na-Automatico\ns-Salir:    ")
    elif(op=='a'):
        paren=""
        largo=randint(0,4)#rand()%1001
        for i in range(0,largo+1):
            rand1=randint(0,1)
            if(rand1==1):
                paren=paren+')'
            else:
                paren=paren+'('
        print(paren+"\n")
        x=[]
        fa=open('grammar.txt','a+')
        fa.write("\n\nMODO AUTOMATICO: "+paren+"\n")
        for p in paren:
            x.append(p)
        ROB=['B']
        fa.write("B")
        print(ROB)
        for i in range(len(x)):
            ROB=Balanceo(x[i],ROB)
            print(ROB)
            fa.write("\n")
            for item in ROB:
                fa.write("%s" % item)
        h=ROB.count('R')
        fa.close()
        if(len(ROB)>len(x)and h==0):
            Doesitwork(ROB,x)
        else:
            print("Los parentesis no estan balanceados")
            fa2=open('grammar.txt','a+')
            fa2.write("\nLos parentesis no estan balanceados")
            fa2.close()
        op=input("\n\nm- Manual\na-Automatico\ns-Salir:    ")
    elif(op=='s'):
        op=='s'#para que se salga automatico
    else:
        op=input("\n\nm- Manual\na-Automatico\ns-Salir:    ")
