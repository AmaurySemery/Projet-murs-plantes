import pandas as pd
from time import sleep
import csv
import time

i = 0

# Nombre de lignes pour chaque fichier csv
## Ce range doit être modifié en binôme avec la fonction sleep dans le corps du programme
# Ces modifications détermineront la fréquence d'actualisation des dataframes dans les fichiers ainsi que leur volume
range = 5

# Variables déclarées pour standardiser les items descriptifs
Entree420mA = '4-20mA'
EntréeTension = '0-10V'
EntréeAutre = 'Autre'
BrandAdafruit = 'Adafruit'
ProductRefVMSB = 'VM-SB'

# Variables déclarées pour la gestion des délais
sleepmillisecond=0.1
sleepsecond=1
sleep10second=10
sleep30second=30
sleepminut=60
sleep10minut=600
sleephour=3600

# Création des listes
dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1S4 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB1Op = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB2S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB2S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB2S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB2S4 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
dfC1SB2Op = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])

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

    # Dataframes du Sensor 2 dans le Can Bus 1 pour la Sensor Box 1
    TypeC1SB1S2 = 'Moisture Sensor'
    ValueC1SB1S2 = 2 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S2 = Entree420mA
    ProductRefC1SB1S2 = ProductRefVMSB
    BrandC1SB1S2 = BrandAdafruit
    NameC1SB1S2 = 'Francis'
    dfC1SB1S2 = dfC1SB1S2.append({'Type': TypeC1SB1S2,'Value': ValueC1SB1S2,'Input Type': InputTypeC1SB1S2,'Product Ref': ProductRefC1SB1S2,'Brand': BrandC1SB1S2,'Name': NameC1SB1S2,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S2)

    # Dataframes du Sensor 3 dans le Can Bus 1 pour la Sensor Box 1
    TypeC1SB1S3 = 'Moisture Sensor'
    ValueC1SB1S3 = 3 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S3 = Entree420mA
    ProductRefC1SB1S3 = ProductRefVMSB
    BrandC1SB1S3 = BrandAdafruit
    NameC1SB1S3 = 'Robert'
    dfC1SB1S3 = dfC1SB1S3.append({'Type': TypeC1SB1S3,'Value': ValueC1SB1S3,'Input Type': InputTypeC1SB1S3,'Product Ref': ProductRefC1SB1S3,'Brand': BrandC1SB1S3,'Name': NameC1SB1S3,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S3)

    # Dataframes du Sensor 4 dans le Can Bus 1 pour la Sensor Box 1
    TypeC1SB1S4 = 'Moisture Sensor'
    ValueC1SB1S4 = 4 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1S4 = Entree420mA
    ProductRefC1SB1S4 = ProductRefVMSB
    BrandC1SB1S4 = BrandAdafruit
    NameC1SB1S4 = 'Dupont'
    dfC1SB1S4 = dfC1SB1S4.append({'Type': TypeC1SB1S4,'Value': ValueC1SB1S4,'Input Type': InputTypeC1SB1S4,'Product Ref': ProductRefC1SB1S4,'Brand': BrandC1SB1S4,'Name': NameC1SB1S4,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S4)

    # Dataframes du Optionnal dans le Can Bus 1 pour la Sensor Box 1
    TypeC1SB1Op = 'Moisture Sensor'
    ValueC1SB1Op = 5 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB1Op = Entree420mA
    ProductRefC1SB1Op = ProductRefVMSB
    BrandC1SB1Op = BrandAdafruit
    NameC1SB1Op = 'Henry'
    dfC1SB1Op = dfC1SB1Op.append({'Type': TypeC1SB1Op,'Value': ValueC1SB1Op,'Input Type': InputTypeC1SB1Op,'Product Ref': ProductRefC1SB1Op,'Brand': BrandC1SB1Op,'Name': NameC1SB1Op,'Date': Date}, ignore_index=True)
    #print(dfC1SB1S1)

    # Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB2S1 = 'Moisture Sensor'
    ValueC1SB2S1 = 1 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB2S1 = Entree420mA
    ProductRefC1SB2S1 = ProductRefVMSB
    BrandC1SB2S1 = BrandAdafruit
    NameC1SB2S1 = 'Regis'
    dfC1SB2S1 = dfC1SB1S1.append({'Type': TypeC1SB1S1,'Value': ValueC1SB1S1,'Input Type': InputTypeC1SB1S1,'Product Ref': ProductRefC1SB1S1,'Brand': BrandC1SB1S1,'Name': NameC1SB1S1,'Date': Date}, ignore_index=True)
    #print(dfC1SB2S1)

    # Dataframes du Sensor 2 dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB2S2 = 'Moisture Sensor'
    ValueC1SB2S2 = 2 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB2S2 = Entree420mA
    ProductRefC1SB2S2 = ProductRefVMSB
    BrandC1SB2S2 = BrandAdafruit
    NameC1SB2S2 = 'Francis'
    dfC1SB2S2 = dfC1SB2S2.append({'Type': TypeC1SB2S2,'Value': ValueC1SB2S2,'Input Type': InputTypeC1SB2S2,'Product Ref': ProductRefC1SB2S2,'Brand': BrandC1SB2S2,'Name': NameC1SB2S2,'Date': Date}, ignore_index=True)
    #print(dfC1SB2S2)

    # Dataframes du Sensor 3 dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB2S3 = 'Moisture Sensor'
    ValueC1SB2S3 = 3 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB2S3 = Entree420mA
    ProductRefC1SB2S3 = ProductRefVMSB
    BrandC1SB2S3 = BrandAdafruit
    NameC1SB2S3 = 'Robert'
    dfC1SB2S3 = dfC1SB2S3.append({'Type': TypeC1SB2S3,'Value': ValueC1SB2S3,'Input Type': InputTypeC1SB2S3,'Product Ref': ProductRefC1SB2S3,'Brand': BrandC1SB2S3,'Name': NameC1SB2S3,'Date': Date}, ignore_index=True)
    #print(dfC1SB2S3)

    # Dataframes du Sensor 4 dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB2S4 = 'Moisture Sensor'
    ValueC1SB2S4 = 4 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB2S4 = Entree420mA
    ProductRefC1SB2S4 = ProductRefVMSB
    BrandC1SB2S4 = BrandAdafruit
    NameC1SB2S4 = 'Dupont'
    dfC1SB1S4 = dfC1SB1S4.append({'Type': TypeC1SB2S4,'Value': ValueC1SB2S4,'Input Type': InputTypeC1SB2S4,'Product Ref': ProductRefC1SB2S4,'Brand': BrandC1SB2S4,'Name': NameC1SB2S4,'Date': Date}, ignore_index=True)
    #print(dfC1SB2S4)

    # Dataframes du Optionnal dans le Can Bus 1 pour la Sensor Box 2
    TypeC1SB2Op = 'Moisture Sensor'
    ValueC1SB2Op = 5 # Placer la valeur du return de la fonction get du sensor ici
    InputTypeC1SB2Op = Entree420mA
    ProductRefC1SB2Op = ProductRefVMSB
    BrandC1SB2Op = BrandAdafruit
    NameC1SB2Op = 'Henry'
    dfC1SB2Op = dfC1SB2Op.append({'Type': TypeC1SB2Op,'Value': ValueC1SB2Op,'Input Type': InputTypeC1SB2Op,'Product Ref': ProductRefC1SB2Op,'Brand': BrandC1SB2Op,'Name': NameC1SB2Op,'Date': Date}, ignore_index=True)
    #print(dfC1SB2Op)

    sleep(sleepsecond)
    # Changer le délai entre chaque enregistrement de ligne
    ## Cette partie doit être modifiée en interaction avec le range en début de programme


    if(i >= range):
        FormatDateLog = '%d-%m-%y' + '-' + '%H-%M-%S'
        lognow = time.strftime(FormatDateLog)

        ## Sur le raspberry, créer autant de dossiers que de listes (ex : dfC1SB1S1, dfC1SB1S2, etc)
        # Attention à bien modifier les différents champs pour qu'ils correspondent aux bonnes adresses / listes
        # Ici, des fichiers CSV sont produits dans le dossier correspondant pour stocker les dataframes

        # Fichier dfC1SB1S1
        LogdfC1SB1S1 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S1/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S1)
        df = pd.DataFrame(dfC1SB1S1) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S1) # placer l'adresse du fichier ici
        print(dfC1SB1S1)

        # Fichier dfC1SB1S2
        LogdfC1SB1S2 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S2/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S2)
        df = pd.DataFrame(dfC1SB1S2) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S2) # placer l'adresse du fichier ici
        print(dfC1SB1S2)

        # Fichier dfC1SB1S3
        LogdfC1SB1S3 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S3/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S3)
        df = pd.DataFrame(dfC1SB1S3) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S3) # placer l'adresse du fichier ici
        print(dfC1SB1S3)

        # Fichier dfC1SB1S4
        LogdfC1SB1S4 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1S4/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1S4)
        df = pd.DataFrame(dfC1SB1S4) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1S4) # placer l'adresse du fichier ici
        print(dfC1SB1S4)

        # Fichier dfC1SB1Op
        LogdfC1SB1Op = '/Users/Fuan/Desktop/Solioti/test/dfC1SB1Op/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1Op)
        df = pd.DataFrame(dfC1SB1Op) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB1Op) # placer l'adresse du fichier ici
        print(dfC1SB1Op)

        # -----

        # Fichier dfC1SB2S1
        LogdfC1SB2S1 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB2S1/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB2S1)
        df = pd.DataFrame(dfC1SB2S1) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB2S1) # placer l'adresse du fichier ici
        print(dfC1SB2S1)

        # Fichier dfC1SB2S2
        LogdfC1SB2S2 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB2S2/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB2S2)
        df = pd.DataFrame(dfC1SB2S2) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB2S2) # placer l'adresse du fichier ici
        print(dfC1SB2S2)

        # Fichier dfC1SB2S3
        LogdfC1SB2S3 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB2S3/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB2S3)
        df = pd.DataFrame(dfC1SB2S3) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB2S3) # placer l'adresse du fichier ici
        print(dfC1SB2S3)

        # Fichier dfC1SB2S4
        LogdfC1SB2S4 = '/Users/Fuan/Desktop/Solioti/test/dfC1SB2S4/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB2S4)
        df = pd.DataFrame(dfC1SB2S4) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB2S4) # placer l'adresse du fichier ici
        print(dfC1SB2S4)

        # Fichier dfC1SB2Op
        LogdfC1SB2Op = '/Users/Fuan/Desktop/Solioti/test/dfC1SB2Op/soliotitest'+lognow+'.csv'
        #print(LogdfC1SB1Op)
        df = pd.DataFrame(dfC1SB2Op) # placer la liste des dataframes ici
        df.to_csv(LogdfC1SB2Op) # placer l'adresse du fichier ici
        print(dfC1SB2Op)


        # Supprimer l'ancienne liste et en refaire une nouvelle
        # ----- dfC1SB1S3

        del dfC1SB1S1
        dfC1SB1S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1S2
        dfC1SB1S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1S3
        dfC1SB1S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1S4
        dfC1SB1S4 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB1Op
        dfC1SB1Op = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])

        # ----- dfC1SB2S1

        del dfC1SB2S1
        dfC1SB2S1 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB2S2
        dfC1SB2S2 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB2S3
        dfC1SB2S3 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB2S4
        dfC1SB2S4 = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])
        del dfC1SB2Op
        dfC1SB2Op = pd.DataFrame(columns=['Type','Value','Input Type','Product Ref','Brand','Name','Date'])


        i = 0




# Un nouveau fichier d'historiques est généré dans le dossier visé