import requests
import json

join_key = "&appid=" + "9f9a2aa0b0d0871b54bda3bc56990983"
lat = "50.633333"
lon = "3.066667"
units = "&units=metric"
key = "&appid=9f9a2aa0b0d0871b54bda3bc56990983"
langage = "&lang=fr"
url = "https://api.openweathermap.org/data/2.5/forecast?lat="+lat+"&lon="+lon+key+units+langage
print(url)

response = requests.get(url)
data = json.loads(response.text)

with open("data_file.json", "w") as write_file:

    json.dump(data, write_file)

#list=[]

#for line in data:
#    tempmax,tempmin,