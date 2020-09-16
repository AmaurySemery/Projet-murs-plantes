import csv
import pandas as pd

f=open(r"/home/popschool/Documents/GitHub/solioti/Python/Données capteurs/capteurs-brut.csv")
r = csv.DictReader(filter(lambda row: row[0]!='#',f), fieldnames = ["Sensor1", "Sensor2", "Sensor3", "Min", "Max","Alert","Moyenne"], delimiter = ",")