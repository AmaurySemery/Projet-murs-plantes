import requests
import json

City_API_endpoint = "https://api.openweathermap.org/data/2.5/onecall?q="
City = "Lille"
Country = ",fr,"
join_key = "&appid=" + "9f9a2aa0b0d0871b54bda3bc56990983"
units = "&units=metric"

current_city_weather = City_API_endpoint + City + Country + join_key + units
print(current_city_weather)