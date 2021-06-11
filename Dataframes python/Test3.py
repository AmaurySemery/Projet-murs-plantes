import pandas as pd
from time import sleep
import csv
import time

i = 0
range = 10
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

dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])

while i < range:
    i = i + 1
    FormatDate = '%d/%m/%y' + '-' + '%H:%M:%S'
    Date = time.strftime(FormatDate)

    # Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 1
    TypeC1SB1S1 = 'Moisture Sensor'
    ValueC1SB1S1 = 1 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S1 = Entree420mA
    ProductRefC1SB1S1 = ProductRefVMSB
    BrandC1SB1S1 = BrandAdafruit
    NameC1SB1S1 = 'Regis'
    dfC1SB1S1 = dfC1SB1S1.append({'Type': TypeC1SB1S1,'Value': ValueC1SB1S1,'Input Type': InputTypeC1SB1S1,'Product Ref': ProductRefC1SB1S1,'Brand': BrandC1SB1S1,'Name': NameC1SB1S1,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S1)

    # Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB1S2 = 'Moisture Sensor'
    ValueC1SB1S2 = 2 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S2 = Entree420mA
    ProductRefC1SB1S2 = ProductRefVMSB
    BrandC1SB1S2 = BrandAdafruit
    NameC1SB1S2 = 'Regis'
    dfC1SB1S2 = dfC1SB1S2.append({'Type': TypeC1SB1S2,'Value': ValueC1SB1S2,'Input Type': InputTypeC1SB1S2,'Product Ref': ProductRefC1SB1S2,'Brand': BrandC1SB1S2,'Name': NameC1SB1S2,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S1)

    # Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 3
    TypeC1SB1S3 = 'Moisture Sensor'
    ValueC1SB1S3 = 3 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S3 = Entree420mA
    ProductRefC1SB1S3 = ProductRefVMSB
    BrandC1SB1S3 = BrandAdafruit
    NameC1SB1S3 = 'Regis'
    dfC1SB1S3 = dfC1SB1S3.append({'Type': TypeC1SB1S3,'Value': ValueC1SB1S3,'Input Type': InputTypeC1SB1S3,'Product Ref': ProductRefC1SB1S3,'Brand': BrandC1SB1S3,'Name': NameC1SB1S3,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S1)

    sleep(sleepsecond)


    if(i >= range):
        FormatDateLog = '%d-%m-%y' + '-' + '%H-%M-%S'
        lognow = time.strftime(FormatDateLog)

        LogdfC1SB1S1 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S1/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S1)
        df = pd.DataFrame(dfC1SB1S1) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S1) # placer l'adresse du fichier ici
        print(dfC1SB1S1)

        LogdfC1SB1S2 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S2/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S2)
        df = pd.DataFrame(dfC1SB1S2) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S2) # placer l'adresse du fichier ici
        print(dfC1SB1S2)

        LogdfC1SB1S3 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S2/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S2)
        df = pd.DataFrame(dfC1SB1S3) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S3) # placer l'adresse du fichier ici
        print(dfC1SB1S3)


        del dfC1SB1S1
        dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1S2
        dfC1SB1S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1S3
        dfC1SB1S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])

        i = 0




# Un nouveau fichier d'historiques est généré dans le dossier visé