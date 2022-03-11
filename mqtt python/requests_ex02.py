from requests import get

def download(url, file_name):
    with open(file_name, "wb") as file:
        response = get(url)
        file.write(response.content)

if __name__ == '__main__':
    url = "https://www.google.com/url?sa=i&url=https%3A%2F%2Fdullyshin.github.io%2F2018%2F08%2F30%2FHTML-imgLink%2F&psig=AOvVaw2Am95CD8acj-vE8XaArtq9&ust=1647068867834000&source=images&cd=vfe&ved=0CAsQjRxqFwoTCMDKquu_vfYCFQAAAAAdAAAAABAJ"
    download(url, "arduino.png")