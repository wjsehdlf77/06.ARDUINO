import requests as req
import json

API_KEY = '4c763c6e7a90879db89ed544e0b30bec'

def get_weather(city = 'Seoul'):
    URL = f'http://api.openweathermap.org/data/2.5/weather?q={city}&APPID={API_KEY}&lang=kr&units=metric'
    print(URL)
    weather = {}
    res = req.get(URL)
    if res.status_code == 200:
        result = res.json()
        weather['main'] = result['weather'][0]['main']
        weather['description'] = result['weather'][0]['description']
        print(result['weather'][0]['description'])
        icon = result['weather'][0]['icon']
        weather['icon'] = f'http://openweathermap.org/img/w/{icon}.png'
        weather['etc'] = result['main']
    else:
        print('error', res.status_code)
    return weather

weather = get_weather()
print(json.dumps(weather, indent=4, ensure_ascii=False))