import requests

url = "https://api.openweathermap.org/data/2.5/weather?q=seoul&APPID=2257abaccc71e2915d5f5aab369225e0&lang=kr"

response = requests.get(url)

print("status code : ", response.status_code)

print(response.text)

