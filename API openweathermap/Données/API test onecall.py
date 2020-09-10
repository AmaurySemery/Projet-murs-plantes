import requests
import json

join_key = "&appid=" + "9f9a2aa0b0d0871b54bda3bc56990983"
latlon = "lat=50.633333&lon=3.066667"
units = "&units=metric"
key = "&appid=9f9a2aa0b0d0871b54bda3bc56990983"
test = "https://api.openweathermap.org/data/2.5/onecall?"+latlon+key+units
print(test)

