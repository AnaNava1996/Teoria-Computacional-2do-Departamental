from random import randint

cad1=""#
cad2=""#

op=6
while(op!=0):
    f=open('palindromitos.txt','a+')
    op=int(input("\n0-Para salir.\n1-MANUAL.\n2-AUTOMATICO.\n-->"))
    if(op==1):
        L=int(input("introduzca la longitud de la cadena: "))
        f.write("\n\nMODO MANUAL: "+str(L))
        l=int(L/2)
        for i in range(0,l):
            a=randint(0,1)
            if(a==0):
                cad1=cad1+'1'
                cad2='1'+cad2           
            else:
                cad1=cad1+'0'
                cad2='0'+cad2
        if(L%2 !=0):
            c=randint(1,2)
            if(c==2):
                cad1=cad1+"1"
            else:
                cad1=cad1+"0"
        print(cad1+cad2)
        f.write("\n"+cad1+cad2)
        cad1=""
        cad2=""
    elif(op==2):
        b=randint(0,500)#500 porque la cadena debe llegar maximo a 1000...
        print("b="+str(b))
        for i in range(0,b):
            a=randint(0,1)
            if(a==0):
                cad1=cad1+'1'
                cad2='1'+cad2           
            else:
                cad1=cad1+'0'
                cad2='0'+cad2
        if(b!=500):
            c=randint(1,3)
            if(c!=1):
                print("\nlargo de la cadena: "+str((b*2)+1)+"\n")
                f.write("\n\nMODO AUTOMATICO:\nlongitud: "+str((b*2)+1))
                if(c==2):
                    cad1=cad1+"1"
                else:
                    cad1=cad1+"0"
            else:
                print("\nlargo de la cadena: "+str(b*2)+"\n")
                f.write("\n\nMODO AUTOMATICO:\nlongitud: "+str(b*2))
                cad1=cad1#concateno el vacio en el medio
        else:
            print("\nlargo de la cadena: "+str(b*2)+"\n")
            f.write("\n\nMODO AUTOMATICO:\nlongitud: "+str((b*2)+1))
        print(cad1+cad2)
        f.write("\n"+cad1+cad2)
        cad1=""
        cad2=""
    elif(op==0):
        op=0
print("Saliendo...")
