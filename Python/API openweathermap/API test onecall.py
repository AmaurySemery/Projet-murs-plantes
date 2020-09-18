import requests
import json
import pandas as pd
from pprint import pprint

join_key = "&appid=" + "9f9a2aa0b0d0871b54bda3bc56990983"
lat = "50.633333"
lon = "3.066667"
units = "&units=metric"
key = "&appid=9f9a2aa0b0d0871b54bda3bc56990983"
langage = "&lang=fr"
url = "https://api.openweathermap.org/data/2.5/forecast?lat="+lat+"&lon="+lon+key+units+langage
#print(url)

response = requests.get(url)
data = json.loads(response.text)

#pprint(data)

json.dumps(data, indent=4)

with open('/home/popschool/Documents/GitHub/solioti/Python/API openweathermap/Données/data_file.json', 'w') as f:
    f.write(json.dumps(data, indent=4))

with open('data_file.json', 'r') as f:
    datas = json.load(f)
    print(datas)
    
#pprint(datas)