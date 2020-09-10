import requests
import json
from pyowm import OWM
import config 
import smopy 
import matplotlib.pyplot as plt 

owm = OWM('your-API-key')

api_key = "7f9054c4edb12a97316c2da4d6fed6c9"
lat = "50.633333"
lon = "3.066667"
url = "https://api.openweathermap.org/data/2.5/onecall?lat=%s&lon=%s&appid=%s&units=metric" % (lat, lon, api_key)

response = requests.get(url)
data = json.loads(response.text)
print(data)

baseurl='http://api.openweathermap.org/data/2.5/weather?appid='+config.apikey + "&units=metric"