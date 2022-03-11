import sqlite3
import paho.mqtt.client as mqtt



def on_connect(client, userdata, flag, rc):
    print("Connect with result code" + str(rc))
    if rc == 0:
        client.subscribe("iot/#")
    else:
        print('연결 실패 : ', rc)

def on_message(client, userdata, msg):
    con = sqlite3.connect('iot.db')
    cursor = con.cursor()
    value = float(msg.payload.decode())
    (_, user, place, sensor) = msg.topic.split('/')
    sql = f'''INSERT INTO sensors(user, place, sensor, value)
                values('{user}', '{place}', '{sensor}', '{value}')'''
    cursor.execute(sql)            
    con.commit()


client = mqtt.Client()

client.on_connect = on_connect
client.on_message = on_message
try :
    client.connect("localhost")
    client.loop_start()
    #client.loop.forever()
except Exception as err:
    print('에러 : %s'%err)

from time  import sleep

sleep(60)
