import pandas as pd
from time import sleep
import csv
from datetime import datetime

ra= 10
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
now = datetime.now()

# Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 1
dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
for i in range(ra):
    now
    Type = 'Moisture Sensor'
    Value = 2 # Placer la valeur du return de la fonction get du sensor ici
    InputType = Entree420mA
    ProductRef = ProductRefVMSB
    Brand = BrandAdafruit
    Name = 'Regis'
    FormatDate = '%d/%m/%y' + '-' + '%H:%M:%S'
    Date = time.strftime(FormatDate)
    dfC1SB1S1 = dfC1SB1S1.append({'Type': Type,'Value': Value,'Input Type': InputType,'Product Ref': ProductRef,'Brand': Brand,'Name': Name,'Date': Date}, ignore_index=True)
    print(dfC1SB1S1)
    sleep(sleepsecond)


print(dfC1SB1S1)


lognow = '-' + str(now.day) + '-' + str(now.month) + '-' + str(now.year) + '-' + str(now.hour) + 'h-' + str(now.minute) + 'm-' + str(now.second) + 's'
LogdfC1SB1S1 = '/Users/Fuan/Desktop/Solioti/test/soliotitest'+lognow+'.csv'
print(LogdfC1SB1S1)
df = pd.DataFrame(dfC1SB1S1) # placer la liste des dataframes ici
df.to_csv(LogdfC1SB1S1) # placer l'adresse du fichier ici

# Un nouveau fichier d'historiques est généré dans le dossier visé