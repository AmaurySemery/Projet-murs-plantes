import pandas as pd
from time import sleep
import csv
from datetime import datetime

ra= 5
Entree420mA = '4-20mA'
EntréeTension = '0-20V'
EntréeAutre = 'Autre'
BrandAdafruit = 'Adafruit'
ProductRefVMSB = 'VM-SB'
sleepmillisecond=0.1
sleepsecond=1
sleep10second=10
sleep30second=30
sleepminut=60
sleephour=3600

# Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 1
dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
for i in range(ra):
    Type = 'Moisture Sensor'
    Value = 2 # Placer le return de la fonction get du sensor ici
    InputType = Entree420mA
    ProductRef = ProductRefVMSB
    Brand = BrandAdafruit
    Name = 'Régis'
    Date = datetime.now()
    dfC1SB1S1 = dfC1SB1S1.append({'Type': Type,'Value': Value,'Input Type': InputType,'Product Ref': ProductRef,'Brand': Brand,'Name': Name,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S1)
    sleep(sleepsecond)

print(dfC1SB1S1)