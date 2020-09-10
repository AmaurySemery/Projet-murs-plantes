import requests
import json
from pyowm import OWM
import config 

config.apikey = '7f9054c4edb12a97316c2da4d6fed6c9'

baseurl='http://api.openweathermap.org/data/2.5/weather?appid='+config.apikey + "&units=metric"

def get_locations(filename):
    filename = '/home/popschool/Documents/GitHub/solioti/API openweathermap/Données/localisations.txt'
    # Same as 01_carto.py
    geocode=[] # geocode = tableau des listes de coord
    lonlat=open(filename, 'r') # ouverture du fichier
    for line in lonlat:
        lon, lat, city=line.split(',') # on découpe la ligne à la ","
        coord={} # coord est une liste vide
        coord["lat"]=lon.strip() #on ajoute un objet "lon"
        coord["lon"]=lat.strip()#on ajoute un objet "lat"
        coord["city"]=city.strip()
        geocode.append(coord) # on ajoute la coord au tableau (à la fin)
        return geocode #on renvoie notre joli tableau

def print_dict(l,titre):
    # Same as 01_carto.py
    print("==== %s ====" % titre)
    for item in l:
        print(item, " = ", l[item])

def get_weather(c):
    # Same as 01_carto.py
    url = baseurl + "&lon="+c["lon"] + "&lat="+c['lat']
    weather=requests.get(url).json()
    print(weather)
    c["temp"]=weather['main']['temp']
    return c

def main():
    #1 - get locations from file :
    locations = get_locations('lonlatonly.txt')

    #2 - add weather for each point :
    for location in locations :
        location = get_weather(location)

    #3 display locaQtions (print) :
    nbligne=0
    for location in locations :
        nbligne=nbligne+1
        sep = "LIGNE %d"  % nbligne
        print_dict(location,sep)
        
    # NOW, we have all the data we need, no more API Request !

if __name__ == "__main__":
    main()