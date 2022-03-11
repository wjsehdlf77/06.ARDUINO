import paho.mqtt.client as mqtt

def on_connect(client, userdata, flag, rc):
    print("Connect with result code" + str(rc))
    if rc == 0:
        client.subscribe("iot/#")
    else:
        print('연결 실패 : ', rc)
    
def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    print(f"{msg.topic} {value}")




# client = mqtt.Client()
# try :
#     client.connect("localhost")
#     #4. 메세지 루프 - 이벤트 바랭시 해당 콜백 함수 호출됨
#     client.loop()       #새로운 스레드 실행 --> demon스레드 -> main 스레드 종료시에 강제 종료됨
# except Exception as err:
#     print('에러 : %s'%err)

# 1. MQTT 클라이언트 객체 인스턴스화
client = mqtt.Client()
# 2. 관련 이벤트에 대한 콜백 함수 등록
client.on_connect = on_connect
client.on_message = on_message
try :
 # 3. 브로커 연결
    client.connect("localhost")
 # 4. 메시지 루프 - 이벤트 발생시 해당 콜백 함수 호출됨
    client.loop_forever()
except Exception as err:
    print('에러 : %s'%err)