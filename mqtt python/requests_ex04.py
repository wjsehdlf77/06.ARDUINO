import requests

url = "http://127.0.0.1:8000/api/greet/?name=hong&age=30"

response = requests.get(url)

print(response.json())