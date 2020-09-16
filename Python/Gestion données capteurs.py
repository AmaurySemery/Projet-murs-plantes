import json

x = '{"sensor1":90,"sensor2":89,"sensor3":82,"minimum":82,"maximum":81,"alerte":0,"moyenne":87}'

y = json.loads(x)

print(y["sensor1"])