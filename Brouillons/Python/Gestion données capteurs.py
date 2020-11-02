import csv
import pandas as pd

f=open(r"/home/popschool/Documents/GitHub/solioti/Python/Données capteurs/capteurs-brut.csv")
r = csv.DictReader(filter(lambda row: row[0]!='#',f), fieldnames = ["Sensor1", "Sensor2", "Sensor3", "Min", "Max","Alert","Moyenne"], delimiter = ",")

Sensor1 = []
Sensor2 = []
Sensor3 = []
Min = []
Max = []
Alert = []
Moyenne = []
for row in r:
    a = int(row['Sensor1'])
    b = int(row['Sensor2'])
    c = int(row['Sensor3'])
    d = int(row['Min'])
    e = int(row['Max'])
    f = int(row['Alert'])
    g = int(row['Moyenne'])
    Sensor1.append(a)
    Sensor2.append(b)
    Sensor3.append(c)
    Min.append(d)
    Max.append(e)
    Alert.append(f)
    Moyenne.append(g)
    
print(Sensor1,Sensor2,Sensor3,Min,Max,Alert,Moyenne)