import pandas as pd
import json

#f=open(r"C:\Divers\Python codes\Projet-top-sites-AoG\Dossiers-CSV\classement_SSAoG_CSV.csv")

# Dataframes de la Gateway
dGW = {'EV1': [1,2], 'EV2': [1,2], 'EV3': [4,2], 'EV4': [3, 4],'EV5': [1, 2], 'EV6': [3, 4],'EV7': [1, 2], 'EV8': [3, 4],'EV9': [1, 2]}
dfGW = pd.DataFrame(data=dGW)
dfGW

# Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 1
dC1SB1S1 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB1S1 = pd.DataFrame(data=dC1SB1S1)
dfC1SB1S1

# Dataframes du Sensor 2 dans le Can Bus 1 pour la Sensor Box 1
dC1SB1S2 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB1S2 = pd.DataFrame(data=dC1SB1S2)
dfC1SB1S2

# Dataframes du Sensor 3 dans le Can Bus 1 pour la Sensor Box 1
dC1SB1S3 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB1S3 = pd.DataFrame(data=dC1SB1S3)
dfC1SB1S3

# Dataframes du Sensor 4 dans le Can Bus 1 pour la Sensor Box 1
dC1SB1S4 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB1S4 = pd.DataFrame(data=dC1SB1S4)
dfC1SB1S4

# Dataframes du Optionnal dans le Can Bus 1 pour la Sensor Box 1
dC1SB1Op = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': ["Henry", "Régis"]}
dfC1SB1Op = pd.DataFrame(data=dC1SB1Op)
dfC1SB1Op

# Dataframes de la Sensor Box 1 dans le Can Bus 1
dC1SB1 = {'Name': [1,2], 'Power supplies': [1,2], 'Relai EV state': [4,2], 'Relai terminaison': [3, 4],'Relai alim': [1, 2]}

# -----------

# Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 2
dC1SB2S1 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB2S1 = pd.DataFrame(data=dC1SB2S1)
dfC1SB2S1

# Dataframes du Sensor 2 dans le Can Bus 1 pour la Sensor Box 2
dC1SB2S2 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB2S2 = pd.DataFrame(data=dC1SB2S2)
dfC1SB2S2

# Dataframes du Sensor 3 dans le Can Bus 1 pour la Sensor Box 2
dC1SB2S3 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB2S3 = pd.DataFrame(data=dC1SB2S3)
dfC1SB2S3

# Dataframes du Sensor 4 dans le Can Bus 1 pour la Sensor Box 2
dC1SB2S4 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB2S4 = pd.DataFrame(data=dC1SB2S4)
dfC1SB2S4

# Dataframes du Optionnal dans le Can Bus 1 pour la Sensor Box 2
dC1SB2Op = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': ["Henry", "Régis"]}
dfC1SB2Op = pd.DataFrame(data=dC1SB2Op)
dfC1SB2Op

# Dataframes de la Sensor Box 2 dans le Can Bus 1
dC1SB2 = {'Name': [1], 'Power supplies': [2], 'Relai EV state': [3], 'Relai terminaison': [4],'Relai alim': [5]}

# -----------

# Dataframes du Sensor 1 dans le Can Bus 1 pour la Sensor Box 3
dC1SB3S1 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB3S1 = pd.DataFrame(data=dC1SB3S1)
dfC1SB3S1

# Dataframes du Sensor 2 dans le Can Bus 1 pour la Sensor Box 3
dC1SB3S2 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB3S2 = pd.DataFrame(data=dC1SB3S2)
dfC1SB3S2

# Dataframes du Sensor 3 dans le Can Bus 1 pour la Sensor Box 3
dC1SB3S3 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB3S3 = pd.DataFrame(data=dC1SB3S3)
dfC1SB3S3

# Dataframes du Sensor 4 dans le Can Bus 1 pour la Sensor Box 3
dC1SB3S4 = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': [3, 4]}
dfC1SB3S4 = pd.DataFrame(data=dC1SB3S4)
dfC1SB3S4

# Dataframes du Optionnal dans le Can Bus 1 pour la Sensor Box 3
dC1SB3Op = {'Type': [1,2], 'Value': [1,2], 'Input Type': [4,2], 'Product Ref': [3, 4],'Brand': [1, 2], 'Name': ["Henry", "Régis"]}
dfC1SB3Op = pd.DataFrame(data=dC1SB3Op)
dfC1SB3Op

# Dataframes de la Sensor Box 3 dans le Can Bus 1
dC1SB3 = {'Name': [], 'Power supplies': [], 'Relai EV state': [], 'Relai terminaison': [],'Relai alim': []}